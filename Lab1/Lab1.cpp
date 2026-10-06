#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // If the tree is empty, return a
                           // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    else if(data == root->data) {
        // If the data is equal to the root's data, insert it as greater value
		root->right = insertNode(root->right, data);
	}

    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST
int inorderTraversalSUM(Node* root,int x)
{
    static int sum = 0;
    if (root != nullptr)
    {
        if (root->data <= x)
            sum += root->data;
        inorderTraversalSUM(root->right,x);
    }
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Main function to demonstrate the operations of BST
int main()
{

    Node* root = nullptr;
    int t,n,q;
    cin >> t;
    while (t--)
    {
        int sum, suma;
        cin >> n >> q;
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            x +=sum;
            sum = x;
            root = insertNode(root, x);
		}
        for (int i = 0; i < q; i++)
        {
            int x;
            cin >> x;
			suma = inorderTraversalSUM(root,x);
            cout << suma << " ";
        }
        cout << endl;
    }

    return 0;
}