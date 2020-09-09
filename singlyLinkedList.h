#include<iostream>
using namespace std;
template<class T>
class sll{
public:
	sll(){
		length=0;
		head=NULL;
	}
	~sll(){
		clear();
	}
	int len(){
		return length;
	}
	void pushFront(T value){
		if(head==NULL){
			head=new node;
			head->key=value;
			head->next=NULL;
		}else{
			node *cur=new node;
			cur->key=value;
			cur->next=head;
			head=cur;
		}
		length++;
	}
	void pushBack(T value){
		if(head==NULL){
			head=new node;
			head->key=value;
			head->next=NULL;
		}else{
			node *cur=head;
			while(cur->next!=NULL){
				cur=cur->next;
			}
			cur->next=new node;
			cur=cur->next;
			cur->key=value;
			cur->next=NULL;
		}
		length++;
	}
	void insert(int pos, T value){
		if(pos>len() || pos<0){
			cout<<"out of range when insert("<<pos<<", "<<value<<")"<<endl;
			return;
		}else if(pos==0){
			pushFront(value);
		}else if(pos==len()){
			pushBack(value);
		}else{
			node *cur=head;
			for(int i=0;i<pos-1;i++){
				cur=cur->next;
			}
			node *nxt=cur->next;
			node *tmp=new node;
			tmp->key=value;
			tmp->next=nxt;
			cur->next=tmp;
		}
		length++;
	}
	void popFront(){
		if(len()<=0){
			cout<<"popFront fail because nothing in the linklist"<<endl;
			return;
		}else{
			node *cur=head;
			head=head->next;
			delete cur;
		}
		length--;
	}
	void popBack(){
		if(len()<=0){
			cout<<"popBack fail because nothing in the linklist"<<endl;
			return;
		}else if(len()==1){
			popFront();
		}else{
			node *cur=head;
			for(int i=0;i<len()-2;i++){
				cur=cur->next;
			}
			delete cur->next;
			cur->next=NULL;
		}
		length--;
	}
	void erase(int pos){
		if(pos<0 || pos>=len()){
			cout<<"out of range when erase("<<pos<<")"<<endl;
			return;
		}else if(pos==0){
			popFront();
		}else if(pos==len()-1){
			popBack();
		}else{
			node *cur=head;
			for(int i=0;i<pos-1;i++){
				cur=cur->next;
			}
			node *nxt=cur->next;
			cur->next=nxt->next;
			delete nxt;
		}
		length--;
	}
	void clear(){
		node *cur=head, *nxt;
		while(cur->next!=NULL){
			nxt=cur->next;
			delete cur;
			cur=nxt;
		}
		head=NULL;
		length=0;
	}
	void print(){
		if(head!=NULL){
			node *cur=head;
			while(cur!=NULL){
				cout<<cur->key<<endl;
				cur=cur->next;
			}
			cout<<"length="<<len()<<endl;
		}else{
			cout<<"nothing in the linklist"<<endl;
		}
	}
private:
	typedef struct node{
		T key;
		struct node *next;
	}node;
	int length;
	node *head;
};
