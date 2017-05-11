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

        boolean[][] seen = new boolean[N][N];
        PriorityQueue<Location> pq = new PriorityQueue<>();
        pq.add(new Location(grid[0][0], 0, 0));

        while (!pq.isEmpty()) {
            Location item = pq.remove();

            // avoid processing more than once
            if (seen[item.i][item.j]) {
                continue;
            }
            seen[item.i][item.j] = true;

            // check if we've arrived at the destination
            if (item.i == N-1 && item.j == N-1) {
                System.out.println(item.cost);
                break;
            }

            // check neighbors
            Location[] neighbors = new Location[] {
                new Location(0, item.i + 1, item.j    ),
                new Location(0, item.i    , item.j + 1)
            };

            for (Location d : neighbors) {
                if (d.i < N && d.j < N && !seen[d.i][d.j]) {
                    d.cost = item.cost + grid[d.i][d.j];
                    pq.add(d);
                }
            }
        }
    }

    private static class Location implements Comparable<Location> {
        int cost;
        int i;
        int j;

        public Location(int cost, int i, int j) {
            this.cost = cost;
            this.i = i;
            this.j = j;
        }

        @Override
        public int compareTo(Location other) {
            return cost - other.cost;
        }
    }

}
