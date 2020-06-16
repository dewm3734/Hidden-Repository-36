#include <cmath>
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

struct white{
	int index;
	int array; // 1 for left side, 2 for right side, 3 for top side
};
struct wArray{
	white left;
	white right;
	white top;
	white bottom;
};
struct angles{
	double LBAngle;
	double LTAngle;
	double RBAngle;
	double RTAngle;
};
wArray find_white_line(){
	int row1 = cameraView.height/20; int row2 = cameraView.height-row1;
	int col1 = cameraView.width/20; int col2 = cameraView.width-col1;
	white left={-1,1}; white right={-1,2}; white top={-1,3}; white bottom={-1,4};
	for(int i = 0; i < row2-row1; i++){
		if(isWhite(get_pixel(cameraView, row1+i, col1, 3)) == 1){
			left.index = i;
			left.array = 1;
			break;
		}else if(isWhite(get_pixel(cameraView, row1+i, col2, 3)) == 1){
			right.index = i;
			right.array = 2;
			break;
		}
	}
	for(int j = 0; j < col2-col1; j++){
		if(isWhite(get_pixel(cameraView, row1, col1+j, 3)) == 1){
			top.index = j;
			top.array = 3;
			break;
		}else if(isWhite(get_pixel(cameraView, row2, col1+j, 3)) == 1){
			bottom.index = j;
			bottom.array = 4;
			break;
		}
	}
	wArray _white = {left, right, top, bottom};
	return _white;
}
angles angle(wArray _wArray){
	angles _angles;
	if(_wArray.left.index != -1 && _wArray.bottom.index != -1){
		double x = (cameraView.height - 10) - _wArray.left.index;
		double y = _wArray.bottom.index;
		double z = sqrt(x*x + y*y);
		double angle = asin(x/z);
		_angles.LBAngle = angle;// 0 = left-bottom
	}else{
		_angles.LBAngle = 0;
	}
	if(_wArray.left.index != -1 && _wArray.top.index != -1){
		double x = _wArray.left.index;
		double y = _wArray.top.index;
		double z = sqrt(x*x + y*y);
		double angle = asin(y/z);
		_angles.LTAngle = angle;// 1 = left-top
	}else{
		_angles.LTAngle = 0;
	}
	if(_wArray.right.index != -1 && _wArray.bottom.index != -1){
		double x = (cameraView.height - 10) - _wArray.right.index;
		double y = (cameraView.width - 10) - _wArray.bottom.index;
		double z = sqrt(x*x + y*y);
		double angle = asin(x/z);
		_angles.RBAngle = angle;// 2 = right-bottom
	}else{
		_angles.RBAngle = 0;
	}
	if(_wArray.right.index != -1 && _wArray.top.index != -1){
		double x = _wArray.right.index;
		double y = (cameraView.width - 10) - _wArray.top.index;
		double z = sqrt(x*x + y*y);
		double angle = asin(y/z);
		_angles.RTAngle = angle;// 3 = right-top
	}else{
		_angles.RTAngle = 0;
	}
	return _angles;
}
bool isWhiteCentre()
{
	bool isCentre = false;
	for(int i = 0; i < cameraView.width; i++)
	{
		if(isWhite(get_pixel(cameraView, cameraView.height/2, i, 3)))
		{
			isCentre = true;
		}
	}
	return isCentre;
}

