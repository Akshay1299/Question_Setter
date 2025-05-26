/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* curr = head;
        Node* newNode = new Node(data);
        
        // Tackling the case where we're given an empty linked list
        if(head == NULL){
            newNode->next = newNode;
            return newNode;
        }
        // Case where the node to be inserted is going to be the head of the linked list
        // i.e. the node to be inserted has the smallest value
        if(data < head->data){
            newNode->next = head;
            Node* curr = head;
            while(curr->next != head){
                curr = curr->next;
            }
            curr->next = newNode;
            return newNode;
        }
        // Other cases
        Node* prev = NULL;
        while(curr->data < data && curr->next != head){
            prev = curr;
            curr = curr->next;
        }
        // Case when the node is going to be inserted at the last, in this case
        // we will have to change circular nature of linked list
        if(curr->data < data){
            curr->next = newNode;
            newNode->next = head;
            return head;
        }
        // Case when node is going to be inserted in somewhere middle (simplest case)
        prev->next = newNode;
        newNode->next = curr;
        return head;
    }
};