 #include<bits/stdc++.h>
 using namespace std;

 struct Node{
    public:
    int data;
    Node * next;
    Node * prev;

    Node(int data1, Node * next1, Node * prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
 };

 Node* convertArr2LL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node * prev = head;
    for(int i = 1;i < arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
 };
 //print a LL
 void print(Node* head){
    while(head !=NULL){
        cout << head->data << " ";
        head = head->next;
    }
 }

Node * deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    
    // if(tail->next == NULL){
    //     tail->prev->next = nullptr;
    //     tail->prev = nullptr;
    //     delete(tail);
    // }

    Node* temp = tail->prev;
    temp->next = nullptr;
    tail->prev = nullptr;
    delete(tail);
    return head;
}

 int main(){
    vector<int> arr = {5,9,7,6};
    Node* head = convertArr2LL(arr);
    head = deleteTail(head);
    print(head);
    return 0;
 }