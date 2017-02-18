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
        s1 = float((pix[i - rad, j - rad][0] * 0.5 + pix[i - rad, j][0] * 0.75 + pix[i - rad, j + rad][0] * 0.5
                    + pix[i, j - rad][0] * 0.75 + pix[i, j][0] * 1 + pix[i, j + rad][0] * 0.75
                    + pix[i + rad, j - rad][0] * 0.5 + pix[i + rad, j][0] * 0.75 + pix[i + rad, j + rad][0]) * 0.5) // 3.3
        s2 = float((pix[i - rad, j - rad][1] * 0.5 + pix[i - rad, j][1] * 0.75 + pix[i - rad, j + rad][1] * 0.5
                    + pix[i, j - rad][1] * 0.75 + pix[i, j][1] * 1 + pix[i, j + rad][1] * 0.75
                    + pix[i + rad, j - rad][1] * 0.5 + pix[i + rad, j][1] * 0.75 + pix[i + rad, j + rad][1]) * 0.5) // 3.3
        s3 = float((pix[i - rad, j - rad][2] * 0.5 + pix[i - rad, j][2] * 0.75 + pix[i - rad, j + rad][2] * 0.5
                    + pix[i, j - rad][2] * 0.75 + pix[i, j][2] * 1 + pix[i, j + rad][2] * 0.75
                    + pix[i + rad, j - rad][2] * 0.5 + pix[i + rad, j][2] * 0.75 + pix[i + rad, j + rad][2]) * 0.5) // 3.3
        draw.point((i, j), (int(s1), int(s2), int(s3)))
        j += 1
    i += 1

image.save("//home//vlad//Prg//semesrovye//img//imgGauss//lena_res.jpg", "JPEG")
del draw