def function(x1):
    return x1*x1*4+x1*2

xStart = float(input())
xEnd = float(input())
e = float(input())
while abs(xStart - xEnd) > e:
    x = (xEnd + xStart) / 2
    f1 = function(x - e)
    f2 = function(x + e)
    if f1 < f2:
        xEnd = x
    else:
        xStart = x
print(xEnd)