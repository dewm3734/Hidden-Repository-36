# TEST CASE

CORE Test Cases</br>
How well does the robot follow the white line? Is it constantly correcting itself?
|Scenario|Expected Outcome|Actual Outcome|
|:---------------|:---------------|:-------------|
|Robot travelling on horizontal white lines|Robot must successfully travel on the maze’s horizontal white lines.|The robot only travels in a straight line. So it follows the first horizontal white line, but once it passes the line it keeps travelling in straight ahead until it runs into an obstacle and does not turn.|
|Robot travelling around sharp corners.|When making turns the robot should stay on the white line, so it is easier to find the next white line.|Although the robot turns when it approaches corners, it does not turn exactly on the white lines.|
|Robot after passing a sharp corner.|Robot must find the next white line and follow it.|Once the robot passes the corner, it would correct itself and move back onto the white line.|
|Robot travelling around curved corners|The robot should smoothly make it way around corners, staying on the white line.|    |
|Robot travelling on diagonal white lines|
Robot must successfully travel on the maze’s diagonal white lines.|  |
|Robot travelling on vertical lines|Robot must successfully travel on the maze’s vertical white lines.|  |
