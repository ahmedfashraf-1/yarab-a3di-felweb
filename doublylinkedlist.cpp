#include<bits/stdc++.h>
#define ll long long 
using namespace std;
struct node{
    ll data;
    node*next;
    node*prev;
};
class double_linked_list{
    node*head;
    ll cnt;
    public:
    double_linked_list(){
        head=NULL;
        cnt=0;
    }
    void insertfirst(ll x){
        node*newnode=new node;
        newnode->data=x;
        newnode->prev=NULL; // lazem prev 3andi NULL
        if(head==NULL){ // awel 7aga 3andi
            head=newnode;
            newnode->next=NULL;
        }
        else{
            newnode->next=head;
            head->prev=newnode; // lw 3andi elem fe el awel refrence to newnode 
            head=newnode;// head refrence to newnode 
        }
        cnt++;
    }
    void insert_last(ll x){
        node*newnode=new node;
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            newnode->prev=NULL;
        }
        else{
        node*q=head;
        while(q->next!=NULL){
            q=q->next;
        }
        q->next=newnode;
        newnode->prev=q;
    }
    cnt++;
    }
    void insert_at(ll x,ll pos){
        if(pos<1||pos>cnt){
            cout<<"aktb 7aga sa7 "<<endl;
            return;
        }
        node*newnode=new node;
        newnode->data=x;
        node*q=head; ll i=1;
        while(q!=NULL&&i<pos){
            q=q->next;
            i++;
        }
        newnode->prev=q->prev;
        q->prev->next=newnode;
        newnode->next=q;
        q->prev=newnode;
        cnt++;
    }
    void delete_first(){
        if(head==NULL){
            cout<<"akteb 7aga tanya "<<endl;
            return ;
        }
        node*q=head;
        if(head->next==NULL)head=NULL;
        else{
            head=head->next;
            head->prev=NULL;
        }
        delete q;
        cnt--;
    }
    void delete_last(){
        if(head==NULL){
            cout<<"akteb 7aga tanya "<<endl;
            return ;
        }
        node*q=head;
        if(cnt==1){
            delete q;
            head=NULL;
        }
        while(q->next!=NULL){
            q=q->next;
        }
        q->prev->next=NULL;
        delete q;
        cnt--;
    }
    void delete_at(ll pos){
        if(pos<1||pos>cnt){
            cout<<"akteb 7aga tanya "<<endl;
            return ;
        }
        node*q=head; ll i=1;
        while(q!=NULL&&i<pos){
            q=q->next;
            i++;
        }
        q->prev->next=q->next;
        q->next->prev=q->prev;
        delete q;
        cnt--;
    }
    void display(){
        node*q=head;
        while (q!=NULL)
        {
            cout<<q->data<<" ";
            q=q->next;
        }
        cout<<endl;
    }
    void reverse(){
        node*a=head;
        node*b=a->next;
        a->next=NULL;
        a->prev=b;
        while(b!=NULL){
            b->prev=b->next;// swap (b->prev,b->next);
            b->next=a;
            a=b;
            b=b->prev;
        }
        head=a;
    }
    void purge(){
        node*q=head;
        while(q!=NULL){
            node*temp=q; // 1 ,2 ,2,3,4,4,5
            while(temp->next!=NULL){
                if(temp->next->data==temp->data){ //  مفيش اي تكرار عند 1 يبقي يروح لل 2 هيبقي عندي اتنين ورا بعض 2 يبقي هشيل التانيه واخلي الاولي تشاور علي بعد اللي بعدها 
                    node*purge=temp->next;
                    temp->next=temp->next->next;
                    if(temp->next!=NULL)temp->next->prev=temp;
                    delete purge;
                }
                else temp=temp->next;
            }
            q=q->next;
        }
    }
};
int main(){
        double_linked_list dll;
        dll.insertfirst(5);
        dll.insertfirst(4);
        dll.insertfirst(4);
        dll.insertfirst(3);
        dll.insertfirst(2);
        dll.insertfirst(2);
        dll.insertfirst(1);
        cout << "Original list: ";
        dll.display();
        dll.delete_first();
        cout << "After deleting first: ";
        dll.display();
        dll.delete_last();
        cout << "After deleting last: ";
        dll.display();
        dll.insert_last(6);
        cout << "After inserting last: ";
        dll.display();
        dll.insert_at(10, 3);
        cout << "After inserting 10 at position 3: ";
        dll.display();
        dll.delete_at(3);
        cout << "After deleting element at position 3: ";
        dll.display();
        dll.reverse();
        cout << "After reversing: ";
        dll.display();
        dll.purge();
        cout << "After purging duplicates: ";
        dll.display();
        return 0;
    }