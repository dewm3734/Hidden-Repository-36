#include "robot.hpp"
#include "Speeds.hpp"
#include "whiteness.hpp"
#define _USE_MATH_DEFINES
 
#include <cmath>

double calculateOffset(double speed){
	/// Returns a double between -1 and 1
	/// Representing the distance the centre
	/// Of the white line is away from the robot
	/// If the number is positive the line is to the left
	/// If the number is negitive the line is to the right
	for(int row=0; row<cameraView.height;row++)
	{//turn left
		if(get_pixel(cameraView,row,0,3)>250){
			std::cout<<"left"<<std::endl;
			return row!=0?atan(cameraView.width/2.0/row):1;
		}
	}
	for(int col=0; col<cameraView.width;col++){//adjust forward
		if(get_pixel(cameraView,0,col,3)>250){
			std::cout<<"top"<<std::endl;
			return atan((cameraView.width/2.0-col)/cameraView.height);
		}
	}
	for(int row=0; row<cameraView.height;row++){//turn right
		if(get_pixel(cameraView,row,cameraView.width-1,3)>250){
			std::cout<<"right"<<std::endl;
			return row!=0?-atan(cameraView.width/2.0/row):1;
		}
	}
	for(int col=0; col<cameraView.width;col++){//adjust forward
		if(get_pixel(cameraView,cameraView.height - 1,col,3)>250){
			std::cout<<"bot"<<std::endl;
			return cameraView.width/2.0-col>0?1:0;
		}
	}
	

	return speed * (M_PI_2)/4;
}
Speeds calculateWheelSpeeds(double speed){
	Speeds speeds;
	double angle = calculateOffset(speed);
	
	std::cout<<" angle="<<angle<<std::endl;
	speeds.vLeft=speed-(angle)*675/speed/2/(M_PI_2);
	speeds.vRight=speed+(angle)*675/speed/2/(M_PI_2);
	speeds.vRight=speed+(angle)*675/speed/2/(M_PI_2);


	return speeds;
}
Speeds calculateWheelSpeeds(double speed, double angle){
	Speeds speeds;
	
	std::cout<<" angle="<<angle<<std::endl;
	speeds.vLeft=speed-(angle)*675/speed/2/(M_PI_2);
	speeds.vRight=speed+(angle)*675/speed/2/(M_PI_2);
	speeds.vRight=speed+(angle)*675/speed/2/(M_PI_2);


	return speeds;
}
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 5.0;
    double vRight = 5.0;
    double speed = 20.0;
    Speeds speeds;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    while(1){
	  takePicture();
	  if(isWhiteCentre() == true){
		  speeds = calculateWheelSpeeds(speed);
	  }else{
		  wArray _wArray = find_white_line();
		  angles _angles = angle(_wArray);
		  if(_angles.LBAngle != 0){
			  double angle = _angles.LBAngle;
			  speeds = calculateWheelSpeeds(speed, angle);
		  }else if(_angles.LTAngle != 0){
			  double angle = _angles.LTAngle;
			  speeds = calculateWheelSpeeds(speed, angle);
		  }else if(_angles.RBAngle != 0){
			  double angle = _angles.RBAngle;
			  speeds = calculateWheelSpeeds(speed, angle);
		  }else if(_angles.RTAngle != 0){
			  double angle = _angles.RTAngle;
			  speeds = calculateWheelSpeeds(speed, angle);
		  }
	  }
	  vLeft = speeds.vLeft;
	  vRight = speeds.vRight;
      setMotors(vLeft,vRight);   
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(100000);
  } //while

} // main

