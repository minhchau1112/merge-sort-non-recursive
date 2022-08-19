#include<iostream>
using namespace std;

void Merge(int* a, int l, int mid, int r, int* b) {
	int i = l, j = mid;
	for (int z = l; z < r; z++) {
		if ((i < mid) && ((j >= r) || a[i] <= a[j])) {
			b[z] = a[i];
			i++;
		}
		else {
			b[z] = a[j];
			j++;
		}
	}
	for (int k = l; k < r; k++) {
		a[k] = b[k];
	}
}
void MergeSort_NonRecusive(int* a, int n, int* b) {
	for (int curr = 1; curr <= n - 1; curr = 2 * curr) {
		for (int ltemp = 0; ltemp < n - 1; ltemp += 2 * curr) {
			int mid = min(ltemp + curr, n);
			int rtemp = min(ltemp + 2 * curr, n);
			Merge(a, ltemp, mid, rtemp, b);
		}
	}
}int main() {	int* a, * b;	int n;	cout << "Enter the number of elements : ";	cin >> n;	a = new int[n];	b = new int[n];	for (int i = 0; i < n; i++) {		cout << "a[" << i << "] = ";		cin >> a[i];	}	MergeSort_NonRecusive(a, n, b);	for (int i = 0; i < n; i++) {		cout << a[i]<< " ";	}	return 0;}