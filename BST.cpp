#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(Node* root, int val){

    if(root == NULL){
        return new Node(val);
    }
    if(val < root-> data){
        root-> left = insertBST(root->left, val);
    }
    else{
        root->right = insertBST(root->right, val);
    }
    return root;
}

void inorder(Node* root){  //will be sorted.
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//balanced BST: height of left and right subtree <=1
Node* BuildBSTFromSortedArray(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/ 2;
    Node* root = new Node(arr[mid]);

    root->left = BuildBSTFromSortedArray(arr, start, mid-1);

    root->right = BuildBSTFromSortedArray(arr, mid+1, end);

    return root;

}
int main(){

    Node* root = NULL;
    root = insertBST(root, 5);
    insertBST(root, 1);
    insertBST(root, 3);
    insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);

    int arr[] = {1, 2, 3, 4, 5, 6};

    Node* root = BuildBSTFromSortedArray(arr, 0, 4); //then do the preorder of it
    return 0;
}