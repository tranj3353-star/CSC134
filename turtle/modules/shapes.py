import turtle

def circle(t: turtle.Turtle, radius: float, color: str):
    t.fillcolor(color)
    t.begin_fill()
    original_y = t.ycor()
    t.penup()
    t.setheading(0)
    t.goto(t.xcor(), t.ycor() - radius)
    t.pendown()
    t.circle(radius)
    t.penup()
    t.goto(t.xcor(), original_y)
    t.end_fill()
