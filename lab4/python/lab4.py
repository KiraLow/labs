import math
import pylab

while (True):
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        x1 = float(input("Введите первую границу для аргумента: "))
        x2 = float(input("Введите вторую границу для аргумента: "))
        a = float(input("Введите первую границу для параметра: "))
        a2 = float(input("Введите вторую границу для параметра: "))
        kol_step = int(input("Введите количество шагов"))
        step_for_x = (x2 - x1) / kol_step
        step_for_a = (a2 - a) / kol_step
        v = str(input("Введите букву функции, которую хотите вычислить "))
        diff = float(input("введите максимальную разницу между функциями"))
        xlist = []
        ylist = []
        if v == "G":
            x_mod = float(x1)
            a_mod = float(a2)
            j = 0
            while kol_step > j:
                if 4 * (a_mod * a_mod) + a_mod * x_mod - 5 * (x_mod * x_mod) <= 0.00000000001 and 4 * (
                            a_mod * a_mod) + a_mod * x_mod - 5 * (
                            x_mod * x_mod) > -0.00000001:
                    print("Входные значения не принадлежат области определения функции. "
                          "(Введите другие значения)")
                    break
                else:
                    g_1 = float(-(8 * (12 * pow(a_mod, 2) + 68 * a_mod * x_mod + 63 * pow(x_mod, 2))))
                    g_2 = float(4 * pow(a_mod, 2) + a_mod * x_mod - 5 * pow(x_mod, 2))
                    G = float(g_1 / g_2)
                    xlist.append(x_mod)
                    ylist.append(G)
                    print("G = ", round(G, 4), " при x = ", x_mod, "при аргументе = ", a_mod)
                    x_mod += step_for_x
                    a_mod += step_for_a
                    j += 1
            pylab.plot(xlist, ylist)
            pylab.show()
        i = 0
        min_f = float(ylist[i])
        max_f = float(ylist[i])
        while i < len(ylist):
            if ylist[i] < min_f:
                min_f = ylist[i]
            if ylist[i] > max_f:
                max_f = ylist[i]
            i += 1
        print("Минимальное значение = ", min_f, "\n Максимальное значение = ", max_f)

        if v == "Y":
            x_mod = int(x1)
            while x_mod < x2:
                Y = float(-7 * pow(a_mod, 2) + 40 * a_mod * x_mod + 63 * pow(x_mod, 2) + 1)
                xlist.append(x_mod)
                ylist.append(Y)
                print("Y =", Y, " при x = ", x_mod)
                x_mod += step_for_x
                a_mod += step_for_a
                diff_Y = float(-7 * pow(a_mod, 2) + 40 * a_mod * x_mod + 63 * pow(x_mod, 2) + 1)
                if diff <= (abs(diff_Y - Y)):
                    while diff <= (abs(diff_Y - Y)):
                        step_for_x /= 2
                        step_for_a /= 2
                        x_mod -= step_for_x
                        a_mod -= step_for_a
                        diff_Y = -7 * pow(a_mod, 2) + 40 * a_mod * x_mod + 63 * pow(x_mod, 2) + 1
            pylab.title("График")
            pylab.plot(xlist, ylist)
            pylab.show()
            i = 0
            min_f = float(ylist[i])
            max_f = float(ylist[i])
            while i < len(ylist):
                if ylist[i] < min_f:
                    min_f = ylist[i]
                if ylist[i] > max_f:
                    max_f = ylist[i]
                i += 1
            print("Минимальное значение = ", min_f, "\n Максимальное значение = ", max_f)
        if v == "F":
            x_mod = int(x1)
            a_mod = a
            while x_mod < x2:
                if math.pi * (40 * a_mod ** 2 - 61 * a_mod * x_mod + 7 * x_mod ** 2) >= 0.000000001 or math.pi * (
                                    40 * a_mod ** 2 - 61 * a_mod * x_mod + 7 * x_mod ** 2) <= -0.000000001:
                    F = float(math.sin(math.pi * (40 * a_mod ** 2 - 61 * a_mod * x_mod + 7 * x_mod ** 2)) / (
                        math.pi * (40 * a_mod ** 2 - 61 * a_mod * x_mod + 7 * x_mod ** 2)))
                    xlist.append(x_mod)
                    ylist.append(F)
                    print("F =", F, " при x = ", x_mod)
                    x_mod += step_for_x
                    a_mod += step_for_a
                else:
                    print('Не существует синуса к заданной функции')
            pylab.title("График")
            pylab.plot(xlist, ylist)
            pylab.show()
            i = 0
            min_f = float(ylist[i])
            max_f = float(ylist[i])
            while i < len(ylist):
                if ylist[i] < min_f:
                    min_f = ylist[i]
                if ylist[i] > max_f:
                    max_f = ylist[i]
                i += 1
            print("Минимальное значение = ", min_f, "\n Максимальное значение = ", max_f)
    if run == "no":
        print("Ну и ладно c: ")
        exit(0)
    if run != "yes" and run != "no":
        print("Что-то не пойму что ты написал, давай еще раз ")
