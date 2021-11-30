// as bnb_quantum, but compute exact bounds from every position

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// input data
int N, L, bt = 0;
vector<int> X, E, res, bv, bound;

const vector<int> digits = {9, 3, 1, 8, 4, 2, 6, 7, 5};
vector<int> digit_sets;
bool ok[10][10];

void compute_sets() {
    digit_sets.resize(L);
    int mask[10] = {0, 1022, 342, 586, 278, 34, 78, 130, 278, 522};
    for (int i=0; i<L; ++i) {
        if (res[i] > 0) {
            digit_sets[i] = 1<<res[i];
        } else {
            digit_sets[i] = 1<<1;
            for (int d=2; d<10; ++d)
                if (d <= i and (digit_sets[i-d] & mask[d]) > 0)
                    digit_sets[i] |= 1<<d;
        }
    }
}

void compute_bound(int start, int i, int tot) {
    if (i == L) {
        if (tot > bt) bt = tot;
        return;
    }
    if (res[i] > 0) {
        compute_bound(start, i+1, tot+res[i]);
        return;
    }
    for (int d : digits)
        if (tot + d + bound[i] >= bt and (d > i-start ? (digit_sets[i] & (1<<d)) > 0 : ok[d][res[i-d]])) {
            res[i] = d;
            compute_bound(start, i+1, tot+res[i]);
        }
    res[i] = 0;
}

int compute_bound(int start) {
    compute_bound(start+1, start+1, 0);
    int r = bt;
    bt = 0;
    return r;
}

void best_fill(int i = 0, int tot = 0) {
    if (i == L) {
        if (tot > bt) {
            bt = tot;
            bv = res;
        }
        return;
    }
    if (res[i] > 0) {
        best_fill(i+1, tot+res[i]);
        return;
    }
    for (int d : digits)
        if (tot + d + bound[i] >= bt and d <= i and ok[d][res[i-d]]) {
            res[i] = d;
            best_fill(i+1, tot+res[i]);
        }
    res[i] = 0;
}

int main() {
//  uncomment the following lines if you want to read/write from files
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> N >> L;
    X.resize(N);
    E.resize(N);
    for (int i=0; i<N; i++)
        cin >> X[i];
    for (int i=0; i<N; i++)
        cin >> E[i];

    res.resize(L);
    for (int i=0; i<N; ++i)
        res[X[i]] = E[i];
    for (int i=0; i<10; ++i) {
        for (int j=0; j<10; ++j) {
            if (i==0) ok[i][j] = true;
            else if (j==0) ok[i][j] = false;
            else ok[i][j] = i%j == 0 or j%i == 0;
        }
    }
    compute_sets();
    bound.resize(L);
    for (int i=L-1; i>=0; --i) bound[i] = compute_bound(i);
    best_fill();
    cerr << bt << endl;
    for (int i=0; i<L; ++i)
        cout << bv[i] << " ";
    cout << endl;
    return 0;
}
