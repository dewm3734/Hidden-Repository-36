
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

struct white
{
	int index;
	int array; // 1 for left side, 2 for right side, 3 for top side
};


white find_white_line(int row1, int row2, int col1, int col2)
{
	int index;
	int array;
	int row_array[(row2 - row1)];
	int col_array[(col1 - col2)];
	if(col1 == col2)
	{
		for(int i = 0; i < (row2 - row1); i++)
		{
			row_array[i] = isWhite(get_pixel(cameraView, row1 + i, col1, 3));
			if(col1 == (cameraView.width / 20))
			{
				index = row_array[i];
				array = 1;
			}
			else
			{
				index = row_array[i];
				array = 2;
			}
		}
	}
	else
	{
		for(int i = 0; i < (col2 - col1); i++)
		{
			col_array[i] = isWhite(get_pixel(cameraView, row1, col1 + i, 3));
			index = col_array[i];
			array = 3;
		}
	}
	white _white = {index, array};
	return _white;
}

bool isWhiteCentre()
{
	bool isCentre = false
	for(int i = 0; i < cameraView.width; i++)
	{
		if(isWhite(get_pixel(cameraView, cameraView.height/2, i, 3))
		{
			isCentre = true;
		}
	}
	return isCentre;
}

