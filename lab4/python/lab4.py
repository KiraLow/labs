import math
import pylab

while True:
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        xMod = float(input("Введите первую границу для аргумента: "))  # Организовать ввод начального
        x2 = float(input("Введите вторую границу для аргумента: "))  # и конечного значений аргумента
        aMod = float(input("Введите первую границу для параметра: "))
        a2 = float(input("Введите вторую границу для параметра: "))
        KolStep = int(input("Введите количество шагов"))  # количество шагов расчета функций G, F, Y
        StepForX = (x2 - xMod) / KolStep
        StepForA = (a2 - aMod) / KolStep
        choice = str(input("Введите букву функции, которую хотите вычислить "))
        xList = []
        yList = []
        if choice == "G":
            j = 0
            while KolStep > j:
                if 4 * (aMod * aMod) + aMod * xMod - 5 * (xMod * xMod) <= 0.0000000000000001 and 4 * (
                            aMod * aMod) + aMod * xMod - 5 * (xMod * xMod) > -0.00000001:
                    print("Входные значения не принадлежат области определения функции.\n"
                          "(Введите другие значения)")
                    break
                else:
                    g_1 = float(-(8 * (12 * pow(aMod, 2) + 68 * aMod * xMod + 63 * pow(xMod, 2))))
                    g_2 = float(4 * pow(aMod, 2) + aMod * xMod - 5 * pow(xMod, 2))
                    G = float(g_1 / g_2)  # расчет значений функций  G
                    xList.append(xMod)  # Добавляем значения в массив
                    yList.append(G)
                    print("G = ", round(G, 4), " при x = ", round(xMod, 4), "при аргументе = ", round(aMod, 4))
                    xMod += StepForX
                    aMod += StepForA
                    j += 1
            pylab.plot(xList, yList)
            pylab.show()
            i = 0
            minF = float(yList[i])
            maxF = float(yList[i])
            while i < len(yList):
                if yList[i] < minF:
                    minF = yList[i]
                if yList[i] > maxF:
                    maxF = yList[i]
                i += 1
            print("Минимальное значение = ", minF, "\nМаксимальное значение = ", maxF)

        if choice == "Y":
            j = 0
            while KolStep > j:
                Y = float(-7 * pow(aMod, 2) + 40 * aMod * xMod + 63 * pow(xMod, 2) + 1)
                xList.append(xMod)
                yList.append(Y)
                print("Y =", Y, " при x = ", xMod)
                xMod += StepForX
                aMod += StepForA
                j += 1
            pylab.title("График")
            pylab.plot(xList, yList)
            pylab.show()
            i = 0
            minF = float(yList[i])
            maxF = float(yList[i])
            while i < len(yList):
                if yList[i] < minF:
                    minF = yList[i]
                if yList[i] > maxF:
                    maxF = yList[i]
                i += 1
            print("Минимальное значение = ", minF, "\n Максимальное значение = ", maxF)
        if choice == "F":
            j = 0
            while KolStep > j:
                if math.pi * (40 * aMod ** 2 - 61 * aMod * xMod + 7 * xMod ** 2) >= 0.000000001 or math.pi * (
                                    40 * aMod ** 2 - 61 * aMod * xMod + 7 * xMod ** 2) <= -0.000000001:
                    F = float(math.sin(math.pi * (40 * aMod ** 2 - 61 * aMod * xMod + 7 * xMod ** 2)) / (
                        math.pi * (40 * aMod ** 2 - 61 * aMod * xMod + 7 * xMod ** 2)))
                    xList.append(xMod)
                    yList.append(F)
                    print("F =", F, " при x = ", xMod)
                    xMod += StepForX
                    aMod += StepForA
                    j += 1
                else:
                    print('Не существует синуса к заданной функции')
            pylab.title("График")
            pylab.plot(xList, yList)
            pylab.show()
            i = 0
            minF = float(yList[i])
            maxF = float(yList[i])
            while i < len(yList):
                if yList[i] < minF:
                    minF = yList[i]
                if yList[i] > maxF:
                    maxF = yList[i]
                i += 1
            print("Минимальное значение = ", minF, "\n Максимальное значение = ", maxF)
    if run == "no":
        print("Ну и ладно c: ")
        exit(0)
    if run != "yes" and run != "no":
        print("Что-то не пойму что ты написал, давай еще раз ")