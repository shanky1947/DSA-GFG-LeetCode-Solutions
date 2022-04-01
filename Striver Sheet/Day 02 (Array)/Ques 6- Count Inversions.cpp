/*
Q Link- https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems

Count Inversions
Difficulty: MEDIUM
Contributed By
Deep Mavani
|
Level 1
Avg. time to solve
40 min
Success Rate
55%
Problem Statement
For a given integer array/list 'ARR' of size 'N', find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair ('ARR[i]', 'ARR[j]') is said to be an inversion when:

1. 'ARR[i] > 'ARR[j]' 
2. 'i' < 'j'

Where 'i' and 'j' denote the indices ranging from [0, 'N').
Input Format :
The first line of input contains an integer 'N', denoting the size of the array.

The second line of input contains 'N' integers separated by a single space, denoting the elements of the array 'ARR'.
Output Format :
Print a single line containing a single integer that denotes the total count of inversions in the input array.
Note:
You are not required to print anything, it has been already taken care of. Just implement the given function.  
Constraints :
1 <= N <= 10^5 
1 <= ARR[i] <= 10^9

Where 'ARR[i]' denotes the array element at 'ith' index.

Time Limit: 1 sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation Of Sample Output 1:
We have a total of 3 pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4
Explanation Of Sample Output 1:
We have a total of 4 pairs which satisfy the condition of inversion. (2, 1), (5, 1), (5, 3) and (5, 4).
*/



//BRUTE FORCE
//APPROACH- USE TWO LOOPS
//TC- O(n*n)
//SC- O(1)

//BEST
//APPROACH- USE MERGE SORT CONCEPT TO CALCULATE SMALLER NUMBERS IN RIGHT PART-> (MID-I+1)
//TC- O(n*logn)
//SC- O(1)

long long merge(long long *arr, int si, int mid, int ei){
    int i=si, j=mid+1, k=0;
    int temp[ei-si+1];
    int count=0;
    while(i<=mid && j<=ei){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
            count+=(mid-i+1);
        }
    }
    while(i<=mid)
        temp[k++]=arr[i++];
   	while(j<=ei)
        temp[k++]=arr[j++];
   	for(int i=si, k=0; i<=ei; i++, k++)
        arr[i]=temp[k];
    return count;
}

long long mergeSort(long long *arr, int si, int ei){
    int count=0;
    if(si<ei){
        int mid=(si+ei)/2;
        count+=mergeSort(arr, si, mid);
        count+=mergeSort(arr, mid+1, ei);
        count+=merge(arr, si, mid, ei);
    }
    return count;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}