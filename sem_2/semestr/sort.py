import numpy as np
import sys
import time
sys.setrecursionlimit(2000)
class Profiler(object):
    def __enter__(self):
        self._startTime = time.time()
    def __exit__(self, type, value, traceback):
        print("{:.10f}".format(time.time() - self._startTime))
def bubble_sort(li):
    a = li
    for i in range(len(a), 0, -1):
        for j in range(1, i):
            if a[j-1] > a[j]:
                tmp = a[j-1]
                a[j-1] = a[j]
                a[j] = tmp
    return a
def bubble_sort_def(li):
    a = li
    for i in range(len(a), 0, -1):
        for j in range(1, i):
            if a[j-1] < a[j]:
                tmp = a[j-1]
                a[j-1] = a[j]
                a[j] = tmp
    return a
def insertion_sort(arrayToSort):
    a = arrayToSort
    for i in range(len(a)):
        v = a[i]
        j = i
        while (a[j-1] > v) and (j > 0):
            a[j] = a[j-1]
            j = j - 1
        a[j] = v
    return a
def insertion_sort_def(arrayToSort):
    a = arrayToSort
    for i in range(1, len(a)):
        j = i
        while (j > 0) and (a[j - 1] < a[j]):
            a[j-1], a[j] = a[j], a[j-1]
            j = j - 1
    return a
def shellsort(seq):
    inc = len(seq) // 2
    while inc:
        for i, el in enumerate(seq):
            while i >= inc and seq[i - inc] > el:
                seq[i] = seq[i - inc]
                i -= inc
            seq[i] = el
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)
def shellsort_def(seq):
    inc = len(seq) // 2
    while inc:
        for i, el in enumerate(seq):
            while i >= inc and seq[i - inc] < el:
                seq[i] = seq[i - inc]
                i -= inc
            seq[i] = el
        inc = 1 if inc == 2 else int(inc * 5.0 / 11)
def partition(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot
    for j in range(low, high):
        # If current element is smaller than or
        # equal to pivot
        if arr[j] < pivot:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)
def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)
def partition_def(arr, low, high):
    i = (low - 1)  # index of smaller element
    pivot = arr[high]  # pivot
    for j in range(low, high):
        # If current element is smaller than or
        # equal to pivot
        if arr[j] > pivot:
            # increment index of smaller element
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return (i + 1)
def quickSort_def(arr, low, high):
    if low < high:
        pi = partition_def(arr, low, high)
        quickSort_def(arr, low, pi - 1)
        quickSort_def(arr, pi + 1, high)
n = 1
count = 100
while count <= 1000:
    li = np.random.sample(count)
    with Profiler() as p:
        bubble_sort(li)
    with Profiler() as p1:
        bubble_sort_def(li)
    with Profiler() as p2:
        bubble_sort(li)
    print("Bubble cort with {}".format(count))
    li = np.random.sample(count)
    with Profiler() as m:
        insertion_sort(li)
    with Profiler() as m1:
        insertion_sort_def(li)
    with Profiler() as m2:
        insertion_sort(li)
    print("Insertion cort with {}".format(count))
    li = np.random.sample(count)
    with Profiler() as o:
        shellsort(li)
    with Profiler() as o1:
        shellsort_def(li)
    with Profiler() as o2:
        shellsort(li)
    print("Shell cort with {}".format(count))
    li = np.random.sample(count)
    with Profiler() as l:
        quickSort(li, 0, len(li) - 1)
    with Profiler() as l1:
        quickSort_def(li, 0, len(li) - 1)
    with Profiler() as l2:
        quickSort(li, 0, len(li) - 1)
    print("Quick cort with {}".format(count))
    count += 100
