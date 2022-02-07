#include <iostream>
#include <fstream>
using namespace std;
int top = -1;

void push(int s[], int x) {
    top++;
    s[top] = x;
}

int pop(int s[]) {
    top--;
    return s[top + 1];
}

int main() {
    ifstream fin("stack.in");
    ofstream fout("stack.out");
    int M;
    fin >> M;
    int s[M];
    char command;
    for (int i = 0; i < M; i++) {
        fin >> command;
        if (command == '+') {
            int x;
            fin >> x;
            push(s, x);
        } else {
            fout << pop(s) << endl;
        }
    }

    return 0;
}
