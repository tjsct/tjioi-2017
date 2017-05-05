import java.util.*;
import java.io.*;
import java.math.*;

class larryopoly {
    static int N, M;
    static int[] A = new int[100];
    static int[] dp = new int[1_000_001];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();

        int[] bills = new int[N];
        int max_val = 0;
        for (int i = 0; i < N; i++) {
            bills[i] = sc.nextInt();
            max_val += bills[i];
        }

        // initialize dp array
        int[] dp = new int[max_val + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;

        // process dp
        for (int i = 0; i < N; i++) {
            for (int j = max_val - bills[i]; j >= 0; j--) {
                if (dp[j] != -1 && dp[j] + 1 > dp[j + bills[i]]) {
                    dp[j + bills[i]] = dp[j] + 1;
                }
            }
        }

        // answer queries
        for (int i = 0; i < M; i++) {
            int x = sc.nextInt();
            System.out.println(dp[x]);
        }
    }
}
