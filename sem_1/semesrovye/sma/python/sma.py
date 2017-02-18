import random
import pylab
countRow = int(input())
mas = [countRow]
for i in range(countRow-1):
    mas.append(random.randrange(1,100))
print("\n", mas)

dot = [countRow]
y = [i  for i in range(countRow)]
for l in range(countRow-1):
    dot.append((mas[l-1] + mas[l] + mas[l+1]) / 3)
print(dot)
pylab.plot(y, mas, "go-")
pylab.plot(y, dot,"r--")
pylab.title('SMA')
pylab.show()
