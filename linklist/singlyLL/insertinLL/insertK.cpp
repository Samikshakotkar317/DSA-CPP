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

Node* insertk(Node* head, int el, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(el);
        }
        else return NULL;
    }

    if(k == 1){
        Node* temp = new Node(el, head);
        return temp;
    }

    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    vector<int> arr = {12, 7, 5, 7};
    Node* head = convertArr2LL(arr);
    head = insertk(head, 20, 3);
    print(head);
}