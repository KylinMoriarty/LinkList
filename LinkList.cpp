#include "LinkList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

LinkList::LinkList(){
    head = new ListNode;
    head->next=nullptr;
    except = new ListNode;
    except->next=nullptr;
}//构建一个单链表，初始化头结点和处理异常的节点

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

bool LinkList::IsExistData(int n){
    ListNode *p=head->next;
    if(p==nullptr){
        cout<<"NULL"<<endl;
        return false;
    }
    else{
        while(p->next!=nullptr){
            if(p->data==n){
                cout<<"Exist"<<endl;
                return true;
            }
            p=p->next;
        }
        cout<<"Not Exist"<<endl;
        return false;
    }
}//查找指定数据节点


ListNode* LinkList::FindData(int n){
    ListNode *p=head->next;
    if(p==nullptr){
        cout<<"Not Exist"<<endl;
        return except;
    }
    else{
        while(p->next!=nullptr){
            if(p->data==n)
                return p;
            p=p->next;
        }
        cout<<"Not Exist"<<endl;
        return except;
    }
}//查找返回指定数据节点

ListNode* LinkList::FindIndex(int pos){
    ListNode *p=head;
    int i=1;
    if(p==nullptr||pos<1||pos>GetLength()){
        cout<<"Error"<<endl;
        return except;
    }
    else{
        while(p->next!=nullptr){
            if(i==pos)
                return p->next;
            i++;
            p=p->next;
        }
        return except;
    }
}//查找节点

ListNode* LinkList::FindReverseIndex(int pos){
    ListNode *pA=head;
    ListNode *pB=head;
    if(pA==nullptr||pos<1||pos>GetLength()){
        cout<<"Error"<<endl;
        return except;
    }
    else{
        for(int i=0;i<pos-1;i++){
            if(pA->next!=nullptr)
                pA=pA->next;
            else{
                cout<<"Error"<<endl;
                return except;
            }
        }
        while(pA->next!=nullptr){
                pA=pA->next;
                pB=pB->next;
            }
        return pB;
    }
}//查找倒数第几个节点

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

void LinkList::DeleteAtData(int n){
    ListNode *ptemp = FindData(n);
    if(ptemp==head->next)
        DeleteAtHead();
    else{
        ListNode *p=head;
        while(p->next!=ptemp&&p->next!=nullptr)
            p=p->next;
        if(p->next==ptemp){
            p->next=ptemp->next;
            delete ptemp;
            ptemp=nullptr;//防止其成为野指针
        }
        else
            return ;
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

void LinkList::ReverseList(){
    ListNode *pHead=head;
    if(pHead==nullptr)
		return ;
	ListNode *p=pHead->next;
	ListNode *pre=nullptr;      //反转之后的尾结点指向NULL，所以初始值为NULL
	while(p!=nullptr){			//执行到头结点
		pHead->next=p->next;    //保留下一个需要倒转的节点
		p->next=pre;	        //倒转，使当前节点指向原来前面的节点
		pre=p;		            //将pre换成当前节点，以便下一次操作
		p=pHead->next;          //处理下一个需要反转的节点
	}
    ListNode *pnew=new ListNode;
    pnew->next=pre;//添加头结点
    head=pnew;
}








