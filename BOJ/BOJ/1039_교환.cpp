#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <queue>
#define MAX 7
using namespace std;

string n;
int k, len;
string nums;
string answers;
vector<set<string>> list;

void init() {
	cin >> n >> k;

	len = n.length();
	list.resize(k);

	nums = n;
}

void myswap(string& str, int l, int r) {
	char tmp = str[l];
	str[l] = str[r];
	str[r] = tmp;
}

void bfs() {
	queue<pair<int, string>> q;
	q.push({ 0, n });

	while (!q.empty()) {
		pair<int, string> now = q.front();
		q.pop();

		if (now.first == k) {
			answers = answers > now.second ? answers : now.second;
			continue;
		}

		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {
				string s = now.second;
				myswap(s, i, j);
				
				if (s[0] == '0') continue;
				if (list[now.first].count(s)) continue;
				list[now.first].insert(s);
				q.push({ now.first + 1, s });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	if (len <= 1) {
		cout << -1;
		return 0;
	}

	bfs();

	if (answers == "") cout << -1;
	else for (int i = 0; i < len; i++) cout << answers[i];
	

	return 0;
}