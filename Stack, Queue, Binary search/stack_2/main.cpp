#include <iostream>
using namespace std;
struct stack {
    int top = -1;
    int a[1000000];

    void push(int x) {
        top++;
        a[top] = x;
    }

    int pop() {
        top--;
        return a[top + 1];
    }
};

int main() {
    freopen("stack.in","r", stdin);
    freopen("stack.out","w", stdout);
    int M;
    cin >> M;
    stack s;
    char command;
    for (int i = 0; i < M; i++) {
        cin >> command;
        if (command == '+') {
            int x;
            cin >> x;
            s.push(x);
        } else if (command == '-') {
            cout << s.pop() << endl;
        }
    }
    return 0;
}

