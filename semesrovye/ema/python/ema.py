import random
import pylab
print("Период")
countRow = int(input())
print("Сглаживание")
N = int(input())
mas = [countRow]
for i in range(countRow-1):
    mas.append(random.randrange(1,100))
print("\n", mas)

dot = [countRow]
y = [i  for i in range(countRow)]
for l in range(countRow-1):
    dot1 = ((mas[l-1] + mas[l] + mas[l+1]) / N)
    value = 2/(N+1)
    dot.append(value * mas[l] + (1 - value) * dot1)
print(dot)
pylab.plot(y, mas, "g--")
pylab.plot(y, dot,"ro-")
pylab.title('SMA')
pylab.show()
