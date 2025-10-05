/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution
{
public:
    Node *insertAtPos(Node *head, int p, int x)
    {
        Node *temp = new Node(x);

        // Insert at start i,e before Head pointer
        if (p == -1)
        {
            temp->next = head;
            if (head != NULL)
                head->prev = temp;
            head = temp;
            return head;
        }

        Node *curr = head;

        // Traversing to the specific position
        while (p-- && curr != NULL)
        {
            curr = curr->next;
        }

        // Now curr is at a position > 0

        temp->next = curr->next;
        if (curr->next != NULL) // Only execute if curr is not pointing at last node of LL
            curr->next->prev = temp;

        curr->next = temp;
        temp->prev = curr;

        return head;
    }
};
