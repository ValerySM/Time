//
// Created by Valery Sokolov on 3/25/2022.
//

#ifndef MYTIME_MYTIME_H
#define MYTIME_MYTIME_H
#include <iostream>




class MyTime {
private:
    int hour; //hour
    int minute; //minutes
    int second; //seconds
public:
    MyTime(); //constructor time

    MyTime(int, int, int);
    MyTime(int, int);
    MyTime(const MyTime& origTime);
    bool setMyTime(int, int, int);//hour,minute and second
    bool setMyTime(const MyTime& origTime);
    void printMyTime24() const; //time in 24 on screen
    void printMyTime12() const; //time in 12 on screen
    void add(int hour, int min, int sec);
    MyTime* earlyTime(MyTime&);


};
#endif