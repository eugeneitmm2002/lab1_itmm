#include <iostream>
#include <stack>
#include <cstdio>
#include <conio.h>

using namespace std;

int main()
{
    stack<char> left_brakes, right_brakes;
    char end('\0');
    
    while ((end = getchar()) != '\n')
    {   
        if (end == '(' || end == '[' || end == '{')
            left_brakes.push(end);
        else if (end == ')' || end == ']' || end == '}')
            right_brakes.push(end);
    }
   
    while (!left_brakes.empty() && !right_brakes.empty())
    {
       
        const char left(left_brakes.top());
        const char right(right_brakes.top());
        
        if (left == '(' && right == ')' || left == '{' && right == '}' || left == '[' && right == ']')
        { 
            left_brakes.pop();
            right_brakes.pop();
        }
        else 
            break;  
    }
    
    if (left_brakes.empty() && right_brakes.empty())
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;
    
    
    return 0;
}
