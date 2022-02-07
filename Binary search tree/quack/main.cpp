#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int module = 65536;
vector <string> commands;
vector <int> registers(26);
vector <pair <string, int> > labels;
queue <int> quack;
int cnt_commands = 0;
int cnt_labels = 0;

int move(string label) {
    for (int i = 0; i < cnt_labels; i++) {
        if (labels[i].first == label) {
            return labels[i].second;
        }
    }
}

int main() {
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);
    string command, label;
    int a, b, x;
    char Register;
    bool Continue = true;
    while (cin >> command) {
        commands.push_back(command);
        cnt_commands++;
    }
    for (int i = 0; i < cnt_commands; i++) {
        if (commands[i][0] == ':') {
            labels.push_back(make_pair(commands[i].substr(1), i));
            cnt_labels++;
        }
    }
    int i = 0;
    while (i < cnt_commands) {
        command = commands[i];
        switch(command[0]) {
            case '+':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a + b) & (module - 1);
                quack.push(x);
                break;
            case '-':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a - b) & (module - 1);
                quack.push(x);
                break;
            case '*':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                x = (a * b) & (module - 1);
                quack.push(x);
                break;
            case '/':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                if (!b) {
                    x = 0;
                }
                else {
                    x = (a / b) & (module - 1);
                }
                quack.push(x);
                break;
            case '%':
                a = quack.front();
                quack.pop();
                b = quack.front();
                quack.pop();
                if (!b) {
                    x = 0;
                }
                else {
                    x = (a % b) & (module - 1);
                }
                quack.push(x);
                break;
            case '>':
                Register = command[1];
                x = quack.front();
                quack.pop();
                registers[Register - 'a'] = x;
                break;
            case '<':
                Register = command[1];
                x = registers[Register - 'a'];
                quack.push(x);
                break;
            case 'P':
                if (command.length() == 1) {
                    x = quack.front();
                    quack.pop();
                }
                else {
                    Register = command[1];
                    x = registers[Register - 'a'];
                }
                cout << x << endl;
                break;
            case 'C':
                if (command.length() == 1) {
                    x = quack.front();
                    quack.pop();
                }
                else {
                    Register = command[1];
                    x = registers[Register - 'a'];
                }
                cout << char(x % 256);
                break;
            case ':':
                break;
            case 'J':
                label = commands[i].substr(1);
                i = move(label);
                break;
            case 'Z':
                Register = command[1];
                label = commands[i].substr(2);
                if (!registers[Register - 'a'])
                    i = move(label);
                break;
            case 'E':
                label = commands[i].substr(3);
                if (registers[command[1] - 'a'] == registers[command[2] - 'a'])
                    i = move(label);
                break;
            case 'G':
                label = commands[i].substr(3);
                if (registers[command[1] - 'a'] > registers[command[2] - 'a'])
                    i = move(label);
                break;
            case 'Q':
                Continue = false;
                break;
            default:
                x = atoi(command.c_str());
                quack.push(x);
                break;
        }
        i++;
        if (!Continue) {
            break;
        }
    }
    return 0;
}
