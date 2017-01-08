import random
import pylab
countRow = int(input())
mas = [countRow]
for i in range(countRow-1):
    mas.append(random.randrange(1,9))
print("\n", mas)

dot = [countRow]
y = [i ** 2 for i in range(countRow)]
for l in range(countRow-1):
    dot.append((mas[l-1] + mas[l] + mas[l+1]) / 3)
print(dot)
pylab.plot(y, mas)
pylab.plot(y, dot,"-g")
pylab.title('SMA')
pylab.show()