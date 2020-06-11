class Intercection{
	public:bool left=false;
	public:bool right=false;
	public:bool top=false;
	public:bool intercection = false;
	
	public:void get_sides(){
		this->left=false;
		this->right=false;
		this->top=false;
		this->intercection=false;

		for(int row=0;row<cameraView.height;row++){
			if(get_pixel(cameraView,row,0,3)>250){
				this->left=true;
			}
			if(get_pixel(cameraView,row,cameraView.width,3)>250){	
				this->right=true;
			}
		}
		for(int col=0;col<cameraView.width;col++){
			if(get_pixel(cameraView,0,col,3)>250){
				this->top=true;
			}
		}
		std::cout<<"Left:"<<this->left<<std::endl;
		std::cout<<"Right:"<<this->right<<std::endl;
		std::cout<<"Top:"<<this->top<<std::endl;
		
		this->intercection = (this->left&&this->right)||(this->left&&this->top)||(this->top&&this->right);
	}
};
