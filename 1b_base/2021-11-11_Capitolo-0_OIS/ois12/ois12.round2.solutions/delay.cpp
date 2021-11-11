/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 * NOTE: it is recommended to use this even if you don't
 * understand the following code.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N;
vector<int> S, D;

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N;
    S.resize(N);
    D.resize(N);
    for (int i=0; i<N; i++)
        cin >> S[i];
    for (int i=0; i<N; i++)
        cin >> D[i];

    int j=0;
    for (int i=0; i<N; i++) {
        j = max(j, i-D[i]);
        cout << S[j] << " ";
    }
    cout << endl;
    return 0;
}
