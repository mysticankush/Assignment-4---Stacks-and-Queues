/*  Program for Sliding Window Maximum
 * Compilation : gcc problem6.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 15-08-2021
 * Assignment_4 -> Stacks and Queues
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int dequeue[100005];
int front=0;
int back=-1;
//get front element of deque
int getfront()
{
    return front;
}
//get back element of deque
int getback()
{
    return back;
}
//push element at last in deque
void push(int val)
{
    back++;
    dequeue[back]=val;
}
//pop element from deque
void pop()
{
    front++;
}
//get max of two numbers
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize){
    *returnSize=0;
    int n=numsSize;
    int *ans = (int*) calloc(numsSize, sizeof(int));
    int l=k-1;
    //push first subarray in the deque
    for(int i=0;i<=l;i++)
        push(i);
    int idx=0;
    while(l<n)
    {
        int temp=getfront();
        int temp1=getback();
        int mx=-1e9;
        //range of idxth subarray
        for(int j=temp;j<=temp1;j++)
        {
            mx=max(mx,nums[j]);
        }
        ans[idx++]=mx;
        l++;a
        push(l);
        pop();
        (*returnSize)++;
    }
    front=0;
    back=-1;
    return ans;
}
