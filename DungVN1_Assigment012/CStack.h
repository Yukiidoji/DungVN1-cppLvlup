#pragma once
#include <iostream>


using namespace std;

#define MAX_SIZE 100

class CStack
{
private:
    int stack[MAX_SIZE];   
    int size = 0;          
public:
    CStack(){};
    ~CStack(){};
    void Push(int x);
    int Pop();
    void Show();
};
