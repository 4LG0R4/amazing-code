import java.util.Scanner;

import static java.lang.Integer.min;

public class jepanglee {

  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);

    int n = 0;
    n = in.nextInt();

    int[] arr = new int[1000001];

    arr[0] = 0;
    arr[1] = 0;

    for (int i = 2; i <= n; i++) {
      arr[i] = arr[i - 1] + 1;
      if (i % 2 == 0) {
        arr[i] = min(arr[i], arr[i / 2] + 1);
      }
      if (i % 3 == 0) {
        arr[i] = min(arr[i], arr[i / 3] + 1);
      }
    }

    System.out.println(arr[n]);
  }
}
