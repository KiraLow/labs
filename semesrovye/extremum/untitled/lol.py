A = []
i = int(0)
for i in range(3):
    A.append(input())
l = 0
B = []
for l in range(3):
    B.append(input())
j = 0
C = []
for j in range(3):
    buf = int(A[j]) * int(B[j])
    C.append(buf)
print(C)
