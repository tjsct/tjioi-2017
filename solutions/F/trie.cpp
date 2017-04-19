#include <iostream>
using namespace std;

typedef struct node {
	node* n[26];
	int val = -1;
} node;


int main() {
	int N;
	cin >> N;
	node* root = new node;
	root->val = -1;
	for(int x=0; x<26; x++) root->n[x] = nullptr;

	for(int x=0; x<N; x++) {
		string s; int t;
		cin >> s >> t;
		node* cu = root;
		for(char c : s) {
			if(cu->n[c-'A'] == nullptr) {
				cu->n[c-'A'] = new node;
				cu->n[c-'A']->val = -1;
				for(int i=0; i<26; i++) {
					cu->n[c-'A']->n[i] = nullptr;
				}
			}
			cu = cu->n[c-'A'];
		}
		cu->val = t;
	}
	string s2; cin >> s2;
	node* cu = root;
	long long answer = 0;
	for(char c : s2) {
		cu = cu->n[c-'A'];
		if(cu->val != -1) {
			answer += cu->val;
			cu = root;
		}
	}
	cout << answer;
}

