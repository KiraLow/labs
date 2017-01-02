from PIL import Image, ImageDraw  # Подключим необходимые библиотеки.
import math

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//lena.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
pix = image.load()  # Выгружаем значения пикселей.
s = []
rad = int(input())
i = rad+1
while i < width - (rad+1):
    j=rad+1
    while j < height - (rad+1):
        s1 = (pix[i - rad, j - rad][0] + pix[i - rad, j][0] + pix[i - rad, j + rad][0] + pix[i, j - rad][0] + pix[i, j][0] +
              pix[i, j + rad][0] + pix[i + rad, j - rad][0] + pix[i + rad, j][0] + pix[i + rad, j + rad][0]) // 9
        s2 = (pix[i - rad, j - rad][1] + pix[i - rad, j][1] + pix[i - rad, j + rad][1] + pix[i, j - rad][1] + pix[i, j][1] +
              pix[i, j + rad][1] + pix[i + rad, j - rad][1] + pix[i + rad, j][1] + pix[i + rad, j + rad][1]) // 9
        s3 = (pix[i - rad, j - rad][2] + pix[i - rad, j][2] + pix[i - rad, j + rad][2] + pix[i, j - rad][2] + pix[i, j][2] +
              pix[i, j + rad][2] + pix[i + rad, j - rad][2] + pix[i + rad, j][2] + pix[i + rad, j + rad][2]) // 9
        draw.point((i, j), (s1, s2, s3))
        j += 1
    i += 1

image.save("//home//vlad//Prg//semesrovye//img//imgGauss//lena_res.jpg", "JPEG")
del draw
