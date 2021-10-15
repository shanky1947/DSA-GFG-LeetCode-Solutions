/*
Roman Number to Integer 
Easy Accuracy: 49.66% Submissions: 27604 Points: 2
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999

*/

//Roman to Integer

#include <bits/stdc++.h>
using namespace std;
 
// This function returns value
// of a Roman symbol
int value(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}
 
// Returns decimal value of
// roman numaral
int romanToDecimal(string& str)
{
    // Initialize result
    int res = 0;
 
    // Traverse given input
    for (int i = 0; i < str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = value(str[i]);
 
        if (i + 1 < str.length())
        {
            // Getting value of symbol s[i+1]
            int s2 = value(str[i + 1]);
 
            // Comparing both values
            if (s1 >= s2)
            {
                // Value of current symbol
                // is greater or equal to
                // the next symbol
                res = res + s1;
            }
            else
            {
                // Value of current symbol is
                // less than the next symbol
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;
}
 
// Driver Code
int main()
{
    // Considering inputs given are valid
    string str = "MCMIV";
    cout << "Integer form of Roman Numeral is "
        << romanToDecimal(str) << endl;
 
    return 0;
}



//Integer to Roman

// C++ Program to convert decimal number to
// roman numerals
#include <bits/stdc++.h>
using namespace std;

// Function to convert decimal to Roman Numerals
int printRoman(int number)
{
	int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
	string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
	int i=12;
	while(number>0)
	{
	int div = number/num[i];
	number = number%num[i];
	while(div--)
	{
		cout<<sym[i];
	}
	i--;
	}
}

//Driver program
int main()
{
	int number = 3549;

	printRoman(number);

	return 0;
}

