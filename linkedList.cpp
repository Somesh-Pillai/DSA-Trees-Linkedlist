#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    public:
    node* front;
    node* back;

    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int val){
        node* n = new node(val);
        if(front == NULL){
            front=n;            // we are just having pointers not linked list created, values of pointers are only needed.
            back=n;
        }
        back-> next = n;  //we need to change pointer and then node  
        back =n;
    }

    void pop(){
        if(front == NULL){
            cout<<"Queue empty"<<endl;
            return;
        }
        node* n = front;
        front= front-> next;

        delete n; 
    }

    int peek(){
        if(front == NULL){
            cout<<"Queue empty"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front == NULL){
            cout<<"Queue empty"<<endl;
            return true;
        }
        return false;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    n-> next = head;
    head = n;
}

void insertAtTail(node* &head, int val){
        node* n = new node(val); //next of n will be NULL

        if(head == NULL){
            head=n;
            return;
        }

        node* temp = head;
        while(temp-> next != NULL){
            temp = temp -> next;
        }
        temp-> next = n;

    }

void display(node* head){
        node* temp = head; // we can pass head as we are not taking reference
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp=temp-> next;
        }
        cout<<"NULL"<<endl;
    }
bool search(node* head, int key){
    node* temp = head;
    while(temp != NULL){
        if(temp -> data == key){
            return true;
        }
        temp = temp-> next;
    }
    return false;
}

void deleteAtHead(node* &head){
    node* toDelete = head;
    head = head-> next;
    delete toDelete;   //or else memory leak 
}
void deleteNode(node* &head, int val){

    if(head == NULL){
        return;
    }
    if(head->next == NULL){
        deleteAtHead(head);
    }
    node* temp = head;
    while(temp->next->data != val){
        temp = temp-> next;
    }
    node* nodeToDelete = temp->next;
    temp->next = temp->next->next;

    delete nodeToDelete;
}

node* reverse(node* &head){
    node* prevNode = NULL;
    node* currNode = head;
    node* nextNode;

    while(currNode!= NULL){
        nextNode = currNode->next;
        currNode->next = prevNode;

        prevNode = currNode;
        currNode = nextNode;
    }

    return prevNode;
}

node* revereseKNodes(node* &head, int k){
    node* prevNode = NULL;
    node* currNode = head;
    node* nextNode;
    int count = 0;

    while(currNode!= NULL && count < k){
        nextNode = currNode->next;
        currNode->next = prevNode;

        prevNode = currNode;
        currNode = nextNode;
        count++;
    }
    if(nextNode != NULL){
    head-> next = revereseKNodes(nextNode, k);
    }

    return prevNode;
}

bool detectCycle(node* &head){ //floyd algo
    node* slow = head;
    node* fast = head;

    while(fast!= NULL && fast-> next!= NULL){
        slow = slow-> next;
        fast = fast->next->next;

        if(slow == fast)
            return true;
    }
    return false;

}

void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do{
        slow = slow-> next;
        fast = fast->next->next;
    }while(slow != fast);

    fast = head;
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow-> next = NULL;
}

int length(node* head){
    node* temp = head;
    int l = 0;
    while(temp!= NULL){
        temp = temp-> next;
        l++;
    }
    return l;
}
int findIntersectionPoint(node* &head1, node* &head2){
    int d1 = length(head1);
    int d2 = length(head2);
    int d = d1 - d2;
    node* ptr1;
    node* ptr2;
    if(d > 0){
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        ptr1 = head2;
        ptr2 = head1;
    }

    while(d){
        ptr1 = ptr1-> next;
        if(ptr1 != NULL){
            return -1;
        }
        d--;
    }
    while(ptr1 != NULL){
         if(ptr1 == ptr2){   //intially it can be in same so need to check first and then move the node.
            return ptr1-> data;
        }
        ptr1 = ptr1 ->next;
        ptr2 = ptr2-> next;
    }
    return -1;    
}

node* appendLastKNodesToFirst(node* &head, int k){
    node* newTail;
    node* newHead;
    node* tail = head;

    k = k%length(head);
    int count = 1;
    while(tail-> next != NULL){
            if(count == length(head) - k){
                newTail = tail;
            }
            else if(count == length(head) - k + 1){
                newHead = tail;
            }
        tail = tail-> next;
        count++;
    }
    newTail-> next = NULL;
    tail-> next = head;

    return newHead;

}


int main(){
    node* head= NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 3);
    insertAtTail(head, 5);
    insertAtTail(head, 7);
    display(head);

    return 0;
}