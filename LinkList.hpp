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
    LinkList();//构建一个单链表，初始化头结点
    ~LinkList();//销毁一个单链表
    ListNode* GetHead();//返回头结点
    void CreateLinkListAtEnd(int );//尾插法创建一个单链表
    void CreateLinkListAtHead(int );//头插法创建一个单链表
    void TraverLinkLIst();//遍历单链表
    int GetLength();//获取线性表长度
    bool IsEmpty();//判断单链表是否为空
    ListNode* Find(int );//查找节点
    void InsertAtEnd(int );//尾部插入指定元素
    void InsertAtIndex(int ,int );//在指定位置插入指定元素
    void InsertAtHead(int );//在头部插入指定元素
    void DeleteAtEnd();//删除尾部元素
    void DeleteAll();//删除所有元素
    void DeleteAtPoint(int );//删除指定数据元素
    void DeleteAtIndex(int );//删除指定位置元素
    void DeleteAtHead();//删除头部元素

    void ReverseList1();
    ListNode* ReverseList2(ListNode* );
private:
    ListNode *head;//头结点


};
#endif // LINKLIST_HPP_INCLUDED
