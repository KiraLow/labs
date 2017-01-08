from PIL import Image, ImageDraw

image = Image.open("//home//vlad//Prg//semesrovye//img//imgGauss//python//lena.jpg")  # Открываем изображение.
draw = ImageDraw.Draw(image)  # Создаем инструмент для рисования.
width = image.size[0]  # Определяем ширину.
height = image.size[1]  # Определяем высоту.
pix = image.load()  # Выгружаем значения пикселей.
print("Количество проходов")
n = int(input())
l = 0
for l in range(n):
    i = 2
    s = []
    while i < width - 2:
        j=2
        while j < height - 2:
            s1 = (pix[i - 1, j - 1][0] + pix[i - 1, j][0] + pix[i - 1, j + 1][0] +
                  pix[i, j - 1][0] + pix[i, j][0] + pix[i, j + 1][0] +
                  pix[i + 1, j - 1][0] + pix[i + 1, j][0] + pix[i + 1, j + 1][0]) // 9
            s2 = (pix[i - 1, j - 1][1] + pix[i - 1, j][1] + pix[i - 1, j + 1][1] +
                  pix[i, j - 1][1] + pix[i, j][1] + pix[i, j + 1][1] +
                  pix[i + 1, j - 1][1] + pix[i + 1, j][1] + pix[i + 1, j + 1][1]) // 9
            s3 = (pix[i - 1, j - 1][2] + pix[i - 1, j][2] + pix[i - 1, j + 1][2] +
                  pix[i, j - 1][2] + pix[i, j][2] + pix[i, j + 1][2] +
                  pix[i + 1, j - 1][2] + pix[i + 1, j][2] + pix[i + 1, j + 1][2]) // 9
            draw.point((i, j), (s1, s2, s3))
            j += 1
        i += 1

image.save("//home//vlad//Prg//semesrovye//img//imgGauss//python//lena_res.jpg", "JPEG")
del draw
