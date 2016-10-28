import math
import pylab
from matplotlib import mlab
pi = 3.14
while (True):
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        x = float(input("Введите x: "))
        a = float(input("Введите a: "))
        start_f = int(input("Введите, сколько хотите значений x: "))
        step = float(input("Введите шаг: "))
        start_x = float(input("введите начало графика по x "))
        end_x = float(input("введите конец графика по х "))
        v = str(input("Введите букву функции, которую xотите вычислить "))
        F = 0
        G = 0
        Y = 0
        i = 0
        xlist = []
        ylist = []
        if v == "G":
            while i < start_f:
                g_1 = -(8 * (12 * pow(a, 2) + 68 * a * x + 63 * pow(x, 2)))
                g_2 = (4 * pow(a, 2) + a * x - 5 * pow(x, 2))
                G = g_1 / g_2
                xlist.append(x)
                ylist.append(G)
                print("G = ", round(G, 4), " при x = ", x)
                x += step
                i += 1
            pylab.plot(xlist, ylist)

            pylab.show()
        if v == "Y":
            while i < start_f:
                xlist = mlab.frange(nach_x, end_x, step)
                ylist = [-7 * pow(a, 2) + 40 * a * x + 63 * pow(x, 2) + 1 for x in xlist]
                Y=-7 * pow(a, 2) + 40 * a * x + 63 * pow(x, 2) + 1
                print("Y =", Y)
            pylab.plot(xlist, ylist)

            pylab.show()
        if v == "F":
            f_without_sin = int(
                pi * (40 * a ** 2 - 61 * a * x + 7 * x ** 2) / (pi * (40 * a ** 2 - 61 * a * x + 7 * x ** 2)))
            if f_without_sin:
                F = math.sin(f_without_sin)
                print("F =", F)
            else:
                print('Не существует синуса к заданной функции')
    if run == "no":
        print("Ну и ладно c: ")
        exit(0)
    if run != "yes" and run != "no":
        print("Что-то не пойму что ты написал, давай еще раз ")
