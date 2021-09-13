#include <iostream>

// Recursive implementation of Binary Search Algorithm to return
// the position of target x in the sub-array array[low..high]
int binarySearch(int array[], int low, int high, int key)
{
    // Base condition (search space is exhausted)
    if (low > high)
        return -1;
 
    // we find the mid value in the search space and
    // compares it with target value
    
      /*[Note: we can also use low + (high - low)/2  to avoid overflow. 
        Consider an example where the data type of the low and high is integer. 
        So integer has an upper range of 65535 if it is an unsigned integer. 
        Now consider the value of low as 2048 and high as 65530. 
        Now if you calculate  (low + high) .Clearly 65530 + 2048 is larger that 65535 (max value stored in 2 bytes) 
        and this would result in an overflow, 
        So, it will give you a wrong result due to overflow of integer data type. 
        Now if you calculate mid as low + ( high -low )/2 , 
        it will give you a correct result]*/
 
    int mid = (low + high)/2;    // overflow can happen
    // int mid = low + (high - low)/2;
 
    // Base condition (target value is found)
    if (key == array[mid])
        return mid;
 
    // discard all elements in the right search space
    // including the mid element
    else if (key < array[mid])
        return binarySearch(array, low,  mid - 1, key);
 
    // discard all elements in the left search space
    // including the mid element
    else
        return binarySearch(array, mid + 1,  high, key);
}
 
// Recursive implementation of Binary Search Algorithm
int main(void)
{
    int array[] = { 2, 5, 6, 8, 9, 10 };
    int target = 5;
 
    int n = sizeof(array)/sizeof(array[0]);
 
    int low = 0, high = n - 1;
    int index = binarySearch(array, low, high, target);
 
    if (index != -1)
        printf("Element found at index %d", index);
    else
        printf("Element not found in the array");
 
    return 0;
}
/* Try more Inputs
case 1: 
actual = binarySearch([16, 19, 20, 23, 45, 56, 78, 90, 96, 100],0,9,45)
expected = 4

case2: 
 actual = binarySearch([2, 3, 4, 10, 40],0,4,10)
 expected = 3
 
case3: 
actual = binarySearch([3, 4, 5, 6, 7, 8, 9],0,6,4)
expected = 1
*/


/* ---------------Iterative approach--------------
binarySearch(array, int x)
    low = 0, high = array.length - 1;
    while (low <= high)
        int mid = low + ((high-low)/2);
        if (x == array[mid]) 
            return mid
        else if (x < array[mid])
            high = mid - 1;
        else
            low = mid + 1
    return -1
*/
