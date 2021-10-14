/*
Reverse words in a given string 
Easy Accuracy: 50.0% Submissions: 64175 Points: 2
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 2000

*/


#include <bits/stdc++.h>
using namespace std;
 
void reverseWords(string s)
{
     
    vector<string> tmp;
    string str = "";
    for (int i = 0; i < s.length(); i++)
    {
         
        if (s[i] == ' ')
        {
            tmp.push_back(str);
            str = "";
        }
 
        else
            str += s[i];
    }
   
    tmp.push_back(str);
 
    int i;
    for (i = tmp.size() - 1; i > 0; i--)
        cout << tmp[i] << " ";
    cout << tmp[0] << endl;
}

int main()
{
    string s = "i like this program very much";
    reverseWords(s);
    return 0;
}
