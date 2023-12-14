#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

node *temp, *head = temp = NULL;

bool isEmpty();
void enPriorityQueue(int value);
int dePriorityQueue();

int main()
{
    enPriorityQueue(11);
    enPriorityQueue(54);
    enPriorityQueue(44);
    enPriorityQueue(22);
    while(head!=NULL){cout<<dePriorityQueue()<<"\t";}
    

    return 0;
}

bool isEmpty() { return head == NULL; }
void enPriorityQueue(int value)
{
    node *newNode = new node;
    newNode->data = value;
    if (isEmpty() || newNode->data > head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    temp = head;
    while (newNode->data < temp->next->data){temp = temp->next;}
    newNode->next = temp->next;
    temp->next = newNode;
}

int dePriorityQueue()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return 0;
    }
    temp = head;
    int largerNumber = head->data;
    head=head->next;
    free(temp);
    return largerNumber;
}