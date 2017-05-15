#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int st[1000005];

int main(){
    int N; cin >> N;
    int Q; cin >> Q;
    for (int i = 0; i < N; i++){
        int num; cin >> num;
        for (int j = 2; j*j <= num; j++){
            if (num % j == 0){
                while (num % j == 0){
                    num /= j;
                }
                if(!st[j]) st[j] = i+1;
            }
        }
        if (num > 1){
            if(!st[num]) st[num] = i+1;
        }
    }
    for (int i = 0; i < Q; i++){
        int u; cin >> u;
        if (!st[u]) {
            cout << -1 << endl;
        }
        else {
            cout << st[u] << endl;
        }
    }
}
