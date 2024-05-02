#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class node{
    public :
    int v;
    class node *next;
    
    node(){next = NULL;}
    
};

node * insert(int val, node * head) //stack - adding at the head
{
    node *n = new node;
    n->v=val;
    if(head==NULL)
    {
        head=n;
        head->next=NULL;
        return head;
    }
    /*while(head->next !=NULL)
    {
        head = head->next;
    }
    head->next=n;*/
    n->next=head;
    head=n;
    return head;
}

node * del(node * head)
{
    node * temp = head;
    head = head->next;
    free(temp);
    return head;
}

class stack{
    public :
    node * fr;
    node * bk;
    
    stack()
    {
        fr=bk;
    }

    void add(int v, node *head, int op)
    {
        if(op==1)
        {
            node * n1=insert(v, head);
            this->bk=n1;
            cout << "head value: " << head->v << endl;
            return;
        }
        else if(op==2)
        {
            node * n1=insert(v, head);
            this->fr=n1;
            cout << "head1 value: " << head->v << endl;
            return;
        }
        return;
    }
    void remove(node * head, int op)
    {
        if(op==1)
        {
            node * n1=del(head);
            this->fr=n1;
            return;
        }
        else if(op==2)
        {
            node * n1=del(head);
            this->bk=n1;
            return;
        }
        return;
    }
    void show()
    {
        cout << this->bk->v << endl;
    }
    
};

class queue{
    public :
    stack st;
    stack stv;
    node * head;
    node * head1;
    queue()
    {
        head = NULL;
        head1 = NULL;
    }
    void enq(int val)
    {
        st.add(val, head, 1);
        stv.add(val, head1, 2);
    }
    void deq()
    {
        st.remove(head, 1);
        stv.remove(head1, 2);
    }
    void printFront()
    {
        stv.show();
    }
};

std::string trim(const std::string &s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
 
    auto end = s.end();
    do {
        end--;
    } while (std::distance(start, end) > 0 && std::isspace(*end));
 
    return std::string(start, end + 1);
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

int main() {
    int steps, op, val;
    string inp;
    vector <string> inputs;
    queue Q;
    cout << "please enter steps" << endl;
    cin >> steps;
    vector<string> temp;
    fflush(stdin);
    for(int i=0; i<steps; i++){
        getline(cin, inp);
        temp = split(trim(inp));
        /*cout << "num of fields in input :" << temp.size() << endl;
        cout << temp[0] << " " << temp[1] << endl;*/
        op=stoi(temp[0]);
        if(temp.size() == 2)
        {
            val=stoi(temp[1]);
        }
        if(op==1)
        {
            cout << endl << "Enqueueing" << endl;
            Q.enq(val);
        }
        else if(op==2)
        {
            cout << endl << "Dequeueing" << endl;
            Q.deq();
        }
        else if(op==3)
        {
            cout << endl << "Printing first in the queue" << endl;
            Q.printFront();
        }
    }
    cout << endl;
    return 0;
}
