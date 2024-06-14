import turtle

# 거북이 객체 생성
t = turtle.Turtle()

# 정사각형 그리기
side_length = 50  # 한 변의 길이 (단위: 픽셀)
t.penup()
t.goto(-side_length / 2, -side_length / 2)  # 정사각형의 중심으로 이동
t.pendown()
t.color("red")
t.begin_fill()
for _ in range(4):
    t.forward(side_length)
    t.left(90)
t.end_fill()

# 테두리 그리기
border_width = 3  # 테두리 두께 (단위: 픽셀)
t.penup()
t.goto(-side_length / 2 - border_width / 2, -side_length / 2 - border_width / 2)
t.pendown()
t.pensize(border_width)
t.color("black")  # 테두리 색깔
for _ in range(4):
    t.forward(side_length + border_width)
    t.left(90)

# 화면 유지
turtle.done()
