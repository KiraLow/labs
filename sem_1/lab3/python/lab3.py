import math
import pylab
pi = 3.14
while (True):
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        x1 = float(input("Введите первую границу для x: "))
        x2 = float(input("Введите вторую границу для x: "))
        a = float(input("Введите a: "))
        step = float(input("Введите шаг: "))
        v = str(input("Введите букву функции, которую xотите вычислить "))
        diff = float(input("Введите максимальную разницу между значениями функций"))
        i = 0
        xlist = []
        ylist = []
        if v == "G":
            x_mod = float(x1)
            while x_mod <= x2:
                if x_mod == -4 * a / 5 or x_mod == a:
                    print("Входные значения не принадлежат области определения функции. "
                        "(Введите другие значения)")
                    break
                else:
                    g_1 = float(-(8 * (12 * pow(a, 2) + 68 * a * x_mod + 63 * pow(x_mod, 2))))
                    g_2 = float((4 * pow(a, 2) + a * x_mod - 5 * pow(x_mod, 2)))
                    G = float(g_1 / g_2)
                    xlist.append(x_mod)
                    ylist.append(G)
                    print("G = ", round(G, 4), " при x = ", x_mod)
                    x_mod += step
                    if (4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod)) != 0.0:
                        diff_G = float(-(8 * (12 * (a * a) + 68 * a * x_mod + 63 * (x_mod * x_mod))) /
                                (4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod)))
                        if diff <= (abs(diff_G - G)):
                            step /= 2
                            x_mod += step
                        else:
                                print("error")
                        if diff >= (abs(diff_G - G)):
                            step *= 2
                            x_mod += step

            pylab.plot(xlist, ylist)
            pylab.show()

        if v == "Y":
            while x1 < x2:
                xlist.append(x1)
                ylist.append(Y)
                Y = -7 * pow(a, 2) + 40 * a * x1 + 63 * pow(x1, 2) + 1
                print("Y =", Y)
                x1 += step
                i += 1
            pylab.plot(xlist, ylist)
            pylab.show()
        if v == "F":
            f_without_sin = float(
                pi * (40 * a ** 2 - 61 * a * x1 + 7 * x1 ** 2) / (pi * (40 * a ** 2 - 61 * a * x1 + 7 * x1 ** 2)))
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
