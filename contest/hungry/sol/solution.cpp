#include <iostream>
#include <queue>
#include <set>
#include <cstring>
#include <utility>

using namespace std;

int main(void) {
    int N; cin >> N;
    int grid[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    bool seen[N][N];
    memset(seen, 0, N * N * sizeof(bool));

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(-grid[0][0], make_pair(0, 0)));

    while (!pq.empty()) {
        pair<int, pair<int, int>> item = pq.top();
        pq.pop();

        int cost = -item.first;  // negative bc max heap
        pair<int, int> loc = item.second;

        // avoid processing more than once
        if (seen[loc.first][loc.second]) {
            continue;
        }
        seen[loc.first][loc.second] = true;

        // check if we've arrived at the destination
        if (loc.first == N-1 && loc.second == N-1) {
            cout << cost << endl;
            break;
        }

        // check neighbors
        pair<int, int> neighbors[2] = {
            make_pair(loc.first + 1, loc.second    ),
            make_pair(loc.first    , loc.second + 1)
        };

        for (int i = 0; i < 2; i++) {
            pair<int, int> d = neighbors[i];
            if (d.first < N && d.second < N && !seen[d.first][d.second]) {
                int d_cost = cost + grid[d.first][d.second];
                pq.push(make_pair(-d_cost, d));
            }
        }
    }

    return 0;
}
