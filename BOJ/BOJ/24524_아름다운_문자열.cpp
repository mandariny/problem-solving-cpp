#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

string s, t;
int max_cnt;
int s_len, t_len;
vector<deque<int>> v(26);

void init() {
	cin >> s >> t;
	s_len = s.length();
	t_len = t.length();
	for (int i = 0; i < s_len; i++) {
		v[s[i] - 'a'].push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	init();
	
	int flag = 0;
	while (1) {
		int pre = -1;
		// t���ڿ� ã��
		for (int i = 0; i < t_len; i++) {
			while (1) {
				// ���̻� �ش� ���ڸ� ã�� �� ���� ��� ����
				if (v[t[i] - 'a'].size() == 0) {
					flag = 1;
					break;
				}
				// t�� ����� ������ index�� ������
				int next = v[t[i] - 'a'].front();
				v[t[i] - 'a'].pop_front();

				// ���� ���ں��� �ڿ� ���� ������ ��� ��� ����
				if (pre < next) {
					pre = next;
					break;
				}
			}
			if (flag) break;
		}

		if (flag) break;
		else max_cnt++;
	}
	cout << max_cnt;
	
	return 0;
}