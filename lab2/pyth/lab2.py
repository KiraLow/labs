import math

pi = 3.14
while (True):
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        x = int(input("Введите x: "))
        a = int(input("Введите a: "))
        v = str(input("Введите букву функции, которую xотите вычислить "))
        F = 0
        G = 0
        Y = 0
        if v == "G":
            if x == -4 * a / 5 or x == a:
                print("Данной функции не существует, тлен, жизнь боль (введите другие значения")
            else:
                G = -(8 * (12 * pow(a, 2) + 68 * a * x + 63 * pow(x, 2))) / (4 * pow(a, 2) + a * x - 5 * pow(x, 2))
                print("G =", G)
        elif v == "Y":
            Y = -7 * pow(a, 2) + 40 * a * x + 63 * pow(x, 2) + 1
            print("Y =", Y)
        elif v == "F":
            f_1 = math.sin(pi * (40 * (a * a) - 61 * a * x + 7 * (x * x)))
            f_2 = pi * (40 * (a * a) - 61 * a * x + 7 * (x * x))
            if f_2 == 0:
                print('Не существует синуса к заданной функции')
            else:
                F = f_1 / f_2
                print("F =", F)
    if run == "no":
        print("Ну и ладно c: ")
        exit()
    if run != "yes" and run != "no":
        print("Что-то не пойму что ты написал, давай еще раз ")
