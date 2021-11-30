// Precomputes positions for each letter. Then, in a greedy approach, tries to
// put the N-K required letters choosing each time the highest one (i.e., from 'z' to 'a')
// that still has a position in the original passphrase that allows to place the remaining
// letters.

#include <iostream>
#include <list>
#include <string>

using namespace std;

int N, K;
string passphrase;
string solution;
list<int> positions[26];

int main() {
    cin >> N >> K;
    cin >> passphrase;

    for (int i = 0; i < passphrase.length(); i++)
        positions[passphrase[i] - 'a'].push_back(i);

    int reached_position = -1;
    for (int to_place = N - K; to_place > 0; to_place--) {
        bool done = false;
        for (char c = 'z'; c >= 'a' && !done; c--) {
            while (positions[c - 'a'].size() > 0 && positions[c - 'a'].front() <= reached_position) {
                positions[c - 'a'].pop_front();
            }
            if (positions[c - 'a'].size() > 0) {
                int pos = positions[c - 'a'].front();
                if (N - 1 - pos >= to_place - 1) {
                    solution += c;
                    reached_position = pos;
                    done = true;
                }
            }
        }
    }

    cout << solution << endl;
    return 0;
}
