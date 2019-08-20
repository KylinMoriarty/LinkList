#include <iostream>
#include "LinkList.hpp"
using namespace std;

int main()
{
    LinkList L1,L2;
    L1.CreateLinkListAtEnd(5);
    L1.InsertAtIndex(1,6);
    L1.TraverLinkLIst();
    //L1.DeleteAtIndex(2);
    L1.ReverseList1();
    //L1.DeleteAll();
   // cout<<L1.GetLength()<<endl;
    L1.TraverLinkLIst();

   // L2.CreateLinkListAtHead(5);
   // L2.TraverLinkLIst();
    return 0;
}
