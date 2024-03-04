#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> stones;
vector<int> dp;
int start_stone = 2134567890;

void init() {
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		stones.push_back(x);
	}
	dp.resize(n, 1);
}

void get_max_stone(int num) {
	int stone = stones[num];
	for (int i = num - 1; i >= 0; i--) {
		if (stones[i] >= stone) continue;
		dp[num] = max(dp[num], dp[i] + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	// dp[i] = i번째 돌을 밟은 경우의 최대 돌 수 
	for (int i = 1; i < n; i++) {
		get_max_stone(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) ans = max(ans, dp[i]);
	cout << ans;

	return 0;
}