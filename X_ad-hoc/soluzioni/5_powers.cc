#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (a % 2 == 1 || (a % 4 == 0 && b > 1)) {
		cout << 0 << endl;
	} else {
		cout << a / 2 << endl;
	}
	return 0;
}
