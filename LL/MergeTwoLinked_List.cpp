#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *ptr;
};
void AddData(int data, Node ** head_ref){
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
        cout<<temp->data<<endl;
        temp=temp->ptr;
    }
}
void Merge(Node *head1, Node *head2){
    Node *first=NULL;
    while (head1!=NULL && head2!=NULL){
        if (head1->data<head2->data){
            AddData(head1->data,&first);
            head1=head1->ptr;
        }
        else if (head1->data>head2->data){
            AddData(head2->data,&first);
            head2=head2->ptr;
        }
        else {
            AddData(head2->data,&first);
            head2=head2->ptr;
            head1=head1->ptr;
        }
    }
    while (head1!=NULL){
        AddData(head1->data,&first);
        head1=head1->ptr;
    }
    while (head2!=NULL){
        AddData(head2->data,&first);
        head2=head2->ptr;
    }
    PrintLL(first);
}
int main(){
    Node *head1=NULL;
    Node *head2=NULL;
    AddData(2,&head1);
    AddData(4,&head1);
    AddData(7,&head1);
    AddData(8,&head1);
    AddData(3,&head2);
    AddData(5,&head2);
    AddData(6,&head2);
    AddData(9,&head2);
    Merge(head1,head2);
}
