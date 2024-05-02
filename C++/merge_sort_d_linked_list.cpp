//merge sort of doubly linked list

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

class Node
{
public:
    int v;
    Node * n;
    Node * p;
    Node(int a)
    {
        v = a;
    };
};

/*class LinkedList
{
public:
    Node static * head;
    static int len;
    LinkedList()
    {
        head->n = NULL;
        head->p = NULL;
        len++;
    }
    void newNode(int a)
    {
        Node * n = new Node(a);
        cout << "n->v = " << n->v << endl;
        Node * temp;
        if(len == 1)
        {
            head = n;
            return;
        }
        for(int i=0; i<len-1; i++)
        {
            cout << temp->v << " ";
            temp=temp->n;
        }
        temp->n=n;
        n->p=temp;
    }
    void printList()
    {
        Node * temp = head;
        for(int i=0; i<len-1; i++)
        {
            cout << temp->v << endl;
            temp=temp->n;
        }
    }
};

int LinkedList::len = 0;
Node * LinkedList::head;
*/

void merge_ll(Node * head, int l, int m, int r)
{
    int len1 = m-l+1;
    int len2 = r-m;

    //copy elemets from linked list to temporary lls
    int x=0, y=0, z=l;
    //seek the value of l through head
    Node * temp = head;
    int c=0;
    while(temp->n != NULL && c!=l)
    {
        temp=temp->n;
        c++;
    }
    x=0;
    Node * headl = new Node(temp->v);
    Node * templ = headl;
    while(x < len1 && temp->n!=NULL)
    {   
        Node * headl = new Node(temp->v);
        headl = templ->n;
        headl->p = templ;
        templ = headl;
        temp=temp->n;
        x++;
    }
    // seak the value of m through head
    int c=l;
    while(temp->n != NULL && c!=m)
    {
        temp=temp->n;
        c++;
    }
    y=0;
    Node * headr = new Node(temp->v);
    Node * tempr = headr;
    while(y < len2 && temp->n!=NULL)
    {   
        Node * headr = new Node(temp->v);
        headr = tempr->n;
        headr->p = tempr;
        tempr = headr;
        temp=temp->n;
        x++;
    }

    //sort out according to smaller / bigger
    while(templ->n!=NULL && tempr->n!=NULL)
    {
        
    }
    //append remaining

    //free the temporary
}

void merge_routine_ll(Node * head, int l, int r)
{
    if(l>=r)
    {
        return;
    }
    auto m = l + (r-l)/2;
    merge_routine_ll(head, l, m);
    merge_routine_ll(head, m+1, r);
    merge_ll(head, l, m, r);
}
int main()
{  
    /*LinkedList ll;
    ll.newNode(3);
    ll.newNode(1);
    ll.newNode(5);
    //ll.printList();*/

    Node * head = new Node(3);
    Node * sec = new Node(5);
    head->n = sec;
    sec->p = head;
    Node * third = new Node(1);
    sec->n = third;
    third->p = sec;
    Node * temp = head;
    while(temp->n != NULL)
    {
        cout << temp->v << endl;
        temp = temp->n;
    }

    merge_routine_ll(head, 0, 3);

    free(third);
    free(sec);
    free(head);
    return 0;
}