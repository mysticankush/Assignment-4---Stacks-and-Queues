/*  Program for Balanced Paranthesis
 * Compilation : gcc problem1.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 15-08-2021
 * Assignment_4 -> Stacks and Queues
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[100005];
int top=-1;
//Function to find the length of the string
int customstrlen(char* s)
{
    int size=0;
    while(s[size]!='\0')
    {
        size++;
    }
    return size;
}
//Function to push element in stack
void push(char c)
{
    top++;
    stack[top]=c;
}
//Function to pop element from stack
void pop()
{
    top--;
}
//Function to check whether stack is empty or not
bool isempty()
{
    if(top==-1)
    return true;
    else
    return false;
}
//Function to get top element of stack
int gettop()
{
    return stack[top];
}
//Function to check whether string is balanced or not
bool isValid(char * s){
    if(s == "") return true;
    int sz = customstrlen(s);
    for(int i = 0; i < sz; i++){
        if(s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
           push(s[i]);
        }
        else{
            //If the top of stack is same as the character present at ith position then pop else return false
            if(isempty())
            return false;
                if(s[i]==')')
                {
                    if(gettop()!='(')
                        return false;
                    else
                        pop();
                }
                else if(s[i]=='}')
                {
                    if(gettop()!='{')
                        return false;
                    else
                        pop();
                }
                else
                {
                    if(gettop()!='[')
                        return false;
                    else
                        pop();
                }
            }
        }
    if(isempty()) 
    return true;
    else 
    return false;
}

int main()
{
    char str[100005];

    //Taking input of the string
    printf("Enter the String : ");
    scanf("%s",str);
    
    bool ans = isValid(str);
    
    if(ans == true){
        printf("Balanced Paranthesis");
    }else{
        printf("Not Balanced Paranthesis"); 
    }
    
    
}
