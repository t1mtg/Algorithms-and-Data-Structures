#include <iostream>
#include <fstream>
using namespace std;
int top = -1;
void push(char s[], char x) {
    top++;
    s[top] = x;
}

void pop(char s[]) {
    top--;
}

bool stack_empty(char s[]) {
    return (top == -1);
}

int main() {
    ifstream fin("brackets.in");
    ofstream fout("brackets.out");
    char stack[10000];
    string input;
    while (fin >> input) {
        top = -1;
        bool flag = true;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(' || input[i] == '[') {
                push(stack, input[i]);
            } else {
                if ((input[i] == ')' && stack[top] == '(') || (input[i] == ']' && stack[top] == '[')) {
                    pop(stack);
                } else {
                    flag = false;
                    break;
                }

            }
        }
        if ((flag) && (stack_empty(stack))){
            fout << "YES" << endl;
        } else {
            fout << "NO" << endl;
        }
    }
    fin.close();
    fout.close();
    return 0;
}