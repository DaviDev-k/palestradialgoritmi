// https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true

#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k) {
	
	deque<int> dq;
	dq.push_back(0);  // deque inizializzata ad un valore minimo
	int i = 0;        // iteratore sulla lunghezza dell'array di input
	
	/* Per il primo intervallo di lunghezza k, riempi la dq con valori decrescenti, nell'ordine dell'input */
	for (; i < k; i++) {
		/* `!dq.empty()` evita di estrarre da una deque vuota */
		while (!dq.empty() && arr[i] > dq.back()) { dq.pop_back(); }
		dq.push_back(arr[i]);
	}
	
	cout << dq.front();  // stampa il valore massimo
	
	/* Per i restanti valori dell'input... */
	for (; i < n; i++) {
		
		/* ...togli l'elemento in testa quando "viene sorpassato" */
		if (arr[i - k] == dq.front()) { dq.pop_front(); }
		
		/* ...mantieni la deque ordinata in senso decrescente */
		while (!dq.empty() && arr[i] > dq.back()) { dq.pop_back(); }
		dq.push_back(arr[i]);
		
		cout << " " << dq.front();  // stampa il valore massimo
	}
	cout << endl;
}

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n, k;
		cin >> n >> k;
		int i;
		int arr[n];
		for (i = 0; i < n; i++) { cin >> arr[i]; }
		printKMax(arr, n, k);
		t--;
	}
	return 0;
}

