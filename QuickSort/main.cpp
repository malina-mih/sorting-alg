#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
int partition(int a[], int l, int r) {
int x = a[l];
int i = l-1;
int j = r+1;
while (true) {
do {
j--;
} while (a[j] > x);
do {
i++;
} while (a[i] < x);
if (i < j) {
swap(a[i], a[j]);
} else {
return j;
}
}
}
void quickSort(int a[], int l, int r) {
if (l < r)
{
int p = partition(a, l, r);
quickSort(a, l, p);
quickSort(a, p+1, r);
}
}
int main() {
const int SIZE = 500000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++) {
arr[i] = rand() % 1000000;
}
clock_t start = clock();
quickSort(arr, 0, SIZE-1);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
cout << "Execution time for Quick Sort: " << duration * 1000 << " ms" << endl;
return 0;
}
