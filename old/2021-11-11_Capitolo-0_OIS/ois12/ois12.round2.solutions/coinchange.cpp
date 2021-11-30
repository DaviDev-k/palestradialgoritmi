// insert brief description of the solution here

#include <assert.h>
#include <stdio.h>

// input data
long long V[15];

int main() {
  //  uncomment the following lines if you want to read/write from files
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

  for (int i = 0; i < 15; i++)
    assert(1 == scanf("%lld", &V[i]));

  long long val = 0;
  long long coins[] = {1,   2,    5,    10,   20,    50,    100,  200,
                       500, 1000, 2000, 5000, 10000, 20000, 50000};

  for (int i = 0; i < 15; i++)
    val += coins[i] * V[i];

  long long sol[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 14; i >= 0; i--) {
    sol[i] = val / coins[i];
    val -= sol[i] * coins[i];
  }

  for (int i = 0; i < 15; i++)
    printf("%lld ", sol[i]);
  printf("\n");
  return 0;
}
