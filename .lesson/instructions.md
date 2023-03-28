# Instructions  

  ** StopWatch class **


Often, we need to determine how long it takes/took to perform a certain action(s). 

Write a class, StopWatch which will provide an easy interface to the computer's timing facilities. 

When you first create a Timerobject, it should be set to a 'stop' state. 
When the programmer wants to time something, they call the start() method before the action executes and  call the stop() method after the event finishes. 

The elapsed() method will return (in whole seconds) how long the action took.

This simple operation may not suit all programmers' needs. To allow more general usage, we'll also the programmer to start the timer at the object's declaration. Also, a programmer can get the elapsed time whether the timer is still running or not. Finally, we'll provide an toString() method so the programmer can directly print the currently elapsed time without having to retrieve it separately.

In addition, allow the programmer to subtract() and add() two StopWatch objects to receive a StopWatch object that is the difference/sum of the original two Timers' currently elapsed times. (The resulting object should not be running.)

Test our program adequately. Make sure that things work correctly if the programmer tries to get/print the elapsed time of a StopWatch which has never been started. Make sure nothing goes wrong if the programmer tries to stop a Timerobject that isn't currently running.

We won't need a reset() method since the programmer can simply call start() again to start over

Don't call  the functions localtime and asctime from the standard C library ctime here. They do nothing useful here! (And asctime leaves a mess behind you would probably forget to clean up even if you knew how!)
Instead use the functions in the <time> library.

Finally, place your StopWatch in a library and write a test application that makes sure it is working properly. The easiest way would be to print the current system time, start the Timer, and ask the tester to wait for a while before hitting Enter. Then, when they do hit Enter, stop the StopWatch and print both the Timer's elapsed seconds and the system time. 

The tester can check the elapsed time for themselves. Place this interaction in a yes/no loop so the tester can repeat the testing easily by simply saying 'yes' or 'no' to your question of whether or not to continue. (Your loop should allow the tester to enter either y/n or the full words yes/no. But don't worry about them typing 'yellow' or 'Naugahyde' or whatever.)
