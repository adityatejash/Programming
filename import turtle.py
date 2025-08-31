import turtle

t = turtle.Turtle()
size = 800
y_axis = 50

# rainbow
color = ["red", "orange", "yellow", "green", "blue", "indigo", "violet"]
x=50
t.speed(20)
for i in range(7):
    t.showturtle()
    t.fillcolor(color[i])
    t.begin_fill()
    t.circle(size-100)
    t.end_fill()
    t.penup()
    t.goto(0,x)
    t.pendown()
    x += 50
    t.hideturtle()
turtle.done()