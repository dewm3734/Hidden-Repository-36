#include "robot.hpp"
// requires get_pixel to be passed as an argument, then returns 0 if the
// luminosity is < 250 or  1 if >= 250
int isWhite(int pixel)
{
	if(pixel >= 250)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
// Implement the code below into into the robot.cpp to determine whether
// a row contains any white pixels
//int whiteArray[100];
//for(int k = 0; k < 100; k++)
//{ 
     //whiteArray[k] = isWhite(get_pixel(cameraView, 50, k, 3);
//}

