#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;


int N, M;
vector<int> items;
vector<int> prefix;


/**
 * attempt to split items into parts
 * each with maximum component size sz
 * returns true if number of parts <= M
 */
bool test_size(int sz) {
    int pos = 0;
    int m = 0;

    while (m <= M && pos < N) {
        int i = lower_bound(
                prefix.begin() + pos,
                prefix.end(),
                prefix[pos] + sz
            ) - prefix.begin();

        // i is the first item >= sz
        // we want the last item <= sz
        //cerr << i << " " << prefix[i] << " " << (prefix[pos] + sz) << " ";
        if (i == N + 1 || prefix[i] > prefix[pos] + sz) {
            //cerr << "SUB" << endl;
            assert(i != pos);
            i--;
        } else {
            //cerr << "EQUAL?" << endl;
        }

        // element size is greater than sz!
        if (i == pos) {
            //cerr << "FALSE: el size (" << items[pos]
            //     << ") > sz (" << sz << ")" << endl;
            return false;
        }

        //cerr << "i = " << i << endl;
        //cerr << "sum is: " << prefix[i] << endl;
        pos = i;
        m++;
    }

    //cerr << "returning: m (" << m << ") -> " << (m <= M) << endl;
    return m <= M;
}


int main(void) {
    cin >> N >> M;

    int acc = 0;
    for (int i = 0; i < N; i++) {
        // read in values
        int val; cin >> val;
        items.push_back(val);

        // make prefix array
        // (item i is sum of 0..i inclusive)
        prefix.push_back(acc);
        acc += val;
    }

    // element N is the sum
    prefix.push_back(acc);


    int lo = 1, hi = prefix[N];
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        //cerr << "lo: " << lo << ", hi: " << hi
        //     << ", testing: " << mid << endl;

        // A[mid] >= val
        if (test_size(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << endl;
    return 0;
}

