import java.util.*;

public class grocery {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), M = sc.nextInt();

		int[] n = new int[N];
		int max1 = 0, sum1 = 0;
		for(int x=0; x<N; x++) {
			n[x] = sc.nextInt();
			max1 = Math.max(max1, n[x]);
			sum1 += n[x];
		}

		int lo = max1, hi = sum1;
		while(lo <= hi) {
			int mid = (lo+hi)/2;
			int t = 0, r = 1;
			for(int i : n) {
				if(i+t > mid) {
					t = i;
					r++;
				} else {
					t += i;
				}
				if(r > M) break;
			}
			if(r > M) lo = mid+1;
			else hi = mid-1;
		}
		System.out.println(lo);
	}
}
