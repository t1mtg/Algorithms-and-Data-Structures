#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> heap;

void sift_up(int i) {
    if (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[i].second < heap[parent].second) {
            swap(heap[i], heap[parent]);
            sift_up(parent);
        }
    }
}
void sift_down(int i) {
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int min;
    if (left_child < heap.size() && right_child < heap.size()) {
        if (heap[left_child].second < heap[right_child].second) {
            min = left_child;
        } else {
            min = right_child;
        }
    } else if (left_child < heap.size()) {
        min = left_child;
    } else if (right_child < heap.size()) {
        min = right_child;
    } else {
        return;
    }
    if (heap[i].second > heap[min].second) {
        swap(heap[i], heap[min]);
        sift_down(min);
    }
}

void insert(pair<int, int> a) {
    heap.push_back(a);
    sift_up(heap.size() - 1);
}

int extract_min() {
    if (heap.size() == 0) {
        return INT_MAX;
    }
    int min = heap[0].second;
    heap[0].second = INT_MAX;
    sift_down(0);
    return min;
}

void decrease_key(pair <int,int> a) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i].first == a.first) {
            heap[i] = a;
            sift_up(i);
            break;
        }
    }
}


int main() {
    freopen("priorityqueue.in","r", stdin);
    freopen("priorityqueue.out","w", stdout);
    string s;
    int count = 0;
    while (cin >> s) {
        count++;
        if (s == "push") {
            int temp;
            cin >> temp;
            insert(make_pair(count, temp));
        } else if (s == "extract-min") {
            int temp = extract_min();
            if (temp == INT_MAX) {
                cout << '*' << endl;
            } else {
                cout << temp << endl;
            }
        } else if (s == "decrease-key") {
            int num1, num2;
            cin >> num1 >> num2;
            decrease_key(make_pair(num1, num2));
        }
    }
    return 0;
}
