import java.io.*;
import java.util.*;

class hungry {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        final int N = Integer.parseInt(br.readLine());

        int[][] grid = new int[N][N];
        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                grid[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        br.close();

        int[][] dp = new int[N][N];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = N * N * 10;

        dp[0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i > 0)
                    dp[i][j] = Math.min(dp[i][j], dp[i-1][j] + grid[i][j]);
                if (j > 0)
                    dp[i][j] = Math.min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }

        System.out.println(dp[N-1][N-1]);
    }
}

