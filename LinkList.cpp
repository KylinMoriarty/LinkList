#include "LinkList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

LinkList::LinkList(){
    head = new ListNode;
    head->data=0;
    head->next=nullptr;
}//构建一个单链表，初始化头结点

LinkList::~LinkList(){
    delete head;
}//销毁一个单链表

ListNode* LinkList::GetHead(){
    return head;
}

void LinkList::CreateLinkListAtEnd(int n){
    ListNode *pnew,*ptemp;
    ptemp=head;
    if(n<0){
        cout<<"False"<<endl;//当输入的值有误时，处理异常
        return ;
    }
    for(int i=0;i<n;i++){
        pnew = new ListNode;
        cout<<"请输入第"<<i+1<<"个值：";
        cin>>pnew->data;
        pnew->next=nullptr;//新节点下一个地址为NULL
        ptemp->next=pnew;//当前节点的下一个地址为新节点
        ptemp=pnew;//将当前节点设为新节点
    }
}//尾插法创建一个单链表

void LinkList::CreateLinkListAtHead(int n){
    ListNode *pnew,*ptemp;
    ptemp=head;
    if(n<0){
        cout<<"False"<<endl;//当输入的值有误时，处理异常
        return ;
    }
    for(int i=0;i<n;i++){
        pnew = new ListNode;
        cout<<"请输入第"<<i+1<<"个值：";
        cin>>pnew->data;
        pnew->next=ptemp->next;
        ptemp->next=pnew;
    }
}//头插法创建一个单链表

void LinkList::TraverLinkLIst(){
    if(head==nullptr||head->next==nullptr){
        cout<<"NULL"<<endl;
        return ;
    }
    ListNode *p=head;
    while(p->next!=nullptr){
        p=p->next;
        cout<<p->data<<" ";
    }
    cout<<endl;

}//遍历单链表
int LinkList::GetLength(){
    int len=0;
    ListNode *p = head->next;
    while(p!=nullptr){
        len++;
        p=p->next;
    }
    return len;
}//获取线性表长度

bool LinkList::IsEmpty(){
    if(head->next==nullptr)
        return true;
    return false;
}//判断单链表是否为空

ListNode* LinkList::Find(int n){
    ListNode *p=head;
    if(p==nullptr){
        cout<<"NULL"<<endl;
        return nullptr;
    }
    else{
        while(p->next!=nullptr){
            if(p->data==n)
                return p;
            p=p->next;
        }
        return nullptr;
    }
}//查找节点

void LinkList::InsertAtEnd(int n){
    ListNode *pnew = new ListNode(n);
    ListNode *p = head;
    if(head==nullptr)
        head=pnew;
    else{
        while(p->next!=nullptr)
            p=p->next;
        p->next=pnew;
    }
}//尾部插入指定元素

void LinkList::InsertAtIndex(int pos,int n){
    if(pos<1||pos>GetLength())
        cout<<"ERROR"<<endl;
    else{
        ListNode *pnew = new ListNode;
        pnew->data=n;
        ListNode *p = head;
        int i=1;
        while(pos>i){//若为i-1则为后插
            p=p->next;
            i++;
        }
        pnew->next=p->next;
        p->next=pnew;
    }
}//在指定位置插入指定元素（前插）

void LinkList::InsertAtHead(int n){
    ListNode *pnew = new ListNode;
    pnew->data=n;
    ListNode *p=head;
    if(head==nullptr)
        head=pnew;
    pnew->next=p->next;
    p->next=pnew;
}//在头部插入指定元素

void LinkList::DeleteAtEnd(){
    ListNode *p=head;
    ListNode *ptemp=nullptr;
    if(p->next==nullptr)
        cout<<"NULL"<<endl;
    else{
        while(p->next!=nullptr){
            ptemp=p;   //结束时停在倒数第二个节点
            p=p->next;//结束时停在倒数第一个节点
        }
        delete p;
        p=nullptr;//防止其成为野指针
        ptemp->next=nullptr;
    }
}//删除尾部元素

void LinkList::DeleteAll(){
    ListNode *p = head->next;
    ListNode *ptemp=new ListNode;
    while(p!=nullptr){
        ptemp=p;
        p=p->next;
        head->next=p;
        ptemp->next=nullptr;//防止其成为野指针
        delete ptemp;
    }
    head->next=nullptr;
}//删除所有元素

void LinkList::DeleteAtHead(){
    ListNode *p=head;
    if(p==nullptr||p->next==nullptr)
        cout<<"NULL"<<endl;
    else{
        ListNode *ptemp=nullptr;
        p=p->next;
        ptemp=p->next;
        delete p;
        p=nullptr;
        head->next=ptemp;
    }
}//删除头部元素

void LinkList::DeleteAtPoint(int n){
    ListNode *ptemp = Find(n);
    if(ptemp==head->next)
        DeleteAtHead();
    else{
        ListNode *p=head;
        while(p->next!=ptemp)
            p=p->next;
        p->next=ptemp->next;
        delete ptemp;
        ptemp=nullptr;//防止其成为野指针
    }

}//删除指定数据元素

void LinkList::DeleteAtIndex(int pos){
    if(pos<1||pos>GetLength())
        cout<<"ERROR"<<endl;
    else{
        ListNode *ptemp = nullptr;
        ListNode *p = head;
        int i=0;
        while(pos>i){//
            ptemp=p;
            p=p->next;
            i++;
        }
        ptemp->next=p->next;
        delete p;
        p=nullptr;
    }
}//删除指定位置元素

void LinkList::ReverseList1(){
    ListNode *pre=nullptr;
	ListNode *p=nullptr;
	ListNode *pHead=head;
    while(pHead!=nullptr)
    {
        p=pHead->next;	//保存剩余链表
		pHead->next=pre;//断开剩余链表头结点pHead，指向pre
		pre=pHead;	//pre更新
		pHead=p;	//head更新
    }
    ListNode *pnew=new ListNode;
    pnew->next=pre;
    head=pnew;
    DeleteAtEnd();
}

ListNode* LinkList::ReverseList2(ListNode* pHead){
    if(pHead==NULL)
		return NULL;
	ListNode *p=pHead->next;
	ListNode *newHead=pHead;
	while(p!=NULL){			//将p结点移到链表最前方
		pHead->next=p->next;//头结点指向p的下一个结点
		p->next=newHead;	//p插入链表最前方
		newHead=p;		//链表新头结点更新为p
		p=pHead->next;//处理下一个结点，该结点位于头结点后
	}
	return newHead;
}








