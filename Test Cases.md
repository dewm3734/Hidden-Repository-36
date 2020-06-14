# TEST CASE

CORE Test Cases</br>
How well does the robot follow the white line? Is it constantly correcting itself?
|Scenario|Expected Outcome|Actual Outcome|
|:---------------|:---------------|:-------------|
|Robot travelling on horizontal white lines|Robot must successfully travel on the maze’s horizontal white lines.|The robot only travels in a straight line. So it follows the first horizontal white line, but once it passes the line it keeps travelling in straight ahead until it runs into an obstacle and does not turn.|
|Robot travelling around sharp corners.|When making turns the robot should stay on the white line, so it is easier to find the next white line.|Although the robot turns when it approaches corners, it does not turn exactly on the white lines.|
|Robot after passing a sharp corner.|Robot must find the next white line and follow it.|Once the robot passes the corner, it would correct itself and move back onto the white line.|
|Robot travelling around curved corners|The robot should smoothly make it way around corners, staying on the white line.|    |
|Robot travelling on diagonal white lines|Robot must successfully travel on the maze’s diagonal white lines.|  |
|Robot travelling on vertical lines|Robot must successfully travel on the maze’s vertical white lines.|  |

## Possible test case format.
|**Scenario 1 Description**|Robot must successfully travel on the maze’s horizontal white lines.|
|---|---|
|**Preconditions**|N/A|
|**Assumption**|User has the text editor Geany installed on their computer and the necessary compilers installed and working.|
|**Test Description**|write purpose of test|
|**Testing Steps**|1. Open Geany.<br> 2. Open sever3.cpp file.<br> 3. Open a new Geany instance.<br> 4. Open robot.cpp file.<br> 5. Change variables.<br> 6. Execute server3.cpp.<br> 7. Execute robot.cpp.<br> 8. Observe robot movement.<br> 9. If the robot successfully completes the expected result, record in table with ✔️. If robot robot does not completed expected result record in table with ❌.<br> 10. Repeat steps 5 to 9 until variables are all tested.|
|**Expected Result**|The robot should move following the horizontal white line. The robot should not be constantly correcting itself especially when just travelling on a straight line.|
|**Actual Result**|The robot only travels in a straight line. So it follows the first horizontal white line, but once it passes the line it keeps travelling in straight ahead until it runs into an obstacle and does not turn.|
