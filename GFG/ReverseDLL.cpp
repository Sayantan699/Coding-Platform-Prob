/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution
{
public:
    Node *reverse(Node *Head)
    {
        // code here
        Node *curr = Head;
        Node *future = NULL;

        Node *previous = NULL;
        while (curr)
        {
            future = curr->next;
            curr->next = previous;
            curr->prev = future;
            previous = curr;
            curr = future;
        }

        Head = previous;

        return Head;
    }
};