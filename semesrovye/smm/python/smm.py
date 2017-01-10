import random
import numpy as np
import matplotlib.pyplot as plt
mas = []


def odd(array, count, num):
    average = []
    mass = []
    for elem in array:
        if len(mass) < count:
            mass.append(elem)
        else:
            temp = mass.copy()
            mass.sort()
            sortingmass = mass.copy()
            mass = temp.copy()
            average.append(float(sortingmass[num]))
            mass.pop(0)
            mass.append(elem)
    return average

def aneven(array, count, num):
    average = []
    mass = []
    for elem in array:
        if len(mass) < count:
            mass.append(elem)
        else:
            temp = mass.copy()
            mass.sort()
            sortingmass = mass.copy()
            mass = temp.copy()
            average.append(float((sortingmass[num] + sortingmass[num - 1]) / 2))
            mass.pop(0)
            mass.append(elem)
    return average

def Srednee(arr, count):
    if count % 2 == 0:
        return aneven(arr, count, count // 2)
    else:
        return odd(arr, count, count // 2)


def Data():
    data = open('txt.log', 'r').readlines()

    temp1 = []
    temp2 = []

    timeCount = []
    timeCounts = []

    i = 1
    for line in data:
        lineS = line.split('\t')
        timeCount.append(float(lineS[0]))
        temp1.append(float(lineS[4]))
        temp2.append(float(lineS[5]))
        if i > 9:
            timeCounts.append(float(lineS[0]))
        i += 1

    temp1s = Srednee(temp1, 9)
    temp2s = Srednee(temp2, 9)

    temp1array = np.array(temp1)
    temp2array = np.array(temp2)
    timeCountarray = np.array(timeCount)

    temp1sArray = np.array(temp1s)
    temp2sArray = np.array(temp2s)
    timeCountsArray = np.array(timeCounts)

    plt.figure(1)

    plt.subplot(211)
    plt.plot(timeCountarray, temp1array)
    plt.plot(timeCountsArray, temp1sArray, 'black')
    plt.grid()

    plt.subplot(212)
    plt.plot(timeCountarray, temp2array)
    plt.plot(timeCountsArray, temp2sArray, 'black')
    plt.grid()
    plt.show()

