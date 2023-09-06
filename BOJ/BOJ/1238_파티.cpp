#include <iostream>
#include <queue>
#include <vector>
#define MAX_CITY_NUM 1001
using namespace std;

// N개의 마을에서 X번 마을로 가는 최단 거리 -> N번의 dijkstra
// X번 마을에서 N개의 마을로 가는 최단 거리 -> 1번의 dijkstra

struct road {
	int city_num;
	int weight;
};

struct compare {
	bool operator() (const road& r1, const road& r2) {
		return r1.weight > r2.weight;
	}
};

int n, m, x;
int n_to_x[MAX_CITY_NUM];
int x_to_n[MAX_CITY_NUM];
vector<vector<road>> path(MAX_CITY_NUM);

void init() {
	cin >> n >> m >> x;
	for (int i = 0; i < m; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		path[start].push_back({ end, weight });
	}
}

void get_n_to_x_time(int start) {
	int dist[MAX_CITY_NUM];
	for (int i = 0; i <= n; i++) dist[i] = 2134567890;
	dist[start] = 0;
	priority_queue<road, vector<road>, compare> pq;
	pq.push({ start, dist[start] });

	bool visited[MAX_CITY_NUM] = { 0 };

	while (!pq.empty()) {
		road now = pq.top();
		pq.pop();

		if (visited[now.city_num]) continue;

		visited[now.city_num] = true;

		if (now.city_num == x) break;

		for (road r : path[now.city_num]) {
			if (dist[r.city_num] > now.weight + r.weight) {
				dist[r.city_num] = now.weight + r.weight;
				pq.push({ r.city_num, dist[r.city_num] });
			}
		}
	}

	n_to_x[start] = dist[x];
}

void get_x_to_n_time() {
	int dist[MAX_CITY_NUM];
	for (int i = 0; i <= n; i++) dist[i] = 2134567890;
	dist[x] = 0;
	priority_queue<road, vector<road>, compare> pq;
	pq.push({ x, dist[x] });

	bool visited[MAX_CITY_NUM] = { 0 };

	while (!pq.empty()) {
		road now = pq.top();
		pq.pop();

		if (visited[now.city_num]) continue;

		visited[now.city_num] = true;

		for (road r : path[now.city_num]) {
			if (dist[r.city_num] > now.weight + r.weight) {
				dist[r.city_num] = now.weight + r.weight;
				pq.push({ r.city_num, dist[r.city_num] });
			}
		}
	}

	for (int i = 0; i <= n; i++) {
		x_to_n[i] = dist[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		get_n_to_x_time(i);
	}

	get_x_to_n_time();

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		int t = n_to_x[i] + x_to_n[i];
		ans = ans < t ? t : ans;
	}

	cout << ans;

	return 0;
}