import java.util.*;

class puck {
    static int N, K;
    static boolean[][] badPair = new boolean[10][10];

    static int recur(int[] list, int pos, boolean[] used) {
        if (pos == N - 1) {
            if (!badPair[list[N-1]][list[0]]) {
                return 1;
            }
            return 0;
        }

        int count = 0;
        int lastVal = list[pos];

        for (int k = 0; k < N; k++) {
            if (!used[k] && !badPair[lastVal][k]) {
                list[pos+1] = k;
                used[k] = true;

                count += recur(list, pos + 1, used);

                list[pos+1] = -1;
                used[k] = false;
            }
        }

        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        K = sc.nextInt();

        for (int k = 0; k < K; k++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            badPair[a][b] = true;
            badPair[b][a] = true;
        }

        int[] list = new int[10];
        boolean[] used = new boolean[10];
        list[0] = 0;
        used[0] = true;

        System.out.println(recur(list, 0, used));
    }
}
