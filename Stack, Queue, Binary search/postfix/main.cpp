#include <iostream>
#include <fstream>
using namespace std;
int top = -1;

void push(int s[], int x) {
    top++;
    s[top] = x;
}

void pop(int s[]) {
    top--;
}

int main() {
    ifstream fin("postfix.in");
    ofstream fout("postfix.out");
    int stack[100];
    string input;
    getline(fin, input);
    int temp;
    for (int i = 0; i < input.size(); i++) {
        if (isdigit(input[i])) {
            push(stack, input[i] - '0');
        } else if (input[i] != ' ') {
            if (input[i] == '*') {
                temp = stack[top - 1] * stack[top];
            }
            if (input[i] == '+') {
                temp = stack[top - 1] + stack[top];
            }
            if (input[i] == '-') {
                temp = stack[top - 1] - stack[top];
            }
            pop(stack);
            pop(stack);
            push(stack, temp);
        }
    }
        fout << stack[0];
    return 0;
}
