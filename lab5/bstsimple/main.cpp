#include <iostream>
using namespace std;
struct BinTree {
    int Data;
    BinTree *Left;
    BinTree *Right;
};

BinTree* insert(int Data, BinTree *&x) {
    if (x == NULL) {
        x = new BinTree;
        x -> Data = Data;
        x -> Left = NULL;
        x -> Right = NULL;
    } else {
        if (x -> Data > Data) {
            insert(Data, x -> Left);
        } else if (x -> Data < Data){
            insert(Data, x -> Right);
        }
    }
}




bool exists(int data, BinTree *x) {
    if (x == NULL) {
        return false;
    }
    if (data == x -> Data) {
        return true;
    }
    if (data < x -> Data) {
        return exists(data, x -> Left);
    } else {
        return exists(data, x -> Right);
    }
}

BinTree* minimum(BinTree *&x) {
    if (x -> Left == NULL) {
        return x;
    }
    return minimum(x -> Left);
}

BinTree maximum(BinTree *x) {
    if (x -> Right == NULL) {
        return *x;
    }
    return maximum(x -> Right);
}


BinTree* next(int data, BinTree *&x) {
    BinTree *current = x;
    BinTree *successor = NULL;
    while (current != NULL) {
        if (current -> Data > data) {
            successor = current;
            current = current -> Left;
        } else {
            current = current -> Right;
        }
    }
    return successor;
}

BinTree *prev(int data, BinTree *&x) {
    BinTree *current = x;
    BinTree *previous = NULL;
    while (current != NULL) {
        if (current -> Data < data) {
            previous = current;
            current = current -> Right;
        } else {
            current = current -> Left;
        }
    }
    return previous;
}

BinTree *Delete(BinTree *&x, int data) {
    if (x == NULL)  {
        return x;
    }
    if (data < x -> Data) {
        x -> Left = Delete(x -> Left, data);
    } else if (data > x -> Data) {
        x -> Right = Delete(x -> Right, data);
    } else if (x -> Left != NULL && x -> Right != NULL) {
        x -> Data = minimum(x -> Right)->Data;
        x -> Right = Delete(x -> Right, x -> Data);
    } else {
        if (x -> Left != NULL) {
            x = x -> Left;
        } else if (x -> Right != NULL) {
            x = x -> Right;
        } else
            x = NULL;
    }
    return x;
}

int main() {
    freopen("bstsimple.in", "r", stdin);
    freopen("bstsimple.out", "w", stdout);
    BinTree* Tree = 0;
    string instruction;
    int x;
    while (cin >> instruction) {
        if (instruction == "insert") {
            cin >> x;
            insert(x, Tree);
        } else if (instruction == "exists") {
            cin >> x;
            cout << (exists(x, Tree) ? "true" : "false") << endl;
        } else if (instruction == "delete") {
            cin >> x;
            Tree = Delete(Tree, x);
        } else if (instruction == "next") {
            cin >> x;
            BinTree *temp = next(x, Tree);
            if (temp == NULL) {
                cout << "none" << endl;
            } else {
                cout << temp -> Data << endl;
            }
        } else if (instruction == "prev") {
            cin >> x;
            BinTree *temp = prev(x, Tree);
            if (temp == NULL) {
                cout << "none" << endl;
            } else {
                cout << temp -> Data << endl;
            }
        }
    }

    return 0;
}