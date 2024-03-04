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
		// t문자열 찾기
		for (int i = 0; i < t_len; i++) {
			while (1) {
				// 더이상 해당 문자를 찾을 수 없는 경우 종료
				if (v[t[i] - 'a'].size() == 0) {
					flag = 1;
					break;
				}
				// t에 사용할 문자의 index를 가져옴
				int next = v[t[i] - 'a'].front();
				v[t[i] - 'a'].pop_front();

				// 이전 글자보다 뒤에 나온 글자일 경우 사용 가능
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