
Cycling through graphics displays - waiting for ENTER
or - ENTER-key driven animation

Sometimes we need a simple means to show a sequence of situations.
A typical simple approach is
      draw / show / print case1 ; wait for ENTER (or wait for a click)
      draw / show / print case2 ; wait for ENTER 
      etc

wait for ENTER is realised by getline(cin,lin);  (with string lin; C++ string)

Here we made a toy doing this in terminal
case1            X    case3              case2 X
              X             X   X   X              X
           X                                           X
as you hit ENTER repeatedly - a sort of rotation appears
Just a toy    root back_forth.C     hit ENTER forever
back_forth.C    (it is made 5 lines instead of 3)
================================================================
But if we want to show for example many functions in a TCanvas
show function 1  wait for ENTER  show function 2    etc
We Draw three functions and wait for ENTER
back_forthGRAPH.C      (does not work, see why, and the working version)
is simply made from  back_forth.C replacing the prints by 3 functions

Only one problem - it does not work. Line by line everything works
The problem is that all the non-graphic processing must be done before
any graphics.  There is a solution: add this call: 
                                 gSystem->ProcessEvents();
But there is more - the updating of the graphics is not guaranteed.
Thus we need to add  Displ->Modified(); Displ->Update(); before calling gSystem

back_forthGRAPHworks.C    is behaving as expected
================================================================

two_focus.C         focus on graphics or on the terminal

We can use ENTER on the terminal, naturally
But in ROOT also the graphics can wait for events, ENTER is one of them
I have prepared an otherwise meaningless demonstration of a moving star
gedit two_focus.C   &             and
root  two_focus.C                 repeats the 5 waits forever - stop by CTRL-C

The present version is heavily extended to assure visible expected "jumps"
The random is set with really random seed; printed "waiting info" is added

================================================================


