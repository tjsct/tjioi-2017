#include <fstream>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;

int main() {
  int n;
  unordered_map<string, int> candies;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int sugar;
    string name;
    cin >> name >> sugar;
    candies[name] = sugar;
  }
  string receipt;
  cin >> receipt;
  
  string str = "";
  int count = 0;
  for (int i = 0; i < receipt.size(); i++) {
    str += receipt[i];
    if (candies.find(str) != candies.end()) {
      count += candies[str];
      str = "";
    }
  }
  
  cout << count << endl;  
  return 0;
}
