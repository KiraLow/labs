def square(y1, x1):
    return (y1 + x1 / y1) / 2

x = float(input("Число, у которого ищем квадратный корень"))
e = float(input("Введем точность, с которой хотим вычислить"))
yi = float(x)
y = float()
y = yi
yi = (y + x / y) / 2

if (y - yi) >= e:
    while (y - yi) >= e:
        y = yi
        yi = square(y, x)
print("Результат = ", y)