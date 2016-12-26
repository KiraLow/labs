from numpy import *
import matplotlib.pyplot as plt
import random
import time

t = linspace(0, 3, 51)
x = []
y = []
i = 0
m = 0
l = 0
t = 0
kolDot = 100
rad = float(input("Введите радиус"))
f = open('//home//iarven//prog//test.txt', 'w+')
while kolDot <= 5000:
    while i < kolDot:
        t1 = time.time()
        x.append(random.uniform(-5, 5))
        y.append(random.uniform(-5, 5))
        i += 1
    if kolDot == 100:
        x1 = random.uniform(-5, 5)
        y1 = random.uniform(-5, 5)
    while m != kolDot:
        if sqrt((pow(x1 - x[m], 2)) + (pow(y1 - y[m], 2))) <= rad:
            l += 1
        m += 1
    t = time.time() - t1
    print("При", kolDot, "количестве точек, количество точек, принадлежащих окружности составляет: %i", l, "\n")
    print("Время выполнения программы = ", t)
    f.write(str(kolDot))
    f.write(",")
    f.write(str(t))
    f.write("\n")
    kolDot += 100
plt.plot(x, y, '.',
             x1, y1, 'ro')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Генерация точек')
plt.legend(['легенда'],  # список легенды
               )  # положение легенды

plt.show()