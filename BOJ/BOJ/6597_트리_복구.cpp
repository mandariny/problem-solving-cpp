#include <iostream>
#include <string>
using namespace std;

/*
�������� ������ root ������
�ο����� ��/�� ������ ���
*/

string preorder;
string inorder;
int idx;

bool init() {
		idx = 0;
		cin >> preorder >> inorder;

		if (cin.eof()) return false;
		return true;
}

void recursion(string str, char value) {
	if (str == "") return;
	
	idx++;
	int pos = str.find(value);
	recursion(str.substr(0, pos), preorder[idx]);
	recursion(str.substr(pos + 1, str.length()), preorder[idx]);

	cout << value;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	while (init()) {
		recursion(inorder, preorder[idx]);
		cout << '\n';
	}

	return 0;
}