#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int x = 0; x <= N; x++) {
        if (x * (x+1) / 2 >= N) {
            cout << x << endl;
            break;
        }
    }
}
