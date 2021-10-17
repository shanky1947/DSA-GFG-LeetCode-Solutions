/*
Longest Common Prefix in an Array 
Easy Accuracy: 49.76% Submissions: 20477 Points: 2
Given a array of N strings, find the longest common prefix among all strings present in the array.


Example 1:

Input:
N = 4
arr[] = {geeksforgeeks, geeks, geek,
         geezer}
Output: gee
Explanation: "gee" is the longest common
prefix in all the given strings.
Example 2:

Input: 
N = 2
arr[] = {hello, world}
Output: -1
Explanation: There's no common prefix
in the given strings.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestCommonPrefix() which takes the string array arr[] and its size N as inputs and returns the longest common prefix common in all the strings in the array. If there's no prefix common in all the strings, return "-1".


Expected Time Complexity: O(N*max(|arri|)).
Expected Auxiliary Space: O(max(|arri|)) for result.


Constraints:
1 = N = 103
1 = |arri| = 103
*/

/*
https://www.geeksforgeeks.org/longest-common-prefix-using-sorting/

5 methods-
1-Word by Word Matching
2-Character by Character Matching
3-Divide and Conquer
4-Binary Search.
5-Using Trie
6-Sorting
*/

//Word by Word Matching
//TC- O(N M), SC- O(M)

// A C++ Program to find the longest common prefix
#include<bits/stdc++.h>
using namespace std;

// A Utility Function to find the common prefix between
// strings- str1 and str2
string commonPrefixUtil(string str1, string str2)
{
	string result;
	int n1 = str1.length(), n2 = str2.length();

	// Compare str1 and str2
	for (int i=0, j=0; i<=n1-1&&j<=n2-1; i++,j++)
	{
		if (str1[i] != str2[j])
			break;
		result.push_back(str1[i]);
	}

	return (result);
}

// A Function that returns the longest common prefix
// from the array of strings
string commonPrefix (string arr[], int n)
{
	string prefix = arr[0];

	for (int i=1; i<=n-1; i++)
		prefix = commonPrefixUtil(prefix, arr[i]);

	return (prefix);
}

// Driver program to test above function
int main()
{
	string arr[] = {"geeksforgeeks", "geeks",
					"geek", "geezer"};
	int n = sizeof(arr) / sizeof(arr[0]);

	string ans = commonPrefix(arr, n);

	if (ans.length())
		printf ("The longest common prefix is - %s",
				ans.c_str());
	else
		printf("There is no common prefix");

	return (0);
}


//Sorting-
//TC- O(MAX * n * log n )

// C++ program to find longest common prefix
// of given array of words.
#include<iostream>
#include<algorithm>

using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(string ar[], int n)
{

	// If size is 0, return empty string
	if (n == 0)
		return "";

	if (n == 1)
		return ar[0];

	// Sort the given array
	sort(ar, ar + n);

	// Find the minimum length from
	// first and last string
	int en = min(ar[0].size(),
				ar[n - 1].size());

	// Now the common prefix in first and
	// last string is the longest common prefix
	string first = ar[0], last = ar[n - 1];
	int i = 0;
	while (i < en && first[i] == last[i])
		i++;

	string pre = first.substr(0, i);
	return pre;
}

// Driver Code
int main()
{
	string ar[] = {"geeksforgeeks", "geeks",
						"geek", "geezer"};
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << "The longest common prefix is: "
		<< longestCommonPrefix(ar, n);
	return 0;
}




