// Esempio didattico dell'utilizzo dei metodi della classe vector

#include <iostream>
#include <vector>

using namespace std;


// STAMPA
template<typename T>  // assaggio di programmazione generica (non capiterà mai di usarlo per risolvere un problema)
void print_vector(vector<T> &v) {
	cout << "[ ";
	for (auto &item : v) {  // iterazione "automatica" su tutti gli elementi del contenitore (aka foreach)
		cout << item << " ";
	}
	cout << "] : " << v.size() << endl;
}


int main() {
	
	cout << "\n== COSTRUTTORI ==\n";
	vector<int> vi;
	vector<float> vf(2);
	vector<char> vc(4, 'c');
	
	cout << "\n== PRINT ==\n";
	print_vector(vi);
	print_vector(vf);
	print_vector(vc);
	
	cout << "\n== PUSH & POP BACK ==\n";
	print_vector(vi);
	vi.push_back(8);
	vi.push_back(16);
	vi.push_back(32);
	print_vector(vi);
	vi.pop_back();
	print_vector(vi);
	
	cout << "\n== OFFSET [] ==\n";
	vi[1] = 4;
	vi[8] = 4;  // ATTENZIONE: non vengono controllati i limiti del vettore
	cout << vi[0] << " " << vi[1] << " " << vi[2] << endl;  // ATTENZIONE: vi[2] non è più un elemento del vettore
	print_vector(vi);
	
	cout << "\n== FRONT & BACK ==\n";
	vi.push_back(2);
	print_vector(vi);
	cout << "front = " << vi.front() << endl;
	cout << "back = " << vi.back() << endl;
	
	cout << "\n== EMPTY & CLEAR ==\n";
	print_vector(vi);
	cout << (vi.empty() ? "empty" : "not empty") << endl;
	vi.clear();
	cout << (vi.empty() ? "empty" : "not empty") << endl;
	print_vector(vi);
	
	cout << "\n== RESIZE ==\n";
	vi.push_back(2);
	print_vector(vi);
	vi.resize(4, 4);
	print_vector(vi);
	vi.resize(6);
	print_vector(vi);
	vi.resize(2, 2);
	print_vector(vi);
	
	cout << endl;
	return 0;
}
