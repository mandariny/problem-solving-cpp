#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
int cave[130][130];
int dist[130][130];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

struct node {
	int x, y;
	int rupee;
};

struct cmp {
	bool operator () (node n1, node n2) {
		return n1.rupee > n2.rupee;
	}
};

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 2134567890;
		}
	}
}

int dijkstra() {
	priority_queue<node, vector<node>, cmp> pq;

	dist[0][0] = cave[0][0];
	pq.push({ 0, 0, dist[0][0] });

	while (!pq.empty()) {
		node now = pq.top();
		pq.pop();

		if (now.x == n - 1 && now.y == n - 1) return now.rupee;

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] <= now.rupee + cave[nx][ny]) continue;
			dist[nx][ny] = now.rupee + cave[nx][ny];
			pq.push({ nx, ny, now.rupee + cave[nx][ny] });
		}
	}

	return dist[n - 1][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	int idx = 1;

	while (1) {
		
		cin >> n;

		if (n == 0) break;

		init();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> cave[i][j];
			}
		}

		

		cout << "Problem " << idx << ": " << dijkstra() << "\n";
		idx++;
	}

	return 0;
}