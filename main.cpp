#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    List<int>list;
    list.push_back(12);
    list.push_back(255);
    list.push_back(341);
    list.push_back(492);
    list.push_back(576);
    list.push_back(689);
    list.print_forward();
    list.print_backward();
    list.insert(619, 5);
    list.print_forward();
    list.print_backward();
    cout << "\tChecking function pop_front \n";
    list.pop_front();
    list.print_forward();
    list.print_backward();
    cout << "\n";
    cout << "\tChecking copy constructor \n";
    List<int>copy = move(list);
    copy.print_forward();
    copy.print_backward();
    cout << "\n";
    cout << "\tChecking function pop_back \n";
    cout << "Before   = ";
    list.print_forward();
    list.pop_back();
    cout << "After    = ";
    list.print_forward();
    cout << "Backward = ";
    list.print_backward();
    cout << "\n";
    list.push_back(784);
    cout << "\tChecking function pop_index \n";
    cout << "Before   = ";
    list.print_forward();
    list.pop_index(3);
    cout << "After    = ";
    list.print_forward();
    cout << "Backward = ";
    list.print_backward();
    cout << "\n";

    cout << "\tChecking creating from array \n";
    List<int>list2{ 1000,2800,3440,4170,5950,6001,7920 };
    cout << "After    = ";
    list2.print_forward();
    list2.pop_back();
    cout << "Backward = ";
    list2.print_backward();
    cout << "\n";

    cout << "\tChecking using operator = \n";
    List<int> list3 = list2;
    cout << "Before list3   = ";
    list3.print_forward();
    cout << "Backward  list3 = ";
    list3.print_backward();
    list3.insert(555, 4);
    cout << "After insert    = ";
    list3.print_forward();
    cout << "Backward        = ";
    list3.print_backward();
    cout << "\n";
    cout << "list2           = ";
    list2.print_forward();
      
    cout << "\tChecking bubble sort \n";
    List<int> list4{ 345, 12, 1112, 999, 75, 34, 176, 5, 7};
    cout << "Before list 4   = ";
    list4.print_forward();
    list4.sort_Bubble();
    cout << "\n";
    cout << "After sort      = ";
    list4.print_forward();
    cout << "Backward        = ";
    list4.print_backward();
    cout << "\n";
    
}