import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    public static int[] memo;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        memo = new int[n + 1];
        System.out.println(topDown(n));
    }

    public static int topDown(int n) {

        if (n == 0 || n == 1 || n == 2) {
            return n;
        } else {
            if (memo[n] > 0) {
                return memo[n];
            }
            memo[n] = topDown(n - 1) + topDown(n - 2);

            return memo[n] % 10007;
        }
    }
}
