#include<queue>
#include<iostream>
#include<vector>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left= NULL;
        right= NULL;
    }

};

void preorder(struct Node* root){
    if(root== NULL)
        return;
    cout<<root->data<<" ";
    preorder(root-> left);
    preorder(root-> right);

}
void inorder(struct Node* root){
    if(root== NULL)
        return;
    inorder(root-> left);
    cout<<root->data<<" ";
    inorder(root-> right);

}

void leverOrder(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> queue;  //stores node
    queue.push(root->data);
    queue.push(NULL); //to mark the end of a level

    while(!queue.empty()){
        Node* node = queue.front();
        queue.pop();
        if(node != NULL){
            cout<<node->data<<" ";
            if(node-> left)
            queue.push(node-> left);
            if(node-> right)
            queue.push(node-> right);
        }
        else if(!queue.empty() && node == NULL) //marking end of level when we still have elements in queue
            queue.push(NULL);
    }
}
int sumAtlevelK(Node* root, int k){
    if(root == NULL){
        return -1;
    }
    if(k == 0){
        return root->data;
    }
    queue<Node*> queue;  //stores node
    queue.push(root->data);
    queue.push(NULL); //to mark the end of a level
    int count = 0;
    int sum = 0;
    while(!queue.empty()){
        Node* node = queue.front();
        queue.pop();
        if(node != NULL){
            if(k == count){
                sum += node->data;
            }
            if(node-> left)
            queue.push(node-> left);
            if(node-> right)
            queue.push(node-> right);
        }
        else if(!queue.empty() && node == NULL) 
            queue.push(NULL);
            count++;
    }
    return sum;
}

int countNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return(countNodes(root-> left) + countNodes(root->right) + 1);
}
int sumOfNodes(Node* root){
    if(root == NULL){
        return 0;
    }
    return(sumOfNodes(root-> left) + sumOfNodes(root->right) + root->data);
}


void rigthView(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> queue;  //stores node
    queue.push(root->data);
    while(!queue.empty()){
        int queueSize = queue.size();
        for(int i = 0; i < queueSize;i++){
            Node* node = queue.front();
            queue.pop();
            if( i == queueSize -1){
                cout<< node->data<< " ";
            }
            if(node -> left){
                queue.push(node->left); 
            }
            if(node -> right){
                queue.push(node->right);
            }
        }
    }
}

int heightOfTree(Node* root){
if(root== NULL){
    return 0;
}
int lefth = heightOfTree(root->left);
int righth = heightOfTree(root->right);

return max(lefth, righth) + 1;
}

int diameter(Node* root){
    if(root== NULL){
    return 0;
}
int lefth = heightOfTree(root->left);
int righth = heightOfTree(root->right);
int currDiamter = lefth+righth + 1;

int leftDiameter = diameter(root->left);
int rightDiameter = diameter(root->right);

return max(currDiamter, max(leftDiameter, rightDiameter));
}
bool getPath(Node* root, int key, vector<int> &path){
    if(root ==NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }

    if(getPath(root->left, key, path) || getPath(root->right, key, path)){
        return true;
    }

    path.pop_back(); //remove the wrong entered element.
    return false;

}

int lca(Node* root, int n1, int n2){
    vector<int> path1;
    vector<int> path2;
    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pathChange;
    for(pathChange=0; pathChange<path1.size() && pathChange< path2.size(); pathChange++){
        if(path1[pathChange] != path2[pathChange]){
            break;
        }
    }
    return path1[pathChange -1];
}


Node* LCA(Node* root, int n1, int n2){
   if(root== NULL){
    return NULL;
   }
   if(root->data == n1 || root-> data == n2){
    return root;
   }

   Node* left = LCA(root->left, n1, n2);
   Node* right = LCA(root->right, n1, n2);

   if(left != NULL && right != NULL){
    return root;
   }
   if(left == NULL && right == NULL){
    return NULL;
   }
   if(left != NULL){
    return LCA(root-> left, n1, n2);
   }
   return LCA(root->right, n1, n2);

}
int getDistance(Node* lca, int key, int dis){
    if(root== NULL){
        return -1;
    }
    if(root->data == key){
        return dis;
    }
    int left = getDistance(root->left, key, dis+1); //as we go down the level distance increases + 1
    if(left != -1){
        return left;
    }
    return getDistance(root->right, key, dis+1);
}
int distBtwNodes(Node* root, int n1, int n2){
    Node* lca = LCA(root, n1, n2);

    int d1 = getDistance(lca, n1 ,0);
    int d2 = getDistance(lca, n2 ,0);

    return d1+d2;
}
int main{
    struct  Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left-> left = new Node(4);
    root->left-> right = new Node(5);

    return 0;
}