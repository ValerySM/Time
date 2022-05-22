#include <iostream>
#include "MyTime.h"

using namespace std;




int main()
{
    MyTime t1;
    MyTime t2;
   
    
    int hour, minute, second;
    do 
    {
        
        cout << "Pleas enter first time: ";
        cin >> hour >> minute >> second;
    }

    while (!(t1.setMyTime(hour,minute,second)));
    do
    {

        cout << "Pleas enter second time: ";
        cin >> hour >> minute >> second;
    }

    while (!(t2.setMyTime(hour, minute, second)));
    
    
    cout <<endl<< "The erlyer time is: ";
    t1.earlyTime(t2)->printMyTime12();

    cout << endl<<"How many time you wanna add to the first time: ";
    cin >> hour >> minute >> second;
    t1.add(hour, minute, second);
    cout <<endl<< "New Time for firts time = ";
    t1.printMyTime12();
    cout << endl << "How many time you wanna add to the second time: ";
    cin >> hour >> minute >> second;
    t2.add(hour, minute, second);
    cout << endl << "New Time for second time = ";
    t2.printMyTime12();

    return 0;

}