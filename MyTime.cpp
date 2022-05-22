//
// Created by Valery Sokolov on 3/25/2022.
//


#include <iostream>
#include "MyTime.h" // time class definition
#include <iomanip>

using namespace std;


MyTime::MyTime()
{
    hour = 0;//variable hour intialized
    minute = 0;//variable minute intialized
    second = 0;//variable second initialized
}

MyTime::MyTime(int hour, int minute, int second)
{
    if (!setMyTime(hour, minute, second))
        MyTime();
    
    
}
MyTime::MyTime(int hour, int minute)
{
    MyTime(hour, minute, 0);

}


MyTime::MyTime(const MyTime& origTime)
{
    MyTime(origTime.hour, origTime.minute, origTime.second);
}

bool MyTime::setMyTime(int h, int m, int s)

{
    if (!(h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60))
        return false;
    
    this->hour = h;
    this->minute = m;
    this->second = s;
    return true;
}

bool MyTime::setMyTime(const MyTime& origTime)
{
    return setMyTime(origTime.hour,origTime.minute,origTime.second);
}

void MyTime::printMyTime24() const //printing time
{ //function printf is initialized

    std::cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;

}
void MyTime::printMyTime12() const //printing time
{ //function printf is initialized
    /*if (hour > 12)
    {
        int AMPM = 0;
        AMPM = hour % 12;
        std::cout << setfill('0') << setw(2) << AMPM << ":" <<setfill('0')<<setw(2)<< minute << ":" << setfill('0') << setw(2) << second;
    }
    else 
    std::cout << setfill('0') << setw(2) << hour << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second;*/
    std::cout << setfill('0') << setw(2) << ((hour<12)?hour:(hour-12)) 
        << ":" << setfill('0') << setw(2) << minute << ":" << setfill('0') << setw(2) << second
        << ((hour < 12) ? " AM" : " PM");
}

void MyTime::add(int hour, int min, int sec)
{
    
    this->hour += hour;
    this->minute += min;
    this->second += sec;
    this->minute += this->second / 60;
    this->second %= 60;
    this->hour += this->minute / 60;
    this->minute %= 60;
    this->hour %= 24;
    
    
}

MyTime* MyTime::earlyTime(MyTime& other)
{
    if (other.hour < this->hour)
        return &other;
    if (other.minute < this->minute)
        return &other;
    if (other.second < this->second)
        return &other;
    return this;
}
