#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
void radixSort(int arr[], int n, int exp)
{
int output[n];
int count[10] = {0};
for (int i = 0; i < n; i++)
count[(arr[i] / exp) % 10]++;
for (int i = 1; i < 10; i++)
count[i] += count[i-1];
for (int i = n - 1; i >= 0; i--)
{
output[count[(arr[i] / exp) % 10] - 1] = arr[i];
count[(arr[i] / exp) % 10]--;
}
for (int i = 0; i < n; i++)
arr[i] = output[i];
}
void radixSortWrapper(int arr[], int n)
{
int max_val = *max_element(arr, arr + n);
for (int exp = 1; max_val / exp > 0; exp *= 10)
radixSort(arr, n, exp);
}
int main() {
const int SIZE = 500000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++) {
arr[i] = rand() % 1000000;
}
clock_t start = clock();
radixSortWrapper(arr, SIZE);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
double milliseconds = (duration - int(duration)) * 1000;
cout << "Execution time: " << milliseconds << " milliseconds";
return 0;
}
