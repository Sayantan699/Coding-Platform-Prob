/*
structure of the node of the linked list is
struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    vector<Node *> mergeList(struct Node **Head, struct Node **Head2)
    {
        Node *head1 = *Head;
        Node *head2 = *Head2;

        while (head1 && head2)
        {
            Node *next1 = head1->next;
            Node *next2 = head2->next;

            head1->next = head2;
            head2->next = next1;

            head1 = next1;
            head2 = next2;
        }

        *Head2 = head2; // Remaining nodes of list2

        return {*Head, *Head2};
    }
};
