#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

const int MAXN = 4000;

int N;
int grid[MAXN][MAXN];
int dp[MAXN][MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = MAXN * MAXN * 10;

    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > 0)
                dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
            if (j > 0)
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
        }
    }

    cout << dp[N-1][N-1] << endl;
    return 0;
}
