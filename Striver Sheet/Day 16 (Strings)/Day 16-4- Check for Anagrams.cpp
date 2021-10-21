/*
Anagram 
Easy Accuracy: 50.99% Submissions: 52947 Points: 2
Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are an anagram of each other or not. An anagram of a string is another string that contains the same characters, only the order of characters can be different. For example, “act” and “tac” are an anagram of each other.

Example 1:

Input:
a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same
characters with same frequency. So, 
both are anagrams.
Example 2:

Input:
a = allergy, b = allergic
Output: NO
Explanation:Characters in both the strings
are not same, so they are not anagrams.
Your Task:
You don't need to read input or print anything.Your task is to complete the function isAnagram() which takes the string a and string b as input parameter and check if the two strings are an anagram of each other. The function returns true if the strings are anagram else it returns false.

Expected Time Complexity: O(|a|+|b|).
Expected Auxiliary Space: O(Number of distinct characters).

Note: |s| represents the length of string s.

Constraints:
1 = |a|,|b| = 105
*/

/*
Method 1 (Use Sorting)  
Sort both strings
Compare the sorted strings
Time Complexity: O(nLogn)
*/

// C++ program to check whether two strings are anagrams
// of each other
#include <bits/stdc++.h>
using namespace std;

/* function to check whether two strings are anagram of
each other */
bool areAnagram(string str1, string str2)
{
	// Get lengths of both strings
	int n1 = str1.length();
	int n2 = str2.length();

	// If length of both strings is not same, then they
	// cannot be anagram
	if (n1 != n2)
		return false;

	// Sort both the strings
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	// Compare sorted strings
	for (int i = 0; i < n1; i++)
		if (str1[i] != str2[i])
			return false;

	return true;
}

// Driver code
int main()
{
	string str1 = "test";
	string str2 = "ttew";

	// Function Call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}




//Method 2 (Count characters) 
// C++ program to check if two strings
// are anagrams of each other
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

/* function to check whether two strings are anagram of
each other */
bool areAnagram(char* str1, char* str2)
{
	// Create 2 count arrays and initialize all values as 0
	int count1[NO_OF_CHARS] = { 0 };
	int count2[NO_OF_CHARS] = { 0 };
	int i;

	// For each character in input strings, increment count
	// in the corresponding count array
	for (i = 0; str1[i] && str2[i]; i++) {
		count1[str1[i]]++;
		count2[str2[i]]++;
	}

	// If both strings are of different length. Removing
	// this condition will make the program fail for strings
	// like "aaca" and "aca"
	if (str1[i] || str2[i])
		return false;

	// Compare count arrays
	for (i = 0; i < NO_OF_CHARS; i++)
		if (count1[i] != count2[i])
			return false;

	return true;
}

/* Driver code*/
int main()
{
	char str1[] = "geeksforgeeks";
	char str2[] = "forgeeksgeeks";

	// Function Call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}

// This is code is contributed by rathbhupendra




//Method 3 (count characters using one array) 
// C++ program to check if two strings
// are anagrams of each other
#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

bool areAnagram(char* str1, char* str2)
{
	// Create a count array and initialize all values as 0
	int count[NO_OF_CHARS] = { 0 };
	int i;

	// For each character in input strings, increment count
	// in the corresponding count array
	for (i = 0; str1[i] && str2[i]; i++) {
		count[str1[i]]++;
		count[str2[i]]--;
	}

	// If both strings are of different length. Removing
	// this condition will make the program fail for strings
	// like "aaca" and "aca"
	if (str1[i] || str2[i])
		return false;

	// See if there is any non-zero value in count array
	for (i = 0; i < NO_OF_CHARS; i++)
		if (count[i])
			return false;
	return true;
}

// Driver code
int main()
{
	char str1[] = "geeksforgeeks";
	char str2[] = "forgeeksgeeks";

	// Function call
	if (areAnagram(str1, str2))
		cout << "The two strings are anagram of each other";
	else
		cout << "The two strings are not anagram of each "
				"other";

	return 0;
}



