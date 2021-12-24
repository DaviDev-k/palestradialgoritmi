// https://open.kattis.com/problems/addingwords

#include <iostream>
#include <bitset>
#include <map>

#define MAX_VALUE 1000
#define MAX_RANGE 2 * MAX_VALUE + 1

using namespace std;

int main(int argc, char **argv) {
	if (argc > 1) { freopen("input.txt", "r", stdin); }
	
	map<string, int> values;
	string ids[MAX_RANGE];
	bitset<MAX_RANGE> bit;
	string cmd, id, op;
	int value;
	while (cin >> cmd) {
		if (cmd == "def") {
			cin >> id >> value;
			if (values.count(id) > 0) { bit.reset(values[id] + MAX_VALUE); }
			values[id] = value;
			ids[value + MAX_VALUE] = id;
			bit.set(value + MAX_VALUE);
		} else if (cmd == "calc") {
			cin >> id >> op;
			cout << id << " " << op << " ";
			int calc;
			bool unk = false;
			if (values.count(id) > 0) { calc = values[id]; }
			else { unk = true; }
			while (op != "=") {
				cin >> id;
				if (!unk && values.count(id) > 0) { calc += ((op == "-") ? -1 : 1) * values[id]; }
				else { unk = true; }
				cin >> op;
				cout << id << " " << op << " ";
			}
			cout << ((unk || calc < -1000 || calc > 1000 ||
			          !bit.test(calc + MAX_VALUE)) ? "unknown" : ids[calc + MAX_VALUE]) << endl;
		} else if (cmd == "clear") {
			values.clear();
			bit &= 0;
		}
	}
	
	return 0;
}

