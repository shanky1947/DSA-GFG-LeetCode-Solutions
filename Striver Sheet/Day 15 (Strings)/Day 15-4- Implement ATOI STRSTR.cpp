/*
Implement Atoi 
Medium Accuracy: 32.9% Submissions: 81492 Points: 4
Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.

Note: You are not allowed to use inbuilt function.

Example 1:

Input:
str = 123
Output: 123
Example 2:

Input:
str = 21a
Output: -1
Explanation: Output is -1 as all
characters are not digit only.
Your Task:
Complete the function atoi() which takes a string as input parameter and returns integer value of it. if the input string is not a numerical string then returns -1.

Expected Time Complexity: O(|S|), |S| = length of string str.
Expected Auxiliary Space: O(1)

Constraints:
1 = length of S = 10
*/


// ATOI
#include <bits/stdc++.h>
using namespace std;

int myAtoi(char* str)
{
	int res = 0;

	int sign = 1;

	int i = 0;

	// If number is negative,
	// then update sign
	if (str[0] == '-') {
		sign = -1;

		// Also update index of first digit
		i++;
	}

	// Iterate through all digits
	// and update the result
	for (; str[i] != '\0'; ++i){
	    if(str[i]>='0' && str[i]<='9')
	        res = res * 10 + str[i] - '0';
	    else
	        return -1;
	}
		

	// Return result with sign
	return sign * res;
}

// Driver code
int main()
{
	char str[] = "-123";

	// Function call
	int val = myAtoi(str);
	cout << val;
	return 0;
}


//STRSTR
//Based on KMP algorithm
