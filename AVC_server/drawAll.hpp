int drawAll(){
    globalWindow.clear();
    cameraWindow.clear();
    drawMaze(); // draw without robot
    getCameraView(); // get camera view
    drawRobot();
    globalWindow.display();
    cameraWindow.display();    
    return 1;
}
