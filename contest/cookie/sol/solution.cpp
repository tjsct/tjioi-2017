#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> st[1000005];
int a[1000005];

int main(){
    int N; cin >> N;
    int Q; cin >> Q;
    for (int i = 0; i < N; i++){
        int num; cin >> num;
        a[i] = num;
        for (int j = 2; j*j <= num; j++){
            if (num % j == 0){
                while (num % j == 0){
                    num /= j;
                }
                st[j].insert(i);
            }
        }
        if (num > 1){
            st[num].insert(i);
        }
    }
    for (int i = 0; i < Q; i++){
        int u; cin >> u;
        if (st[u].empty()){
            cout << -1 << endl;
        }
        else {
            cout << *(st[u].begin()) + 1 << endl;
        }
    }
}
