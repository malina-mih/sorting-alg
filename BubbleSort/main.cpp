#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;
void bubbleSort(int arr[], int n) {
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
swap(arr[j], arr[j + 1]);
}
}
}
}
int main()
{
const int SIZE = 500000;
int arr[SIZE];
for (int i = 0; i < SIZE; i++) {
arr[i] = rand() % 1000000;
clock_t start = clock();
bubbleSort(arr, SIZE);
clock_t end = clock();
double duration = (double)(end - start) / CLOCKS_PER_SEC;
int minutes = (int)duration / 60;
int seconds = (int)duration % 60;
int milliseconds = (int)((duration - (int)duration) * 1000);
cout << "Execution time: " << minutes << " minutes, " << seconds << " seconds, " <<
milliseconds << " milliseconds" << endl;
return 0;
}
}

