/*  Program to find minimum element of stack
 * Compilation : gcc problem5.c
 * Execution : ./a.out
 *
 * Ankush Chhabra 1910990144 15-08-2021
 * Assignment_4 -> Stacks and Queues
*/
typedef struct {
    int value;      
    int mn;
} MinStack;

/** initialize your data structure here. */
int sz;
MinStack* minStackCreate() {
    MinStack *stack = (MinStack *)malloc(1000000 * sizeof(MinStack)); 
    sz = 0;
    return stack;
}

void minStackPush(MinStack* obj, int val) {
    obj[sz].value = val;
    //If sz is 0 then it means val is already minimum
    if(sz==0)
    {
        obj[sz].mn = val;
    }
    else
    {
        // update the minimum element
        obj[sz].mn = val < minStackGetMin(obj) ? val : minStackGetMin(obj);
    }
    sz++;
}

void minStackPop(MinStack* obj) {
  sz--;
}

int minStackTop(MinStack* obj) {
  return obj[sz-1].value;
}

int minStackGetMin(MinStack* obj) {
  return obj[sz-1].mn;
}

void minStackFree(MinStack* obj) {
  free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
