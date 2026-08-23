#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
Node* insert(Node* root, int value)
{
    if (root == nullptr)
        return new Node(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}
void inorder(Node* root)
{
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
bool search(Node* root, int value)
{
    if (root == nullptr)
        return false;
    if (root->data == value)
        return true;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}
int main()
{
    Node* root = nullptr;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    cout << "Inorder Traversal: ";
    inorder(root);
    int target;
    cout << "\n\nEnter value to search: ";
    cin >> target;
    if (search(root, target))
        cout << "Value found in the BST." << endl;
    else
        cout << "Value not found in the BST." << endl;
    return 0;
}
