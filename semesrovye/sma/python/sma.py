import random
import pylab
mas = [10]
for i in range(9):
    mas.append(random.randrange(1,9))
print("\n", mas)

dot = [10]
y = [1,2,3,4,5,6,7,8,9,10]
for l in range(9):
    dot.append((mas[l-1] + mas[l] + mas[l+1]) / 3)
print(dot)
pylab.plot(y, mas)
pylab.plot(y, dot,"-g")
pylab.title('SMA')
pylab.show()