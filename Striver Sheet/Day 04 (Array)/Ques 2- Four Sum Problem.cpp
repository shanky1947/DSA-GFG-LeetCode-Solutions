/*
Q Link- https://leetcode.com/problems/4sum/

18. 4Sum
Medium

5901

674

Add to List

Share
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.

 

Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
 

Constraints:

1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
Accepted
562,962
Submissions
1,514,338
*/


//BRUTE FORCE
//APPROACH- USE TWO LOOPS, FOR EACH NO IN I, FIND TARGET-I IN J
//TC- O(n*n)
//SC- O(1)



//BETTER
//APPROACH- BIANRY SEARCH, USE 3 LOOPS AND FOR LAST NUMBER USE BINARY SEARCH
//TC- O(nlogn + n^3logn)
//SC- O(1)

class Solution {
public:
    int binarySearch(vector<int>& nums, int si, int ei, int target){
        int mid=(si+ei)/2;
        if(si<=ei){
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                return binarySearch(nums, mid+1, ei, target);
            else if(nums[mid]>target)
                return binarySearch(nums, si, mid-1, target);
        }
        return -1;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        set<vector<int>> temp;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    
                    int index=binarySearch(nums, k+1, n-1, target-((long)nums[i]+nums[j]+nums[k]));
                    if(index!=-1){
                        temp.insert({nums[i], nums[j], nums[k], nums[index]});
                    }
                }
            }
        }
        
        set<vector<int>>::iterator itr;
        for(itr=temp.begin(); itr!=temp.end(); itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};


//BEST
//APPROACH- TWO POINTER APPROACH, USE TWO LOOPS, THEN FOR OTHER TWO NUMBERS, USE TWO POINTERS, ALSO SORT ARRAY
//TC- O(2n)
//SC- O(n)

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> temp;
        
        for(int k=0;k<n;k++){
            for(int l=k+1;l<n;l++){
                int i=l+1, j=n-1;
                int no=target-(nums[k]+nums[l]);
                while(i<j){
                    if(nums[i]+nums[j]==no){
                        temp.insert({nums[k], nums[l], nums[i], nums[j]});
                        i++, j--;
                    }
                    else if(nums[i]+nums[j]>no)
                        j--;
                    else
                        i++;
                }
            }
        }
        vector<vector<int>> ans;
        set<vector<int>>::iterator itr;
        for(itr=temp.begin(); itr!=temp.end(); itr++){
            ans.push_back(*itr);
        }
        return ans;
    }
};