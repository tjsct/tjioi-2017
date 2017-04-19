#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
  ifstream fin ("F.in");
  ofstream fout("F.out");
  
  int n;
  unordered_map<string, int> candies;
  fin >> n;
  for (int i = 0; i < n; i++) {
    int sugar;
    string name;
    fin >> name >> sugar;
    candies[name] = sugar;
  }
  string receipt;
  fin >> receipt;
  
  string str = "";
  int count = 0;
  for (int i = 0; i < receipt.size(); i++) {
    str += receipt[i];
    if (candies.find(str) != candies.end()) {
      count += receipt[str];
      str = "";
    }
  }
  
  fout << count << endl;
  fout.close();
  
  return 0;
}
