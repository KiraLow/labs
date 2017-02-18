import random
import time
import matplotlib.pyplot as plt

A = [0, 0, 0, 0, 0, 0, 0, 0, 0]
B = [0, 0, 0, 0, 0, 0, 0, 0, 0]
c = 0

for i in range(9):
    A[i] = int(random.randint(-99, 99))
    B[i] = int(random.randint(-99, 99))
print("\nПервая матрица:\n")
for i in range(3):
    print(A[i], A[i + 1], A[i + 2])
print("\nВторая матрица:\n")
for i in range(3):
    print(B[i], B[i + 1], B[i + 2])

C = [0, 0, 0, 0, 0, 0, 0, 0, 0]
start = time.time()
for k in range(3):
    for j in range(3):
        C[k * 3 + j] = 0
        for i in range(3):
            C[k * 3 + j] += A[k * 3 + i] * B[i * 3 + j]

print("\nРезультат умножения:\n")
for i in range(0, 9, 3):
    print(C[i], '\t', C[i + 1], '\t', C[i + 2])

A = [0, 0, 0, 0, 0, 0, 0, 0, 0]
B = [0, 0, 0, 0, 0, 0, 0, 0, 0]

for i in range(9):
    A[i] = int(random.uniform(-99, 99))
    B[i] = int(random.uniform(-99, 99))
print("\nПервая матрица:\n")
for i in range(3):
    print(A[i], A[i + 1], A[i + 2])
print("\nВторая матрица:\n")
for i in range(3):
    print(B[i], B[i + 1], B[i + 2])

C = [0, 0, 0, 0, 0, 0, 0, 0, 0]
for k in range(3):
    for j in range(3):
        C[k * 3 + j] = 0
        for i in range(3):
            C[k * 3 + j] += A[k * 3 + i] * B[i * 3 + j]

print("\nРезультат умножения:\n")
for i in range(0, 9, 3):
    print(C[i], '\t', C[i + 1], '\t', C[i + 2])
