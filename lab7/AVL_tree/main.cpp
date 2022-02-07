#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int key;
    int balance;
    int height;
    Node* left;
    Node* right;
};

int Balance(Node *V) {
    int left_height;
    int right_height;
    if (V == NULL) {
        return 0;
    } else {
        left_height = Balance(V->left);
        right_height = Balance(V->right);
        V->balance = right_height - left_height;
        if (left_height > right_height) {
            V->height = left_height + 1;
        } else {
            V->height = right_height + 1;
        }
        return V->height;
    }

};
int main() {
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
    int N;
    int K, L, R;
    cin >> N;
    vector <Node> tree(N);
    for (int i = 0; i < N; i++) {
        cin >> K >> L >> R;
        tree[i].key = K;
        if (!L) {
            tree[i].left = NULL;
        } else {
            tree[i].left = &tree[L - 1];
        }
        if (!R) {
            tree[i].right = NULL;
        } else {
            tree[i].right = &tree[R - 1];
        }
        tree[i].height = 0;
        tree[i].balance = 0;
    }
    Balance(&tree[0]);
    for (int i = 0; i < N; i++)
    {
        cout << tree[i].balance << endl;
    }
    return 0;
}
