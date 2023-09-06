#include <iostream>
#include <queue>
using namespace std;

int n, m;
int map[15][15];
struct person {
	int goal_x;
	int goal_y;
	int x;
	int y;
	bool goal = false;
};
person people[30];

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> people[i].goal_x >> people[i].goal_y;
		people[i].goal_x--;
		people[i].goal_y--;
	}
}

bool is_all_in_goal() {
	return true;
}

bool move_to(int idx) {
	return false;
}

void calc_distance(int idx) {
	
}

void find_basecamp(int idx) {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();

	int t = 0;
	while (true) {
		if (is_all_in_goal()) break;

		for (int i = 0; i < m; i++) {
			if (t <= i) break;
			if (move_to(i)) {
				for (int j = 0; j < m; j++) {
					if (t <= j)break;
					calc_distance(j);
				}
			}
		}

		if (t < m) {
			find_basecamp(t);
			for (int i = 0; i < m; i++) {
				if (t <= i)break;
				calc_distance(i);
			}
		}

		t++;
	}

	cout << t;

	return 0;
}