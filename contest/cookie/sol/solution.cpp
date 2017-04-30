#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

set<int> st[100005];
int a[100005];

int main(){
    int N; cin >> N;
    int Q; cin >> Q;
    for (int i = 0; i < N; i++){
        int num; cin >> num;
        a[i] = num;
        for (int j = 2; j < 400; j++){
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
        char c; cin >> c;
        if (c == 'T'){
            int u; cin >> u;
            if (st[u].empty()){
                cout << -1 << endl;
            }
            else{
                cout << *(st[u].begin()) + 1 << endl;
            }
        }
        if (c == 'S'){
            int u, v; cin >> u >> v;
            u--; v--;
            int tmp = a[v];
            a[v] = a[u];
            a[u] = tmp;
            int reduced_a_u = a[u]/(__gcd(a[u], a[v]));
            int reduced_a_v = a[v]/(__gcd(a[u], a[v]));
            for (int j = 2; j < 400; j++){
                if (reduced_a_u % j == 0){
                    while (reduced_a_u % j == 0){
                        reduced_a_u /= j;
                    }
                    st[j].erase(v);
                    st[j].insert(u);
                }
                if (reduced_a_v % j == 0){
                    while (reduced_a_v % j == 0){
                        reduced_a_v /= j;
                    }
                    st[j].erase(u);
                    st[j].insert(v);
                }
            }
            if (reduced_a_u > 1){
                st[reduced_a_u].erase(v);
                st[reduced_a_u].insert(u);
            }
            if (reduced_a_v > 1){
                st[reduced_a_v].erase(u);
                st[reduced_a_v].insert(v);
            }
        }
    }
}
