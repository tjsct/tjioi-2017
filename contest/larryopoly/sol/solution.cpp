#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int A[100];
int dp[1000001];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // initialize dp array
    dp[0] = 0;
    for (int i = 1; i <= 1000000; i++)
        dp[i] = -1;

    // process dp
    for (int i = 0; i < N; i++) {
        for (int j = 1000000; j >= 0; j--) {
            if (dp[j] == -1)
                continue;
            if (j + A[i] <= 1000000)
                dp[j + A[i]] = max(dp[j] + 1, dp[j + A[i]]);
        }
    }

    // answer queries
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        cout << dp[x] << endl;
    }
    return 0;
}
