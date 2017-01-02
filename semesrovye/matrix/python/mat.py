from PIL import Image, ImageDraw  # Подключим необходимые библиотеки.
import math

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//lena.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
pix = image.load()  # Выгружаем значения пикселей.

Gauss = [[0.5, 0.5, 0.5], [0.5, 1.0, 0.5], [0.5, 0.5, 0.5]]
print(Gauss[1][1])
for i in range(len(Gauss)):
    for j in range(len(Gauss[i])):
        print(Gauss[i][j], '\t', end=' ')
    print()
    resultR = pix[i, j][0] * Gauss[i][j]
    resultG = pix[i, j][1] * Gauss[i][j]
    resultB = pix[i, j][2] * Gauss[i][j]

    draw.point((i, j), (resultR, resultG, resultB))
    image.save("//home//vlad//Prg//semesrovye//img//imgGauss//lena_res.jpg", "JPEG")
del draw
