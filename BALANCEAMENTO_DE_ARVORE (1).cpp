#include <bits/stdc++.h>
using namespace std;
#define COUNT 10

struct Node
{
    int data;
    Node *left, *right;
};

void store_nodes(Node *root, vector<Node *> &nodes)
{
    if (root == NULL)
        return;

    store_nodes(root->left, nodes);
    nodes.push_back(root);
    store_nodes(root->right, nodes);
}

Node *build_tree_recursive(vector<Node *> &nodes, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node *root = nodes[mid];

    root->left = build_tree_recursive(nodes, start, mid - 1);
    root->right = build_tree_recursive(nodes, mid + 1, end);

    return root;
}

Node *build_tree(Node *root)
{
    vector<Node *> nodes;
    store_nodes(root, nodes);

    int n = nodes.size();
    return build_tree_recursive(nodes, 0, n - 1);
}

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void pre_order(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    pre_order(node->left);
    pre_order(node->right);
}

void print2DUtil(Node *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << "\n";

    print2DUtil(root->left, space);
}

void print2D(Node *root)
{
    print2DUtil(root, 0);
}

int main()
{
    // Adiciona nós
    Node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);

    printf("Não Balanceada: \n");
    print2D(root);

    root = build_tree(root);

    printf("Balanceada: \n");
    print2D(root);

    return 0;
}