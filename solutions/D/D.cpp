#include <fstream>
#include <vector>
#include <algorithm>

using mamespace std;

int main() {
  ifstream fin ("D.in");
  ofstream fout("D.out");
  
  int n, k, temp;
  vector<int> pencils;
  fin >> n >> k;
  for (int i = 0; i < n; i++) {
    fin >> temp;
    pencils.push_back(temp);
  }
  sort(pencils.begin(), pencils.end());
  
  int sum = 0;
  for (int i = n-1; i >= n-k; i--)
    sum += pencils[i];
  
  fout << sum << endl;
  fout.close()
  
  return 0;
}
