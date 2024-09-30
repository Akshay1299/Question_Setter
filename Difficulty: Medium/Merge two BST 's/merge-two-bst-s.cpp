//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void helper(vector<int> &res, stack<Node*> &bs){
        res.push_back(bs.top()->data);
        Node* top = bs.top();
        bs.pop();
        if(!bs.empty() && bs.top()->left)bs.top()->left = nullptr;
        if(top->right)
        {
            bs.push(top->right);
        }
    }
    void helper2(int *bs_e, stack<Node*> &bs){
        if(!bs.top()->left && ! (*bs_e))
        {
            *bs_e = bs.top()->data;
        }
        else if(!(*bs_e))
        {
            bs.push(bs.top()->left);
        }
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> res;
        stack<Node*> bs1;
        stack<Node*> bs2;
        int bs1e = 0, bs2e = 0; 
        bs1.push(root1);
        bs2.push(root2);
        while(!bs1.empty() && !bs2.empty())
        {
            helper2(&bs1e,bs1);
            helper2(&bs2e,bs2);
            if(bs1e && bs2e)
            {
                if(bs1e<bs2e)
                {
                    helper(res,bs1);
                    bs1e = 0;
                }
                else
                {
                    helper(res,bs2);
                    bs2e = 0;
                }
            }
        }
        while(!bs1.empty())
        {
            if(!bs1.top()->left)
            {
                helper(res,bs1);
            }
            else
            {
                bs1.push(bs1.top()->left);
            }
            
        }
        
        while(!bs2.empty())
        {
            if(!bs2.top()->left)
            {
                helper(res,bs2);
            }
            else
            {
                bs2.push(bs2.top()->left);
            }
            
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends