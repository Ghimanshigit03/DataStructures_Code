#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* ptr;
};
void AddData(int data, Node **head_ref){
    Node *temp=new Node();
    temp->ptr=NULL;
    temp->data=data;
    Node *last=*head_ref;
    if (*head_ref==NULL){
        *head_ref=temp;
    }
    else{
        while (last->ptr!=NULL){
            last=last->ptr;
        }
        last->ptr=temp;
    }
}
void PrintLL(Node *head){
    Node *temp=head;
    while (temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->ptr;
    }
}
Node *Middle(Node *head){
    Node *slow=head;
    Node *fast=head;
    while (fast->ptr->ptr!=NULL){
        slow=slow->ptr;
        fast=fast->ptr->ptr;
    }
    return slow;
}
Node* mergeSortedList(Node* head1, Node* head2)
{
    Node* newHead = NULL;
    Node *tail=NULL;
    if (head1->data <= head2->data) {
        newHead = head1;
        head1=head1->ptr;
    }
    else {
        newHead = head2;
        head2=head2->ptr;
    }
    tail=newHead;
    while(head1!=NULL && head2!=NULL)
    {
        if (head1->data <= head2->data) {
        tail->ptr = head1;
        head1=head1->ptr;
    }
    else {
        tail->ptr = head2;
        head2=head2->ptr;
    }
    tail=tail->ptr;
    }
    if(head1!=NULL)
    {
        tail->ptr=head1;
    }
    if(head2!=NULL)
    {
        tail->ptr=head2;
    }
    return newHead;
}
Node* mergeSort(Node* head)
{
    if(head==NULL||head->ptr==NULL)
    {
        return head;
    }
    Node* mid=new Node();
    mid=Middle(head);
    Node* head2=mid->ptr;
    mid->ptr=NULL;
    Node *newHead = mergeSortedList(mergeSort(head),mergeSort(head2));
    return newHead;
}
int main()
{
    Node *head=NULL;
    int size,i,value;
    cout<<"Enter size of LL\n";
    cin>>size;
    for (i=1;i<=size;i++){
        cout<<"Enter data of LL\t";
        cin>>value;
        AddData(value,&head);
    }
    cout<<"Linked List before Sorting is - \n";
    PrintLL(head);
    Node *newhead=mergeSort(head);
    cout<<"\nLinked List after Sorting is -\n";
    PrintLL(newhead);
}