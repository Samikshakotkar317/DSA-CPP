#include<bits/stdc++.h>
using namespace std;

struct Node{  /// you can use 'struct' as well as 'class' both
    public:
    int data;
    Node* next;
    // constructor type 1
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    //constructor type 2
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArr2LL(vector<int>&arr){
    Node * head = new Node(arr[0]);
    Node * mover = head;
    for(int i = 1; i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    cout << head->data;
}