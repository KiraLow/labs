def square(y1, x1):
    return (y1 + x1 / y1) / 2

x = float(input("Число, у которого ищем квадратный корень"))
yi = x
y = yi
yi = (y + x / y) / 2

if (y - yi) >= 0.00001:
    while (y - yi) >= 0.00001:
        y = yi
        yi = square(y, x)
print("Результат = ", round(y,3))