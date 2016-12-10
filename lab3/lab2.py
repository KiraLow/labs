import math
import pylab

while (True):
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        x_mod = float(input("Введите первую границу для параметра: "))  # Организовать ввод границ изменения x
        x2 = float(input("Введите вторую границу для параметра: "))  # Организовать ввод границ изменения x
        a = float(input("Введите аргумент: "))
        que = str(input("Включаем адаптивный шаг? y/n"))  # Запрос на включение адаптивного шага
        kol_step = int(input("Введите количество шагов"))  # Организовать ввод количества шагов вычисления функции
        # или задать условие, при котором вычисления остановятся.
        step_for_x = (x2 - x_mod) / (kol_step - 1)
        v = str(input("Введите букву функции, которую хотите вычислить "))
        diff = float(input("введите максимальную разницу между функциями"))
        x_list = []  # Массивы для хранения значений, дальше для графика
        a_list = []
        j = 0
        if v == "G":
            while kol_step > j:
                if 0.0000000000000001 >= 4 * (a * a) + a * x_mod - 5 * (x_mod * x_mod) and 4 * (
                            a * a) + a * x_mod - 5 * (
                            x_mod * x_mod) > -0.00000001:
                    print("Входные значения не принадлежат области определения функции. "
                          "(Введите другие значения)")
                    break
                else:
                    g_1 = float(-(8 * (12 * pow(a, 2) + 68 * a * x_mod + 63 * pow(x_mod, 2))))
                    g_2 = float(4 * pow(a, 2) + a * x_mod - 5 * pow(x_mod, 2))
                    G = float(g_1 / g_2)
                    x_list.append(x_mod)
                    a_list.append(G)
                    print("G = ", round(G, 4), " при x = ", x_mod, "при аргументе = ", a, "шаг = ", step_for_x)
                    x_mod += step_for_x
                    G2 = float(-(8 * (12 * pow(a, 2) + 68 * a * x_mod + 63 * pow(x_mod, 2)))) / (4 * pow(a, 2) + a * x_mod - 5 * pow(x_mod, 2))
                    if que == "y" and abs(G2 - G) > diff:
                        step_for_x /= 2
                        x_mod += step_for_x
                        j -= 1
                    j += 1
            pylab.plot(x_list, a_list)  # график по полученным значениям
            pylab.show()

        if v == "Y":
            while kol_step > j:
                Y = float(-7 * pow(a, 2) + 40 * a * x_mod + 63 * pow(x_mod, 2) + 1)
                x_list.append(x_mod)
                a_list.append(Y)
                print("Y =", Y, " при x = ", x_mod)
                x_mod += step_for_x
                diff_Y = float(-7 * pow(a, 2) + 40 * a * x_mod + 63 * pow(x_mod, 2) + 1)
                if que == "y" and abs(diff_Y - Y) > diff:
                    step_for_x /= 2
                    x_mod += step_for_x
                    j -= 1
                j += 1
            pylab.title("График")
            pylab.plot(x_list, a_list)
            pylab.show()

        if v == "F":
            while kol_step < j:
                if math.pi * (40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2) <= 0.000000001 and math.pi * (
                                    40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2) >= -0.000000001:
                    print("На ноль делить нельзя")
                else:
                    F = float(math.sin(math.pi * (40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2)) / (
                        math.pi * (40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2)))
                    x_list.append(x_mod)
                    a_list.append(F)
                    print("F =", F, " при x = ", x_mod)
                    x_mod += step_for_x
                    diff_F = float(math.sin(math.pi * (40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2)) / (
                        math.pi * (40 * a ** 2 - 61 * a * x_mod + 7 * x_mod ** 2)))
                    if que == "y" and abs(diff_F - F) > diff:
                        step_for_x /= 2
                        x_mod += step_for_x
                        j -= 1
                    j += 1
            pylab.title("График")
            pylab.plot(x_list, a_list)
            pylab.show()

    if run == "no":
        print("Ну и ладно c: ")
        exit(0)
    if run != "yes" and run != "no":
        print("Что-то не пойму что ты написал, давай еще раз ")
