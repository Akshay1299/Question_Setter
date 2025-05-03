//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    vector<int>fun(int n){
       vector<int>ans;
       vector<bool>vis(n+1, true);
       for(int i=2; i*i<=n; i++){
           if(vis[i]){
               for(int j=i*i; j<=n; j+=i){
                   vis[j]=false;
               }
           }
       }
       for(int i=2; i<=n; i++){
           if(vis[i]){
               ans.push_back(i);}
       }
       return ans;
   }
   
    Node *primeList(Node *head) {
        vector<int>primes=fun(10010);
        Node *a=NULL, *b=NULL;
        while(head){
            int x=head->val, y;
            int xx=lower_bound(primes.begin(), primes.end(),x)-primes.begin();
            if(xx>=primes.size()){
                y=primes.back();
            }
            else if(xx==0 or primes[xx]==x ){
                y=primes[xx];
            }
            else{
                int aa=primes[xx-1], bb=primes[xx];
                if((x-aa)==(bb-x)){y=aa;}
                else(x-aa)>(bb-x)?y=bb:y=aa;
            }
            Node *yy=new Node(y);
            if(a==NULL){
                a=yy; b=yy;
            }
            else{
                b->next=yy;
                b=yy;
            }
            head=head->next;
        }
        return a;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends