import java.util.Scanner;

public class JepangLee {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int[] arr_0 = new int[41];
        int[] arr_1 = new int[41];

        arr_1[1] = arr_0[0] = 1;
        arr_0[1] = arr_1[0] = 0;

        for (int i = 2; i < 41; i++) {
            arr_0[i] = arr_0[i - 1] + arr_0[i - 2];
            arr_1[i] = arr_1[i - 1] + arr_1[i - 2];
        }

        int a = in.nextInt();
        int[] b = new int[a];

        for (int i = 0; i < a; i++) {
            b[i] = in.nextInt();
        }

        for (int i = 0; i < a; i++) {
            System.out.println(arr_0[b[i]] + " " + arr_1[b[i]]);
        }
    }
}
