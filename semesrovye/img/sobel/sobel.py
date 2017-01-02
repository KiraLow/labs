from PIL import Image, ImageDraw  # Подключим необходимые библиотеки.
import math

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//lena_res.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
pix = image.load()  # Выгружаем значения пикселей.

Gx = [[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]]
Gy = [[1, 2, 1],[0, 0, 0],[-1,-2,-1]]

s = []
rad = int(input())
i = rad+1


def getValues():
    global s1, s2, s3
    s1 = float(
        (pix[i - rad, j - rad][0] * Gx[0][0] + pix[i - rad, j][0] * Gx[0][1] + pix[i - rad, j + rad][0] * Gx[0][2]
         + pix[i, j - rad][0] * Gx[1][0] + pix[i, j][0] * Gx[1][1] + pix[i, j + rad][0] * Gx[1][2]
         + pix[i + rad, j - rad][0] * Gx[2][0] + pix[i + rad, j][0] * Gx[2][1] + pix[i + rad, j + rad][0]) * Gx[2][
            2]) // 3
    s2 = float((pix[i - rad, j - rad][1] * (-1) + pix[i - rad, j][1] * 0 + pix[i - rad, j + rad][1] * 1
                + pix[i, j - rad][1] * (-2) + pix[i, j][1] * 0 + pix[i, j + rad][1] * 2
                + pix[i + rad, j - rad][1] * (-1) + pix[i + rad, j][1] * 0 + pix[i + rad, j + rad][1]) * 1) // 3
    s3 = float((pix[i - rad, j - rad][2] * (-1) + pix[i - rad, j][2] * 0 + pix[i - rad, j + rad][2] * 1
                + pix[i, j - rad][2] * (-2) + pix[i, j][2] * 0 + pix[i, j + rad][2] * 2
                + pix[i + rad, j - rad][2] * (-1) + pix[i + rad, j][2] * 0 + pix[i + rad, j + rad][2]) * 1) // 3

    global l1, l2, l3, G1, G2, G3
    l1 = float(
        (pix[i - rad, j - rad][0] * Gy[0][0] + pix[i - rad, j][0] * Gy[0][1] + pix[i - rad, j + rad][0] * Gy[0][2]
         + pix[i, j - rad][0] * Gy[1][0] + pix[i, j][0] * Gy[1][1] + pix[i, j + rad][0] * Gy[1][2]
         + pix[i + rad, j - rad][0] * Gy[2][0] + pix[i + rad, j][0] * Gy[2][1] + pix[i + rad, j + rad][0]) * Gy[2][
            2]) // 3
    l2 = float((pix[i - rad, j - rad][1] * Gy[0][0] + pix[i - rad, j][1] * Gy[0][1] + pix[i - rad, j + rad][1] * Gy[0][2]
         + pix[i, j - rad][1] * Gy[1][0] + pix[i, j][1] * Gy[1][1] + pix[i, j + rad][1] * Gy[1][2]
         + pix[i + rad, j - rad][1] * Gy[2][0] + pix[i + rad, j][1] * Gy[2][1] + pix[i + rad, j + rad][1]) * Gy[2][
            2]) // 3
    l3 = float((pix[i - rad, j - rad][2] * Gy[0][0] + pix[i - rad, j][2] * Gy[0][1] + pix[i - rad, j + rad][2] * Gy[0][2]
         + pix[i, j - rad][2] * Gy[1][0] + pix[i, j][2] * Gy[1][1] + pix[i, j + rad][2] * Gy[1][2]
         + pix[i + rad, j - rad][2] * Gy[2][0] + pix[i + rad, j][2] * Gy[2][1] + pix[i + rad, j + rad][2]) * Gy[2][
            2]) // 3
    G1 = math.sqrt(s1*s1+l1*l1)
    G2 = math.sqrt(s2 * s2 + l2 * l2)
    G3 = math.sqrt(s3 * s3 + l3 * l3)


while i < width - (rad+1):
    j=rad+1
    while j < height - (rad+1):
        getValues()
        draw.point((i, j), (int(G1), int(G2), int(G3)))
        j += 1
    i += 1
image.save("//home//vlad//Prg//semesrovye//img//imgGauss//lena_sobel.jpg", "JPEG")
del draw