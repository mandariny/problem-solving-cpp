#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;

vector<int> minus_male;
vector<int> plus_male;
vector<int> minus_female;
vector<int> plus_female;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) minus_male.push_back(x);
		else plus_male.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 0) minus_female.push_back(x);
		else plus_female.push_back(x);
	}

	sort(minus_male.begin(), minus_male.end());
	sort(plus_male.begin(), plus_male.end());
	sort(minus_female.begin(), minus_female.end());
	sort(plus_female.begin(), plus_female.end());
}

int get_pair(vector<int> plus, vector<int> minus) {
	int plus_idx = 0;
	int minus_idx = minus.size() - 1;
	int plus_len = plus.size();
	int cnt = 0;

	while (1) {
		if (plus_idx == plus_len) break;
		if (minus_idx == -1) break;

		int sum = plus[plus_idx] + minus[minus_idx];
		if (sum < 0) {
			cnt++;
			plus_idx++;
			minus_idx--;
		}
		else {
			minus_idx--;
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	cout << get_pair(plus_male, minus_female) + get_pair(plus_female, minus_male);

	return 0;
}