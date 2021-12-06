// https://www.hackerrank.com/challenges/deque-stl/problem?isFullScreen=true

#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> dq;
    dq.push_back(0);
    int i = 0;
    for (; i < k; i++) {
        while (!dq.empty() && arr[i] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(arr[i]);
    }
    cout << dq.front();
    for (; i < n; i++) {
        if (arr[i - k] == dq.front()) {
            dq.pop_front();
        }
        while (!dq.empty() && arr[i] > dq.back()) {
            dq.pop_back();
        }
        dq.push_back(arr[i]);
        cout << " " << dq.front();
    }
    cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

