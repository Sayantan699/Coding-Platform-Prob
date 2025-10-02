/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution
{
public:
    Node *flatten(Node *root)
    {
        // code here

        while (root && root->next)
        {
            Node *head1 = root;
            Node *head2 = root->next;
            Node *head3 = root->next->next;

            root = mergeLL(head1, head2);

            root->next = head3;
        }

        return root;
    }

    Node *mergeLL(Node *head1, Node *head2)
    {
        Node *Head = new Node(0); // dummy Node
        Node *Tail = Head;

        while (head1 && head2)
        {
            if (head1->data <= head2->data)
            {
                Tail->bottom = head1;
                head1 = head1->bottom;
                Tail = Tail->bottom;
                Tail->bottom = NULL;
            }
            else
            {
                Tail->bottom = head2;
                head2 = head2->bottom;
                Tail = Tail->bottom;
                Tail->bottom = NULL;
            }
        }
        while (head1)
        {
            Tail->bottom = head1;
            head1 = head1->bottom;
            Tail = Tail->bottom;
            Tail->bottom = NULL;
        }

        while (head2)
        {
            Tail->bottom = head2;
            head2 = head2->bottom;
            Tail = Tail->bottom;
            Tail->bottom = NULL;
        }

        return Head->bottom;
    }
};