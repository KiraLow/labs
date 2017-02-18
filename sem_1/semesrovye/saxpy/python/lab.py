import time
from numpy import *
import numpy as np
import matplotlib.pyplot as plt
import random
a = int(input('Введите A:'))
i = int(0)
j = int(0)
i_general = []
xInt = [500]
yInt = [500]
yInt2 = [500]
xFloat = [500]
yFloat = [500]
yFloat2 = [500]
dif_int = []
dif_float = []
values_int = []
values_float =[]
n = 500
while i < 500:
    xInt[i:] = np.random.randint(0, 100, 1)
    yInt[i:] = np.random.randint(0, 100, 1)
    xFloat[i:] = np.random.uniform(0, 100, 1)
    yFloat[i:] = np.random.uniform(0, 100, 1)
    i += 1
i = 0
start = time.time()
while i <= n:
    yInt2.append(a * xInt[i:] + yInt[i:])
    if (i == 0) or (i == 100) or (i == 200) or (i == 300) or (i == 400) or (i == 500):
        end = time.time()
        i_general.append(i)
        dif_int.append(end - start)
    i += 1
i = 0
start = time.time()
while i <= n:
    yFloat2.append(a * xFloat[i:] + yFloat[i:])
    if (i == 0) or (i == 100) or (i == 200) or (i == 300) or (i == 400) or (i == 500):
        end = time.time()
        dif_float.append(end - start)
    i += 1
print(i_general)
print(dif_int)
print(dif_float)
plt.plot(i_general, dif_int, 'g-', label='int Type')
plt.plot(i_general, dif_float, 'r--', label='float Type')
plt.xlabel('vector')
plt.ylabel('time')
plt.legend()
plt.show()