def function(x1):
    return x1 ** 2 + 5 * x1 + 10

def kol(xEnd,xStart):
    while xEnd - xStart < e:
        x = (xEnd + xStart) / 2
        f1 = function(x) - e
        f2 = function(x) + e
        if f1 < f2:
            xEnd = x
        else:
            xStart = x
    return xStart

xStart = float(input())
xEnd = float(input())
e = float(input())

x = (xEnd + xStart) / 2
f1 = function(x - e)
f2 = function(x + e)
if f1 < f2:
    xEnd = x
else:
    xStart = x

print(kol(xEnd,xStart))