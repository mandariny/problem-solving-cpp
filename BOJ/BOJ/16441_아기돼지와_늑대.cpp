#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
char map[101][101];
int visited[101][101];
queue <pair<int, int>> q;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'W') {
				visited[i][j] = 1;
				q.push({ i, j });
			}
		}
	}
}

void bfs() {
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];

			// 범위 밖, 산, 들른 곳은 갈 수 없음
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] == '#') continue;
			if (visited[nx][ny]) continue;
			if (map[nx][ny] == '.') {
				q.push({ nx, ny });
				visited[nx][ny] = 1;
			}
			else if (map[nx][ny] == '+') {
				while (1) {
					int nnx = nx + dx[i];
					int nny = ny + dy[i];

					if (map[nnx][nny] == '.') {
						if (visited[nnx][nny]) break;
						q.push({ nnx, nny });
						visited[nnx][nny] = 1;
						break;
					}
					else if (map[nnx][nny] == '#') {
						if (visited[nx][ny]) break;
						q.push({ nx, ny });
						visited[nx][ny] = 1;
						break;
					}
					nx = nnx;
					ny = nny;
				}
			}
		}
	}
}

void printAnswers() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '.' && !visited[i][j]) cout << "P";
			else cout << map[i][j];
		}

		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	bfs();
	printAnswers();

	return 0;
}