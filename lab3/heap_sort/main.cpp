#include <iostream>
using namespace std;
void heapify(int array[], int N, int parent) {
    int max = parent;
    int left_child = 2 * parent + 1;
    int right_child = 2 * parent + 2;
    if (left_child < N && array[max] < array[left_child]) {
        max = left_child;
    }
    if (right_child < N && array[max] < array[right_child]) {
        max = right_child;
    }
    if (parent != max) {
        swap(array[parent], array[max]);
        heapify(array, N, max);
    }
};

void heap_sort(int array[], int N) {
    for (int i = N / 2 - 1; i >= 0; i--) {
        heapify(array, N, i);
    }
    for (int i = N - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}
int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    int N;
    cin >> N;
    int array[N];
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    heapify(array, N, 0);
    for (int i = 0; i < N; i++) {
        cout << array[i] << " ";
    }
    return 0;
}
