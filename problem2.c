/*  Program for converting an arithmetic expression from infix to postfix
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
int precedence(char ch) {
    // since precedence of '+' & '-' is same
    if(ch == '+' || ch == '-')
	return 1;
    // since precedence of '*' & '/' is same
    else if(ch == '*' || ch == '/')
	return 2;
    else
	return -1;
}
void infixToPostfix(char *s)
{
    int sz=customstrlen(s);
    char ans[100];
    
    int idx=0;
    
    for(int i=0;i<sz;i++) 
    {
    //Skip all the white spaces
    while(i<sz && s[i]==' ')
    i++;
	// if character is not an operator directly add it into result
	if((s[i] >= '0' && s[i] <= '9'))
		ans[idx++]=s[i];

	else if(s[i] == '(')
		push(s[i]);

	else if(s[i] == ')') {
	    while(gettop() != '(')
		{
		    ans[idx++]=gettop();
		    pop();
		}
	    pop();
	}

	//If an operator then placed according to precedence
	else {
	     while(!isempty() && precedence(s[i]) <= precedence(gettop())) {
	         // adding to result
		 ans[idx++]=gettop();
		 pop();
		}
	    push(s[i]);
	}

	}

	// adding all the remaining characters answer string
	while(!isempty()) {
	    ans[idx++]=gettop();
	    pop();
	}

      ans[idx]='\0';

      printf("%s",ans);
}
int main() {
    
    printf("Enter string : ");
    char exp[100];
    scanf("%s",exp);
    infixToPostfix(exp);
    printf("\n");
    return 0;
}
