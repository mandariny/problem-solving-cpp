#include <iostream>
#include <vector>
using namespace std;

int n, k, a, b;
vector<int> scores;

void init() {
	cin >> n >> k;
	scores.push_back(0);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		scores.push_back(x + scores[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	double ans = 0;
	cout.precision(3);
	for (int i = 0; i < k; i++) {
		cin >> a >> b;
		ans = scores[b] - scores[a - 1];
		ans = round(ans / (b - a + 1) * 100) / 100;
		cout << ans << endl;
	}

	cout << fixed;
	cout << ans << endl;

	return 0;
}