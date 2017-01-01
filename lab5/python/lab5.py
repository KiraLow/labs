import math
import pylab

while True:
    run = input("Вычислим функцию? (yes/no)")
    if run == "yes":
        tempForValues = input("Введите первую границу для аргумента: ")
        xMod = float(tempForValues)  # Организовать ввод начального
        tempForValues = float(input("Введите вторую границу для аргумента: "))
        x2 = float(tempForValues)  # и конечного значений аргумента
        tempForValues = float(input("Введите первую границу для параметра: "))
        aMod = float(tempForValues)
        tempForValues = float(input("Введите вторую границу для параметра: "))
        a2 = float(tempForValues)
        tempForValues = int(input("Введите количество шагов"))
        KolStep = int(tempForValues)  # количество шагов расчета функций G, F, Y

        StepForX = (x2 - xMod) / KolStep
        StepForA = (a2 - aMod) / KolStep

        choice = input("Введите букву функции, которую хотите вычислить ")

        xList = []
        yList = []
        j = 0
        result = str()
        if choice == "G":
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
                    result += str(G)
                    xMod += StepForX
                    aMod += StepForA
                    j += 1
            pylab.plot(xList, yList)
            pylab.show()
            print(result)
            tempForValues = input("Шаблон")
            resultEnd = result.split(tempForValues)
            count = len(resultEnd) - 1
            print(count)
            result = ' '

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
