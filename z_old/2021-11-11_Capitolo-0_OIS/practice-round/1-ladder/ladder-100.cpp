/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i;
int C[MAXN];

int main() {
/// Reindirizza standard input e standard output sui file specificati
/// In pratica: permette di utilizzare cin e cout direttamente da e su file
/// scanf == cin
/// printf == cout
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    assert(1 == scanf("%d", &N));
    for(i=0; i<N; i++)
        assert(1 == scanf("%d", &C[i]));
/// codice equivalente
//  cin >> N;
//  for(i=0; i<N; i++)
//      cin >> C[i];

    // insert your code here
	int R;
	{
		R = C[0];
		cout << "fino a qui tutto bene\n";
		for (i = 1; i < N; i++) {
			int diff = C[i] - C[i - 1];
			cout << "DEBUG: "<<diff<<endl;
			if (diff > R) {
				R = diff;
				cout << "DEBUG: update"<< endl;
			}
		}
	}
    printf("%d\n", R); // print the result
/// codice equivalente
//	cout << R << "\n";
    return 0;
}
