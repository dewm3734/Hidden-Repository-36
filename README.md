# Project-3-Team-36
## AVC Plan
ENGR101 Project 3 - "The purpose of this project is to write a software which guides a robot through a maze."  

### Communication  
We have decided as a group to meet on Friday between 1-3 pm to work on the code for our project. We have made a group chat on Facebook messenger which will be our main form of communication when we have made progress, and want to report back to the group about. If we believe we need to meet as a group twice a week via zoom, Tuesday between 1-3 pm is the next alternative option. 

### Team members and contact info

- #### Jasmine Dong - jasmineelladong@gmail.com  
Project Manager - organising team meetings, reporting regularly on progress

- #### Josh Keegan - josh.keegan3@gmail.com  
Software Architect - writing core code and extending functionality

- #### Michael Dewson - mikedwn123@gmail.com  
Software Architect - writing core code and extending functionality

- #### Deepika Raheja - raheja.deepika87@gmail.com  
Software writing, testing, and documentation - debugging software and committing to
git, writing test cases and documenting performance against milestones

- #### Janelle Lim-Ranola - janelle.limranola@gmail.com  
Software writing, testing, and documentation - debugging software and committing to
git, writing test cases and documenting performance against milestones

### Deadlines to note

| Hand-ins | Date | Course mark |
|----------|------|-------------|
| Plan | Thurs 4th May | |
| Code due | Fri 19th May | 5%|
| Team Log | Wed 24th May | 5% |
| Individual Log | Wed 24th May  | 5% |
| Group Log Report | Wed 24th May  | 5% |

### Interferances to note
| Conflicts | Due Date | 
|----------|------|
| ENGR101 Tutorial 4 | Mon 1st May |
| ENGR 121 Assignment 6 | Wed 3rd May |
| COMP Assignment 7/6+7 | Thurs 4th May |
| ENGR 121 Lab 3 | Fri 5th May  |
| CYBR 171 Assignment 2 | Mon 8th May  |
| ENGR 121 Assignment 7| Wed 10th May  |
| Comp Assignment 8 | Thrus 11th May  |
| CYBR ENGR Test 2 | Wed 17th May  |
| Comp Assignment 9/8+9 | Mon 18th May  |

Note the large gap between the 11th and the 17th. This is where we should be getting a lot of work done and can be treated as both a catch up and a get ahead period for the project. Challenge code may be written in this time. If this happens challenge test case creation will have to be accerated and more minds put towards it.

After report submission is Assignment 10 for Comp and Cybr Test 2. Because of this we may want to complete the parts sooner than scheduled. 

### Timeline
Note this is a team timeline and the Invidvidual Report will have to be completed in your own time. This time is provided while finalising the Group report and logs between the Friday 19th and Wednesday 24th of May however should be worked on throughout by the individual. 

| Date | Agenda | What we want to accomplish |
|----------|------|-------------|
| ENGR101 lectures | | Jasmine is in charge of asking any questions on behalf of the group |
| Tues 26th April | GitHub | Josh set up project repository |
| Sun 31st April | Group met via zoom | Get to know each other |
| Tues 2nd May | Plan discussion | Install SFML on our devices so we are ready to start |
| Wed 3rd May | ENGR101 Lecture | Jasmine asks any questions with Arthur |
| Fri 5th May | Do core code | Writing core code and write Core test cases |
| Sun 7th May | Check on core code | Gives time to test and debug code for next meeting. Finished Core test cases ready for code completion|
| Tues 9th May | Completion discussion | Finalise core code and start completion code and write Completion test cases |
| Fri 12th May | Check on completion code | Gives time to test and debug code for next meeting. Finished Completion test cases ready for challenge code |
| Sun 14th May | Challenge discussion | Finalise completion code and start challenge code and writing Challenge test cases |
| Tues 16th May | Update on challenge | Should be near the end of the coding progress. Finished Challenge test cases|
| Thur 18th May | Double check code | Make sure code works and is ready for hand-in the following day |
| Fri 19th May | CODE DUE | Make sure code is submitted |
| Fri 19th May | Report discussion | Discuss report with group and recap logs (team and individual) |
| Tues 23rd May | Finalise report | Check that report is done and logs are finished |
| Wed 24th May | REPORT DUE | Make sure all report and logs are submitted - PROJECT DONE! |

## Project Log - Jasmine
### Sunday 31st April - Video call via zoom
| Present | Absent |
|----------|------|
| Jasmine | Deepika |
| Joshua | |
| Michael | |
| Janelle | |

Today we all met each other for the first time via zoom. As this project is now online, we did find it difficult to find a time where we were all available to talk, however, we did the best we could. All of us could make it apart from Deepika who was unfortunately at work, however, we created a facebook messenger group chat where we were able to keep her up to date. We started by getting to know each other and then we discussed the project and what our goal was. As a group, we wanted to try to get this project done as fast as we could due to the conflicting assignments. Our first obstacle was installing the SFML library which came with many difficulties. We decided that it was best to try to install it ourselves and communicate through Facebook messenger if we encountered any problems. Josh and Micheal are on OS X and therefore, their installation process was slightly different from the rest of us who are on windows. So it was our job to try to sort out all of the issues that were encountered by either attending labs or working through it together on facebook messenger.

### Tuesday 2nd May - Updates on fb messenger
We have been staying in contact with each other on FB messenger and sending photos of the issues we have encountered with installing SFML on our computers. I believe we are nearly there, however, there are still a few problems which hopefully the tutors in the labs can fix for us. Josh has made a start and brainstormed a few ideas of how we can approach the core code which we will discuss on Friday when we meet via zoom. By the end of Friday, we are hoping to have the SFML library successfully installed and working on everyone's computers so we are able to make a good start on core and finish that as soon as we can so we can move onto completion. Michael will help Josh with writing the code and then Deepika and Janelle will be in charge of debugging the code and writing test cases so we can keep track of the changes we have made, and hopefully enable is to work through the rest of the code efficiently. I (Jasmine) will be reporting regularly on our progress throughout this project, and I will also be there to help write and debug code. 

### Friday 5th May - Zoom call
Today we started to brainstorm ideas on how we want to approach core. We looked through Arthur's slides and discussed ideas of what we wanted to do. We decided to go for the approach by asking ourselves the question of how far from the centre of the image the white line is? This is simply done by detecting the white pixel in the camera and then adjusting the robot by calculating the offset, speed, and even a reverse if the robot goes off track and we want it to find the white line again. We have a number of functions that we are going to implement and we have an idea of the kind of test cases that we will encounter. In this meeting, we also discovered that we still had a few issues with installing the SFML library on a few of our laptops which we need to sort out ASAP so we can move ahead with writing our code. We were deciding between whether we write a function each to try distribute the roles evenly and then try join it together, however, because some functions connect with each other, we believe that it may be best if two of our members write the code, and then the rest of us are in charge of debugging and experimenting with our test cases to get the best outcome we want. 

### Monday 8th June - Gitcomit Test

## Test cases - Core

### Tuesday 9th June - Test
