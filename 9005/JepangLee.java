import java.util.Scanner;

public class JepangLee {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int a;
    a = in.nextInt();
    int[] b = new int[a];
    for (int i = 0; i < a; i++) {
      b[i] = in.nextInt();
    }

    int[] arr = new int[12];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 4;

    for (int i = 3; i < 12; i++) {
      arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
    }

    for (int i = 0; i < a; i++) {
      System.out.println(arr[b[i] - 1]);
    }
  }
}
