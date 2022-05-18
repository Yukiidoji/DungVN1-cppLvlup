#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int findsubstr(const char* str, char* sub);

int main()
{
    const char* str = "This is a parent STRING 2022";
	char sub[100];
	cout << "Input sub string:\n";
	cin >> sub;
    cout << "Starting point of the first sub string found is:\n";
	cout << findsubstr(str, sub);
	return 0;
}

/************************************************
Description: Find sub string in parent string
Input: 
    str: parent string
    sub: sub string
Return: 
     starting point of the first sub string if found
     or -1 if not found sub string
*************************************************/
int findsubstr(const char* str, char* sub)
{
    const char* pch;

        if (strlen(str) >= strlen(sub))
        {
            pch = strstr(str, sub);
            return pch != NULL ? pch - str : -1;
        }
 
    return -1;
}


/* solution 2
int findsubstr(const char* str, char* sub)
{
    const char* p = str;
    while(*p !=NULL)
    {
        if (strlen(p) >= strlen(sub))
        {
            if (strncmp(p, sub, strlen(sub)) == 0)
            {
                return (p - str);
            }
        }
        else
        {
            break;
        }
        p++;
    }    
    return -1;
}
*/


