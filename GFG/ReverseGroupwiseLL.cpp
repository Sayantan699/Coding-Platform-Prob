// Linked List Group Reverse

//         You are given the head of a Singly linked list.
//         You have to reverse every k node in the linked list and return the head of the modified list.
//         Note : If the number of nodes is not a multiple of k then the left - out nodes at the end,
//     should be considered as a group and must be reversed.

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        Node *first = new Node(0);
        first->next = head;
        head = first;
        int x;
        Node *second, *prev, *curr, *front;

        // Reversing process
        while (first->next)
        {
            x = k;
            second = first->next;
            prev = first;
            curr = second;
            while (x && curr)
            {
                Node *front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }

            first->next = prev;
            second->next = curr;
            first = second;
        }
        // deleting the demo node
        first = head;
        head = head->next;
        delete first;
        return head;
    }
};