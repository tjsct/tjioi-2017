#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, temp;
    vector<int> pencils;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pencils.push_back(temp);
    }
    sort(pencils.begin(), pencils.end());

    int sum = 0;
    for (int i = n-1; i >= n-k; i--)
        sum += pencils[i];

    cout << sum << endl;
    return 0;
}
