#CSC 134
#Turtle Graphics
#Justin Tran

import turtle, time
import modules.shapes as shapes

t = turtle.Turtle()
screen = turtle.Screen()
screen.tracer(0)
t.penup()

x = 0
y = 0
vx = 5
vy = 5
r = 50
r_min = 10
r_max = 100
growing = False

def update():
    t.clear()
    global x, y, vx, vy, r, growing
    screensize = (screen.window_width(), screen.window_height())
    
    
    
    if (x+r > screensize[0] / 2):
        x = screensize[0] / 2 - r
        vx *= -1
        
    if (x-r < -screensize[0] / 2):
        x = -screensize[0] / 2 + r
        vx *= -1
        
    if (y+r > screensize[1] / 2):
        y = screensize[1] / 2 - r
        vy *= -1
        
    if (y-r < -screensize[1] / 2):
        y = -screensize[1] / 2 + r
        vy *= -1
    
    t.goto(x, y)
    shapes.circle(t, r, "red")
    x += vx
    y += vy
    
    if r > r_max:
        growing = False
    elif r < r_min:
        growing = True
    
    if growing:
        r += 1
    else:
        r -= 1
    
    screen.update()
    screen.ontimer(update, 15)

update()

screen.exitonclick()