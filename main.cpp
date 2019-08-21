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
    //L1.DeleteAll();
   // L1.IsExistData(7);
   // L1.IsExistData(0);
   // L1.IsExistData(1);
   // L1.DeleteAtData(7);
    cout<<L1.FindReverseIndex(0)->data<<endl;
     cout<<L1.FindReverseIndex(1)->data<<endl;
      cout<<L1.FindReverseIndex(6)->data<<endl;
       cout<<L1.FindReverseIndex(7)->data<<endl;
    L1.ReverseList();
    L1.TraverLinkLIst();

   // L2.CreateLinkListAtHead(5);
   // L2.TraverLinkLIst();
    return 0;
}
