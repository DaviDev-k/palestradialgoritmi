#include <assert.h>
#include <iostream>
#include <stdio.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int V[MAXN];
int state[MAXN]; // -1 = unexplored, -2 = closed, >= 0 distance from source
int sol;

void dfs(int u, int d) {
  if (state[u] == -2)
    return;
  if (state[u] >= 0) {
    sol = std::max(sol, d - state[u]);
    return;
  }
  state[u] = d;
  dfs(V[u], d + 1);
  state[u] = -2;
}

int main() {
  assert(1 == scanf("%d", &N));
  for (i = 0; i < N; i++) {
    assert(1 == scanf("%d", &V[i]));
    state[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    dfs(i, 0);
  }
  std::cout << sol << std::endl;
  return 0;
}
