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

int main(){
    vector<int> arr = {2, 5, 8, 7};
    // Node* y = new Node(arr[0], nullptr);
    // cout << y; // it will give pointer to the memory location
    Node y = Node(arr[0], nullptr);
    cout << y.next; // you cannont print direct y
    // Node* y = new Node(arr[0], nullptr);
    // cout << y->data; // you cannont print y.data it will give me error 
}