/*
Q Link- https://leetcode.com/problems/merge-intervals/

56. Merge Intervals
Medium

12692

504

Add to List

Share
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
Accepted
1,352,881
Submissions
3,029,924
*/


//BRUTE FORCE
//APPROACH- USE TWO FOR LOOPS
//TC- O(n*n)
//SC- O(1)



//BETTER 
//APPROACH- USE TEMP VARIBLE TO STORE COMBINED INTERVAL
//TC- O(n)
//SC- O(1)

class Solution {
public:
    // bool static func(vector<int> a, vector<int> b){
    //     if(a[0]<b[0])
    //         return true;
    //     else if(a[0]==b[0] && a[1]<b[1])
    //         return true;
    //     return false;
    // }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end(), func);
        //func function no needed in sort of stl
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> temp=intervals[0];
        for(auto it:intervals){
            if(it[0]<=temp[1]){
                temp[1]=max(temp[1],it[1]);
            }
            else{
                ans.push_back(temp);
                temp=it;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};



//BEST
//APPROACH- TWO POINTER APPROACH, USED ITH ONE AS TEMP
//TC- O(n)
//SC- O(1)

class Solution {
public:
    bool static func(vector<int> a, vector<int> b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), func);
        vector<vector<int>> ans;
        int i=0, j=1;
        int n=intervals.size();
        while(i<n && j<n){
            if(intervals[i][1]>=intervals[j][0]){
                intervals[i][1]=max(intervals[i][1], intervals[j][1]);
                j++;
            }
            else{
                ans.push_back(intervals[i]);
                i=j;
                j++;
            }
        }
        if(i<n)
            ans.push_back(intervals[i]);
        return ans;
    }
};

