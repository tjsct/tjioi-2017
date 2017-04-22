#include <iostream>

using namespace std;

int N, K;
int count = 0;
int A [10][10];
int B[10];
int C [10];

void recur(int n) {
	if (n == N) {
		if (A[B[0]][B[N-1]] == 0)
			count++;
	} else {
		for (int i = 0; i < N; i++) {
			if (C[i] == 0 && A[i][B[n-1]] == 0) {
				B[n] = i;
				C[i] = 1;
				recur(n+1);
				C[i] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> K;
	
	for (int i = 0; i < 10; i++) {
		B[i] = 0;
		C[i] = 0;
		for (int j = 0; j < 10; j++)
			A[i][j] = 0;
	}

	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		A[a][b] = 1;
		A[b][a] = 1;
	}
	B[0] = 0;
	C[0] = 1;
	recur(1);
	
	cout << count << endl;
	return 0;
}
