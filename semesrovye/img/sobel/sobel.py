from PIL import Image, ImageDraw
import math

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//lena.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
C = image.load()  # Выгружаем значения пикселей.

i = 2
for i in range(height - 2):
    j = 2
    for j in range(width - 2):
        Gx = ((2 * C[i + 2, j + 1][0] + C[i + 2, j][0] + C[i + 2, j + 2][0]) - (2 * C[i, j + 1][0] + C[i, j][0] + C[i, j + 2][0]))
        Gy = ((2 * C[i + 1, j + 2][0] + C[i, j + 2][0] + C[i + 2, j + 2][0]) - (2 * C[i + 1, j][0] + C[i, j][0] + C[i + 2, j][0]))
        G = int(math.sqrt(Gx * Gx + Gy * Gy))
        draw.point((i, j), (G, G, G))
  #ebanoe gobniche
image.save("//home//vlad//Prg//semesrovye//img//sobel//lena_sobol.jpg", "JPEG")
del draw
