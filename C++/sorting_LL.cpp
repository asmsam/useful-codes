//sorting linked list
/*to edit this template :
cd C:\Users\aseemsa\.vscode\extensions\ralfzhang.filetemplate-2.0.4\asset\templates
open cpp.tmpl
*/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Node{
    public:
    int data;
    Node * next;
};

void SplitFrntBck(Node * head, Node * frntref, Node * bckref)
{
    //split based on double pointer mid finder mechnanism
    Node * fast, * slow;
    fast = head;
    slow = head;

    while(fast != nullptr)
    {
        if(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast = fast->next;
    }
    frntref=head;
    bckref = slow;
    slow->next = nullptr;
}

Node * combine(Node * a, Node * b)
{
    Node* result = nullptr;
 
    /* Base cases */
    if (a == nullptr)
        return (b);
    else if (b == nullptr)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = combine(a->next, b);
    }
    else {
        result = b;
        result->next = combine(a, b->next);
    }
    return (result);
}

void mergeSort(Node * head)
{
    if(head == nullptr || head->next == nullptr)
    {
        return;
    }

    Node * a = nullptr;
    Node * b = nullptr;
    SplitFrntBck(head, a, b);

    mergeSort(a);
    mergeSort(b);
    combine(a,b);
}

void printList(Node ** node)
{
    cout << "printing list : " << endl;
    while (*node != nullptr) {
        cout << (*node)->data << " ";
        (*node) = (*node)->next;
    }
}

void printListReverse(Node * node)
{
    if (node == nullptr) {return;}
    printListReverse (node->next);
    cout << node->data << " ";
    return;
}

void push(Node ** hptr, int v)
{
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = v;
 
    if(*hptr == nullptr)
    {
        *hptr = new_node;
        new_node->next = nullptr;
        cout<<"Added head "<<(*hptr)->data<<endl;
    }
    else {
        /* link the old list off the new node */
        new_node->next = *hptr;
        /* move the head to point to the new node */
        *hptr = new_node;
        cout<<"Added "<<(*hptr)->data<<endl;
    }
}

int main()
{
    /* Start with the empty list */
    Node * a = nullptr;
 
    /* Let us create a unsorted linked lists to test the functions
    Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    printList(&a);
    /* Sort the above created Linked List */
    mergeSort(a);
 
    cout << endl << "Sorted Linked List is: \n";
    printList(&a);
    return 0;
}