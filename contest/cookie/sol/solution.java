import java.util.*;

class cookie {
    private static ArrayList<Integer> getFactors(int n) {
        ArrayList<Integer> out = new ArrayList<>();
        if (n % 2 == 0) {
            out.add(2);
            while (n % 2 == 0)
                n /= 2;
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                out.add(i);
                while (n % i == 0)
                    n /= i;
            }
            if (n == 1) {
                break;
            }
        }
        if (n != 1) {
            out.add(n);
        }
        return out;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int N = sc.nextInt(), Q = sc.nextInt();

        int[] A = new int[N];
        HashMap<Integer, Integer> factorMap = new HashMap<>();

        // read values
        for (int i = 0; i < N; i++) {
            A[i] = sc.nextInt();

            ArrayList<Integer> factors = getFactors(A[i]);
            for (int factor : factors) {
                if(!factorMap.containsKey(factor)) factorMap.put(factor, i);
            }
        }

        // read queries
        for (int i = 0; i < Q; i++) {
            int x = sc.nextInt();
            if (factorMap.containsKey(x)) {
                System.out.println(factorMap.get(x) + 1);
            } else {
                System.out.println(-1);
            }
        }
    }
}
