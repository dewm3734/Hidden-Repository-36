#include "robot.hpp"
double calculateOffset(){
	/// Returns a double between -1 and 1
	/// Representing the distance the centre
	/// Of the white line is away from the robot
	/// If the number is positive the line is to the left
	/// If the number is negitive the line is to the right
	
    int offset = 0;//distances away
    int amount = 0;//for finding average
	int row = cameraView.height/2;//center of fov
	int total_cols = cameraView.width;
	for(int col=0; col<total_cols;col++){
	  int whiteness = get_pixel(cameraView,row,col,3);
	  if(whiteness>250){//if it isline
		amount++;
		offset += total_cols/2-col;
	  }
	}
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
    double speed = 80.0;
    takePicture();
    SavePPMFile("i0.ppm",cameraView);
    while(1){
	  takePicture();
	  double offset = calculateOffset();
	  double * speeds = calculateWheelSpeeds(offset, speed);
	  vLeft = speeds[0];
	  vRight = speeds[1];
      setMotors(vLeft,vRight);   
      std::cout<<" Offset="<<offset<<std::endl;
      std::cout<<" vLeft="<<vLeft<<"  vRight="<<vRight<<std::endl;
       usleep(10000);
  } //while

} // main

