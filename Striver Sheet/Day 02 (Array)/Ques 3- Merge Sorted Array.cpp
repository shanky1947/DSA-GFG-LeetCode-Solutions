/*
Q Link- https://leetcode.com/problems/merge-sorted-array/

88. Merge Sorted Array
Easy

3889

374

Add to List

Share
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

 

Example 1:

Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
Example 2:

Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:

Input: nums1 = [0], m = 0, nums2 = [1], n = 1
Output: [1]
Explanation: The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

Constraints:

nums1.length == m + n
nums2.length == n
0 <= m, n <= 200
1 <= m + n <= 200
-109 <= nums1[i], nums2[j] <= 109
 

Follow up: Can you come up with an algorithm that runs in O(m + n) time?

Accepted
1,306,490
Submissions
2,999,805
*/




//BRUTE FORCE
//APPROACH- USING SORT FUNCTION, ADD 2ND ARRAY NO.S TO 1ST ARRAY AND USE SORT FUNCTION
//TC- O(m+nlogn)
//SC- O(1)


//BETTER
//APPROACH- REPLACE 2ND ARRAY ELEMENT INTO 1ST IF SMALLER AND SORT 2ND ARRAY USING INSERTION SORT
//TC- O(n*m)
//SC- O(1)

class Solution {
public:
    void merge(vector<int>& arr1, int n, vector<int>& arr2, int m) {
        if(arr2.size()==0)
            return ;
          int i, k;
        for (i = 0; i < n; i++) {
            if (arr1[i] > arr2[0]) {
              int temp = arr1[i];
              arr1[i] = arr2[0];
              arr2[0] = temp;
            }

            // then sort the second array
            int first = arr2[0];
            // insertion sort is used here
            for (k = 1; k < m && arr2[k] < first; k++) {
              arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
        for(int i=n, k=0; k<m; i++, k++){
            arr1[i]=arr2[k];
        }
    }
};


//BEST
//APPROACH- GAP METHOD
//TC- O(logn)
//SC- O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(nums2.size()==0)
            return;
        int gap = ceil((float)(n + m)/2);
        while(gap>0){
            int i=0, k=gap;
            while(k<m){
                if(nums1[i]>nums1[k])
                    swap(nums1[i], nums1[k]);
                i++;    k++;
            }
            k=k-m;
            while(i<m && k<n){
                if(nums1[i]>nums2[k])
                    swap(nums1[i], nums2[k]);
                i++;    k++;
            }
            i=0;
            while(k<n){
                if(nums2[i]>nums2[k])
                    swap(nums2[i], nums2[k]);
                i++;    k++;
            }
            if(gap==1)   //as ceil(1/2=0.5)==1, infinte loop
                gap=0;
            gap=ceil((float)(gap)/2);    //ceil as 3/2=1.5=1, missed one iteration
        }
        for(int i=m, k=0;k<n; i++, k++)
            nums1[i]=nums2[k];
    }
};