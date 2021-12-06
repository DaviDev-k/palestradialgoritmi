/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>
#include <vector>

using namespace std;

// constraints
#define MAXN 10000
#define MAXC 10001

// input data
int N, i;
int X[MAXN], Y[MAXN];

vector<bool> vis;
vector<int> match;

int nX, nY;
vector<vector<int>> adj;

bool aug(int x) {
    if (vis[x]) {
        return false;
    }

    vis[x] = true;

    for (int y : adj[x]) {
        if (match[y] == -1 || aug(match[y])) {
            match[y] = x;
            return true;
        }
    }

    return false;
}
int matching() {
    match.assign(nY, -1);

    int size = 0;
    vis.resize(nX);
    for (int i = 0; i < nX; i++) {
        vis.assign(nX, false);
        if (aug(i)) {
            size++;
        }
    }

    return size;
}



int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(2 == scanf("%d %d", &X[i], &Y[i]));

    vector<int> Xi(MAXC, -1), Yi(MAXC, -1);
    nX = 0; nY = 0;
    for (int i = 0; i < N; i++) {
        if (Xi[X[i]] == -1) {
            Xi[X[i]] = nX++;
        }
        if (Yi[Y[i]] == -1) {
            Yi[Y[i]] = nY++;
        }
    }

    adj.resize(nX);
    for (int i = 0; i < N; i++) {
        adj[Xi[X[i]]].push_back(Yi[Y[i]]);
    }

    printf("%d\n", matching()); // print the result
    return 0;
}
