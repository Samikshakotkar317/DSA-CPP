#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i< arr.size(); i++){
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
    cout<< endl;
}

Node* deleteTail(Node* head){
    Node* temp = head;
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    while(temp->next->next != NULL){
        temp = temp -> next;
    }
    free(temp->next); // or delete temp->next
    temp->next = nullptr;

    return head;
}

int main(){
    vector<int> arr = {12,5, 8, 7};
    Node* head = convertArr2LL(arr);
    head = deleteTail(head);
    print(head);
}