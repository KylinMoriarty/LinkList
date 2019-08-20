#ifndef LINKLIST_HPP_INCLUDED
#define LINKLIST_HPP_INCLUDED

#include <cstdlib>
#include <vector>
using namespace std;

typedef unsigned long long ULL;

struct ListNode {
	int data;
	struct ListNode *next;
	ListNode(){}
	ListNode(int x) : data(x), next(NULL) {}
};

class LinkList{
public:
    LinkList();//����һ����������ʼ��ͷ���
    ~LinkList();//����һ��������
    ListNode* GetHead();//����ͷ���
    void CreateLinkListAtEnd(int );//β�巨����һ��������
    void CreateLinkListAtHead(int );//ͷ�巨����һ��������
    void TraverLinkLIst();//����������
    int GetLength();//��ȡ���Ա���
    bool IsEmpty();//�жϵ������Ƿ�Ϊ��
    ListNode* Find(int );//���ҽڵ�
    void InsertAtEnd(int );//β������ָ��Ԫ��
    void InsertAtIndex(int ,int );//��ָ��λ�ò���ָ��Ԫ��
    void InsertAtHead(int );//��ͷ������ָ��Ԫ��
    void DeleteAtEnd();//ɾ��β��Ԫ��
    void DeleteAll();//ɾ������Ԫ��
    void DeleteAtPoint(int );//ɾ��ָ������Ԫ��
    void DeleteAtIndex(int );//ɾ��ָ��λ��Ԫ��
    void DeleteAtHead();//ɾ��ͷ��Ԫ��

    void ReverseList1();
    ListNode* ReverseList2(ListNode* );
private:
    ListNode *head;//ͷ���


};
#endif // LINKLIST_HPP_INCLUDED
