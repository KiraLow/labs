from PIL import Image, ImageDraw

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//lena.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
pix = image.load()  # Выгружаем значения пикселей.
i=2
s = []
rad = 3
while i < width - (rad*rad):
    j=rad*rad
    while j < height - (rad*rad):
        s1 = (pix[i - rad, j - rad][0] + pix[i - rad, j][0] + pix[i - rad, j + rad][0] + pix[i, j - rad][0] + pix[i, j][0] +
              pix[i, j + rad][0] + pix[i + rad, j - rad][0] + pix[i + rad, j][0] + pix[i + rad, j + rad][0]) // 9*rad
        s2 = (pix[i - rad, j - rad][rad] + pix[i - rad, j][rad] + pix[i - rad, j + rad][rad] + pix[i, j - rad][rad] + pix[i, j][rad] +
              pix[i, j + rad][rad] + pix[i + rad, j - rad][rad] + pix[i + rad, j][rad] + pix[i + rad, j + rad][rad]) // 9*rad
        s3 = (pix[i - rad, j - rad][2] + pix[i - rad, j][2] + pix[i - rad, j + rad][2] + pix[i, j - rad][2] + pix[i, j][2] +
              pix[i, j + rad][2] + pix[i + rad, j - rad][2] + pix[i + rad, j][2] + pix[i + rad, j + rad][2]) // 9*rad
        draw.point((i, j), (s1, s2, s3))
        j += 1
    i += 1

image.save("//home//vlad//Prg//semesrovye//img//imgGauss//lena_res.jpg", "JPEG")
del draw
