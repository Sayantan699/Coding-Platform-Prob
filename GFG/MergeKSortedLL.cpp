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
    Node *mergeKLists(vector<Node *> &arr)
    {
        // code here
        Node *head = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            head = mergeLL(head, arr[i]);
        }

        return head;
    }

    Node *mergeLL(Node *head1, Node *head2)
    {
        Node *Head = new Node(0); // dummy Node
        Node *Tail = Head;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                Tail->next = head1;
                head1 = head1->next;
                Tail = Tail->next;
                Tail->next = NULL;
            }
            else
            {
                Tail->next = head2;
                head2 = head2->next;
                Tail = Tail->next;
                Tail->next = NULL;
            }
        }
        while (head1)
        {
            Tail->next = head1;
            head1 = head1->next;
            Tail = Tail->next;
            Tail->next = NULL;
        }

        while (head2)
        {
            Tail->next = head2;
            head2 = head2->next;
            Tail = Tail->next;
            Tail->next = NULL;
        }

        return Head->next;
    }
};