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

Node* inserthead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

int main(){
    vector<int> arr = {12, 7, 5, 7};
    Node* head = convertArr2LL(arr);
    head = inserthead(head, 20);
    print(head);
}