import java.util.Scanner;

public class sem {
    public static void main(String[] args) {
        int innerCount = 0;//число точек, попавших в круг
        double x, y;//координаты
        double p;//результат
        int count = 1000;
        System.out.println("Сколько раз рассчитать число?: ");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < count; i++) {
                x = (Math.random() * 2) - 1;
                y = (Math.random() * 2) - 1;
                if (Math.pow(x, 2) + Math.pow(y, 2) <= 1)
                    innerCount++;
            }
            p = (double) 4 * innerCount / count;
            System.out.println("Сгенерированное число Пи: " + p);
            innerCount = 0;
            count += count;
        }

    }
}
