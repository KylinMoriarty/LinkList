#include "LinkList.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;

LinkList::LinkList(){
    head = new ListNode;
    head->next=nullptr;
    except = new ListNode;
    except->next=nullptr;
}//����һ����������ʼ��ͷ���ʹ����쳣�Ľڵ�

LinkList::~LinkList(){
    delete head;
}//����һ��������

ListNode* LinkList::GetHead(){
    return head;
}

void LinkList::CreateLinkListAtEnd(int n){
    ListNode *pnew,*ptemp;
    ptemp=head;
    if(n<0){
        cout<<"False"<<endl;//�������ֵ����ʱ�������쳣
        return ;
    }
    for(int i=0;i<n;i++){
        pnew = new ListNode;
        cout<<"�������"<<i+1<<"��ֵ��";
        cin>>pnew->data;
        pnew->next=nullptr;//�½ڵ���һ����ַΪNULL
        ptemp->next=pnew;//��ǰ�ڵ����һ����ַΪ�½ڵ�
        ptemp=pnew;//����ǰ�ڵ���Ϊ�½ڵ�
    }
}//β�巨����һ��������

void LinkList::CreateLinkListAtHead(int n){
    ListNode *pnew,*ptemp;
    ptemp=head;
    if(n<0){
        cout<<"False"<<endl;//�������ֵ����ʱ�������쳣
        return ;
    }
    for(int i=0;i<n;i++){
        pnew = new ListNode;
        cout<<"�������"<<i+1<<"��ֵ��";
        cin>>pnew->data;
        pnew->next=ptemp->next;
        ptemp->next=pnew;
    }
}//ͷ�巨����һ��������

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

}//����������
int LinkList::GetLength(){
    int len=0;
    ListNode *p = head->next;
    while(p!=nullptr){
        len++;
        p=p->next;
    }
    return len;
}//��ȡ���Ա���

bool LinkList::IsEmpty(){
    if(head->next==nullptr)
        return true;
    return false;
}//�жϵ������Ƿ�Ϊ��

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
}//����ָ�����ݽڵ�


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
}//���ҷ���ָ�����ݽڵ�

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
}//���ҽڵ�

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
}//���ҵ����ڼ����ڵ�

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
}//β������ָ��Ԫ��

void LinkList::InsertAtIndex(int pos,int n){
    if(pos<1||pos>GetLength())
        cout<<"ERROR"<<endl;
    else{
        ListNode *pnew = new ListNode;
        pnew->data=n;
        ListNode *p = head;
        int i=1;
        while(pos>i){//��Ϊi-1��Ϊ���
            p=p->next;
            i++;
        }
        pnew->next=p->next;
        p->next=pnew;
    }
}//��ָ��λ�ò���ָ��Ԫ�أ�ǰ�壩

void LinkList::InsertAtHead(int n){
    ListNode *pnew = new ListNode;
    pnew->data=n;
    ListNode *p=head;
    if(head==nullptr)
        head=pnew;
    pnew->next=p->next;
    p->next=pnew;
}//��ͷ������ָ��Ԫ��

void LinkList::DeleteAtEnd(){
    ListNode *p=head;
    ListNode *ptemp=nullptr;
    if(p->next==nullptr)
        cout<<"NULL"<<endl;
    else{
        while(p->next!=nullptr){
            ptemp=p;   //����ʱͣ�ڵ����ڶ����ڵ�
            p=p->next;//����ʱͣ�ڵ�����һ���ڵ�
        }
        delete p;
        p=nullptr;//��ֹ���ΪҰָ��
        ptemp->next=nullptr;
    }
}//ɾ��β��Ԫ��

void LinkList::DeleteAll(){
    ListNode *p = head->next;
    ListNode *ptemp=new ListNode;
    while(p!=nullptr){
        ptemp=p;
        p=p->next;
        head->next=p;
        ptemp->next=nullptr;//��ֹ���ΪҰָ��
        delete ptemp;
    }
    head->next=nullptr;
}//ɾ������Ԫ��

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
}//ɾ��ͷ��Ԫ��

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
            ptemp=nullptr;//��ֹ���ΪҰָ��
        }
        else
            return ;
    }

}//ɾ��ָ������Ԫ��

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
}//ɾ��ָ��λ��Ԫ��

void LinkList::ReverseList(){
    ListNode *pHead=head;
    if(pHead==nullptr)
		return ;
	ListNode *p=pHead->next;
	ListNode *pre=nullptr;      //��ת֮���β���ָ��NULL�����Գ�ʼֵΪNULL
	while(p!=nullptr){			//ִ�е�ͷ���
		pHead->next=p->next;    //������һ����Ҫ��ת�Ľڵ�
		p->next=pre;	        //��ת��ʹ��ǰ�ڵ�ָ��ԭ��ǰ��Ľڵ�
		pre=p;		            //��pre���ɵ�ǰ�ڵ㣬�Ա���һ�β���
		p=pHead->next;          //������һ����Ҫ��ת�Ľڵ�
	}
    ListNode *pnew=new ListNode;
    pnew->next=pre;//���ͷ���
    head=pnew;
}








