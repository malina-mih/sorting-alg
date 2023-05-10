#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void merge(int arr[], int l, int m, int r) {
int n1 = m - l + 1;
int n2 = r - m;
int* L = new int[n1];
int* R = new int[n2];
for (int i = 0; i < n1; i++) {
L[i] = arr[l + i];
}
for (int j = 0; j < n2; j++) {
R[j] = arr[m + 1 + j];
}

int i = 0, j = 0, k = l;
while (i < n1 && j < n2) {
if (L[i] <= R[j]) {
arr[k] = L[i];
i++;
}
else {
arr[k] = R[j];
j++;
}
k++;
}
while (i < n1) {
arr[k] = L[i];
i++;
k++;
}
while (j < n2) {
arr[k] = R[j];
j++;
k++;
}
delete[] L;
delete[] R;
}
void mergeSort(int arr[], int l, int r) {
if (l < r) {
int m = l + (r - l) / 2;
mergeSort(arr, l, m);
mergeSort(arr, m + 1, r);
merge(arr, l, m, r);
}
}
int main() {
const int size = 500000;
int* arr = new int[size];
for (int i = 0; i < size; i++) {
arr[i] = rand();
}
clock_t start = clock();
mergeSort(arr, 0, size - 1);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC * 100;
cout << "Execution time: " << duration << " ms" << endl;
delete[] arr;
return 0;

}
