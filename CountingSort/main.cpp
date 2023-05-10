#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
void countingSort(int arr[], int n, int k)
{
int count[k+1] = {0};
for (int i = 0; i < n; i++)
count[arr[i]]++;
for (int i = 1; i <= k; i++)
count[i] += count[i-1];
int output[n];
for (int i = n-1; i >= 0; i--)
{
output[count[arr[i]]-1] = arr[i];
count[arr[i]]--;
}
for (int i = 0; i < n; i++)
arr[i] = output[i];
}
int main() {
const int SIZE = 500000;
const int K = 1000000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++) {
arr[i] = rand() % K;
}
clock_t start = clock();
countingSort(arr, SIZE, K);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
int milliseconds = int((duration - int(duration)) * 1000);
cout << "Execution time: " << milliseconds << " milliseconds";
return 0;
}
