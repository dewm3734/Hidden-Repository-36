#include "robot.hpp"
#include "whiteness.hpp"
double calculateOffset(){
	/// Returns a double between -1 and 1
	/// Representing the distance the centre
	/// Of the white line is away from the robot
	/// If the number is positive the line is to the left
	/// If the number is negitive the line is to the right
	
    int offset = 0;//distances away
    int amount = 0;//for finding average
	int mid_col = cameraView.width/2;//center of fov
	int mid_row = cameraView.height/2;
	int total_cols = cameraView.width;
	for(int col=0; col<cameraView.height;col++){
	  int whiteness = get_pixel(cameraView,mid_row,col,3);
	  if(whiteness>250){//if it is line
		amount++;
		offset += mid_col-col;
	  }
	}
	std::cout<<(double)offset/amount/total_cols*2<<std::endl;
	return (double)offset/amount/total_cols*2;// divide by half the camera view to normalise.
}
double * calculateWheelSpeeds(double offset,double speed){
	double lv=0;
	double rv=0;
	lv+=-offset*speed+speed;
	rv+=offset*speed+speed;

    double speeds[2] = { lv,rv }; 
	return speeds;
	
}
int main(){
	if (initClientRobot() !=0){
		std::cout<<" Error initializing robot"<<std::endl;
	}
    double vLeft = 5.0;
    double vRight = 5.0;
    double speed = 50.0;
    double offset = 0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    while(1){
	  takePicture();
	  if(isWhiteCentre())
	  {
		  offset = calculateOffset();
	  }
	  else
	  {
		  wArray _wArray = find_white_line();
		  
	  }
	  double * speeds = calculateWheelSpeeds(offset, speed);
	  vLeft = speeds[0];
	  vRight = speeds[1];
      setMotors(vLeft,vRight);   
      std::cout<<" Offset="<<offset<<std::endl;
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(1000);
  } //while

} // main

