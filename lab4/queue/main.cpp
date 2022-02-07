#include <iostream>
#include <fstream>
using namespace std;
int head = 0;
int tail = 0;

void enqueue(int q[], int x) {
    q[tail] = x;
    tail++;
    }

int dequeue(int q[]) {
    int x = q[head];
    head++;
    return x;
}

int main() {
    ifstream fin("queue.in");
    ofstream fout("queue.out");
    int M;
    fin >> M;
    int q[M];
    char command;
    for (int i = 0; i < M; i++) {
        fin >> command;
        if (command == '+') {
            int x;
            fin >> x;
            enqueue(q, x);
        } else {
            fout << dequeue(q) << endl;
        }
    }

    return 0;
}

