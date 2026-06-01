#! /usr/bin/python3
# 3 TURTLES parallel
from turtle import *
v=30;   ang=115; hop=150
a=Turtle();  b=Turtle();  c=Turtle();
##
a.color("red");     a.pencolor("red")
b.color("orange");  b.pencolor("yellow")
c.color("blue");    c.pencolor("blue")
a.speed(3);  b.speed(3*v); c.speed(2*v);
for d in (a,b,c):
  d.shape("circle")
  d.right(ang)
  d.penup()
  d.forward(hop); hop=hop+10
  d.pendown()
  d.left(ang)
##
for k in range(1,100):
  for d in (a,b,c):
    d.forward(120-k/3)
    d.speed(2+k)
    d.left(44)

a.penup(); a.left(45); a.forward(200)
b.penup(); b.left(55); b.forward(190)
c.penup(); c.left(65); c.forward(180)

import time
time.sleep(10)

