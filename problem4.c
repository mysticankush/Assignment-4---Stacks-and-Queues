/*  Program To find largest rectangle in a Histogram
 * Compilation : gcc problem4.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 15-08-2021
 * Assignment_4 -> Stacks and Queues
*/
int top=-1;
int stack[100005];
//Function to check whether stack is empty is not
bool isempty()
{
    if(top<=-1)
        return true;
    else
        return false;
}
//Function to get top element of stack
int gettop()
{
    return stack[top];
}
//Function to pop from stack
void pop()
{
    top--;
}
//Function to push into stack
void push(int val)
{
    top++;
    stack[top]=val;
}
int largestRectangleArea(int* heights, int heightsSize){
    
    int prevsmaller[heightsSize],nextsmaller[heightsSize];
    //Making of previousmaller array which will have previous smaller value of ith         position
    prevsmaller[0]=-1;
    push(0);
    for(int i=1;i<heightsSize;i++)
    {
        while(!isempty() && heights[gettop()]>=heights[i])
        {
            pop();
        }
        if(isempty())
        {
            prevsmaller[i]=-1;
        }
        else
        {
            prevsmaller[i]=gettop();
        }
        push(i);
    }
    top=-1;
    push(heightsSize-1);
    //making of nextsmaller array which will have next smaller value of ith position
    nextsmaller[heightsSize-1]=heightsSize;
    for(int i=heightsSize-2;i>=0;i--)
    {
        while(!isempty() && heights[gettop()]>=heights[i])
        {
            pop();
        }
        if(isempty())
        {
            nextsmaller[i]=heightsSize;
        }
        else
        {
            nextsmaller[i]=gettop();
        }
        push(i);
    }
    int ans=0;
    for(int i=0;i<heightsSize;i++)
    {
        //taking the subarray from previoussmaller[i]+1 to nextsmaller[i]-1 in which            height[i] will be the minimum height. Therefore we will multiply that height
        if((nextsmaller[i]-prevsmaller[i]-1)*heights[i]>ans)
            ans=(nextsmaller[i]-prevsmaller[i]-1)*heights[i];
    }
    top=-1;
    return ans;
}
