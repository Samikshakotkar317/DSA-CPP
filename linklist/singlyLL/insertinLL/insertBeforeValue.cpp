#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node * next;

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* insertBeforeValue(Node* head, int el, int val){
    if(head == NULL){
        return NULL;
    }

    if(head->data == val){
        return new Node(el, head);
    }

    Node* temp = head;
    while(temp->next != NULL){
        if(temp->next->data == val){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 8, 5, 7};
    Node* head = convertArr2LL(arr);
    head = insertBeforeValue(head, 20, 7);
    print(head);
}