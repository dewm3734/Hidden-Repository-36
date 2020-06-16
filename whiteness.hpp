
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


wArray find_white_line(){
	int row1 = cameraView.height/20; int row2 = cameraView.height-row1;
	int col1 = cameraView.width/20; int col2 = cameraView.width-col1;
	white left={0,0}; white right={0,0}; white top={0,0}; white bottom={0,0};
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
double angle(wArray _wArray){
	
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

