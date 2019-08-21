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
    bool IsExistData(int);//�����Ƿ����ָ�����ݽڵ�
    ListNode* FindIndex(int );//����ָ�����ݽڵ�
    ListNode* FindReverseIndex(int );//���ҵ�����ָ�������ݽڵ�
    void InsertAtEnd(int );//β������ָ��Ԫ��
    void InsertAtIndex(int ,int );//��ָ��λ�ò���ָ��Ԫ��
    void InsertAtHead(int );//��ͷ������ָ��Ԫ��
    void DeleteAtEnd();//ɾ��β��Ԫ��
    void DeleteAll();//ɾ������Ԫ��
    void DeleteAtData(int );//ɾ��ָ������Ԫ��
    void DeleteAtIndex(int );//ɾ��ָ��λ��Ԫ��
    void DeleteAtHead();//ɾ��ͷ��Ԫ��

    void ReverseList();//��ת����

private:
    ListNode *head;//ͷ���
    ListNode *except;//�����쳣
    ListNode* FindData(int );//���ҷ���ָ�����ݽڵ�

};
#endif // LINKLIST_HPP_INCLUDED
