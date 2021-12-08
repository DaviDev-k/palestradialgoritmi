#include <bits/stdc++.h>

using namespace std;

struct my_comparator {
	bool operator()(int a, int b) const {
		if (a % 2 != b % 2) { return a % 2; }
		return a < b;
	}
};

int main() {
	priority_queue<int> max_pq;
	priority_queue<int, vector<int>, greater<int> > min_pq;
	priority_queue<int, vector<int>, my_comparator> cmp_pq;
	for (int i = 0; i < 10; i++) {
		max_pq.push(i);
		min_pq.push(i);
		cmp_pq.push(i);
	}
	while (!max_pq.empty()) {
		cout << max_pq.top() << " ";
		max_pq.pop();
	}
	cout << endl;
	while (!min_pq.empty()) {
		cout << min_pq.top() << " ";
		min_pq.pop();
	}
	cout << endl;
	while (!cmp_pq.empty()) {
		cout << cmp_pq.top() << " ";
		cmp_pq.pop();
	}
	cout << endl;
	
	priority_queue <pair<int, string>> pair_pq;
	pair_pq.push({1, "Qua"});
	pair_pq.push({3, "Qui"});
	pair_pq.push({2, "Quo"});
	while (!pair_pq.empty()) {
		cout << pair_pq.top().first << ":" << pair_pq.top().second << "  ";
		pair_pq.pop();
	}
}
