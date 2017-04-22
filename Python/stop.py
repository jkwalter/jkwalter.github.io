import turtle

turtle.color("blue")

while True:
	turtle.forward(200)
	turtle.left(170)
	if abs(turtle.position()) < 1:
		break

turtle.done()
