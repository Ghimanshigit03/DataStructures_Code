#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *ptr;
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
        cout<<temp->data<<endl;
        temp=temp->ptr;
    }
}
int main(){
    Node *head=NULL;
    AddData(1,&head);
    AddData(2,&head);
    AddData(3,&head);
    AddData(5,&head);
}


void AddFirst(int data,Node **head_ref){
    Node *temp=new Node();
    temp->data=data;
    temp->ptr=*head_ref;
    *head_ref=temp;
}


void AddAtIndex(int data,int index, Node **head_ref){
    Node *temp=new Node();
    temp->data=data;
    Node *last=*head_ref;
    Node *seclast=*head_ref;
    last=last->ptr;
    int i;
    for (i=1;i<index-1;i++){
        last=last->ptr;
        seclast=seclast->ptr;
    }
    temp->ptr=last;
    seclast->ptr=temp;
}


void RemoveLast(Node *head){
    Node *end=head;
    Node *beforend=head;
    end=end->ptr;
    while (end->ptr!=NULL){
        end=end->ptr;
        beforend=beforend->ptr;
    }
    beforend->ptr=NULL;
    free(end);
}


void ReverseLL(Node **head_ref){
    Node *curr=*head_ref;
    Node *prev=NULL;
    Node *next;
    while (curr!=NULL){
        next=curr->ptr;
        curr->ptr=prev;
        prev=curr;
        curr=next;
    }
    *head_ref=prev;
}


void KthFromLast(Node *head,int k){
    Node *slow=head;
    Node *fast=head;
    int i;
    for (i=0;i<k;i++){
        fast=fast->ptr;
    }
    while (fast!=NULL){
        fast=fast->ptr;
        slow=slow->ptr;
    }
    cout<<k<<" th element from last is - "<<slow->data;
}


int Middle(Node *head){
    int f=1;
    Node *slow=head;
    Node *fast=head;
    while (fast->ptr->ptr!=NULL){
        slow=slow->ptr;
        fast=fast->ptr->ptr;
        f++;
    }
    return f;
}


void IsPalindrome(Node *head){
    Node *temp=head;
    int p=Middle(temp);
    int f=0;
    int i;
    for (i=0;i<p;i++){
        temp=temp->ptr;
    }
    ReverseLL(&temp);
    Node *temp2=temp;
    while (temp2!=NULL){
        if (temp2->data==head->data){
            temp2=temp2->ptr;
            head=head->ptr;
        }
        else {
            f=1;
            break;
        }
    }
    if (f==0) cout<<"Yes a Palindrome";
    else cout<<"Not a Palidrome";
}