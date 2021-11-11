/*
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

#define INF 2000000000

// input data
int N, M = 1;
vector<int> H;

int cost(int delta) {
    return delta*delta;
}

int dp(bool direction) {
    vector<int> dp(M+1);
    for (int i=0; i<N; ++i) {
        for (int h=0; h<=M; ++h)
            dp[h] += cost(h-H[i]);
        if (i%2 xor direction) {
            for (int h=1; h<=M; ++h)
                dp[h] = min(dp[h], dp[h-1]);
            if (i == N-1) return dp[M];
            for (int h=M; h>0; --h)
                dp[h] = dp[h-1];
            dp[0] = INF;
        } else {
            for (int h=M-1; h>=0; --h)
                dp[h] = min(dp[h], dp[h+1]);
            if (i == N-1) return dp[0];
            for (int h=0; h<M; ++h)
                dp[h] = dp[h+1];
            dp[M] = INF;
        }
    }
    assert(false);
    return -1;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  ifstream cin("input.txt");
//  ofstream cout("output.txt");

    cin >> N;
    H.resize(N);
    for (int i=0; i<N; i++)
        cin >> H[i];

    for (int h : H)
        M = max(M, h);
    cout << min(dp(true), dp(false)) << endl; // print the result
    return 0;
}
