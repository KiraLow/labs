import random
import pylab
countRow = int(input())
mas = [countRow]
for i in range(countRow - 1):
    mas.append(random.randrange(1,9)*2 / 3.2)
print("\n", mas)

dot = [countRow]
y = [i for i in range(countRow)]
l = 1
for l in range(countRow-1):
    dot.append((mas[l-1] + mas[l] + mas[l+1]) / 3)
print(dot)
pylab.plot(y, mas)
pylab.plot(y, dot,"-g")
pylab.title('SMA')
pylab.show()