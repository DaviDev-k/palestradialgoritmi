// https://ideone.com/a9StE3

#include <bits/stdc++.h>

constexpr int MAXB = 1e5;

int sushi(int, int const B, std::vector<int> const A) {
	assert(B <= MAXB);
	
	if (B == 0) return 0;
	
	std::bitset<MAXB + 1> K(1);
	int R{1};  // int R = 1;
	
	for (;;) {
		auto K2 = K;
		for (auto const &a: A) K2 |= K2 << (a * R);
		if (K2.test(B)) break;
		R *= 2;
		K = K2;
		if (R > B) return -1;
	}
	
	for (int k{R / 2}; k; k /= 2) {
		auto K2 = K;
		for (auto const &a: A) K2 |= K2 << (a * k);
		if (!K2.test(B)) {
			R |= k;
			K = K2;
		}
	}
	
	return R;
}