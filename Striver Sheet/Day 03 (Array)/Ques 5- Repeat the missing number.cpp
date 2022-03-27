/*
Q Link- https://www.interviewbit.com/problems/repeat-and-missing-number-array/

Repeat and Missing Number Array
Medium

227

24

Add to favorites
Asked In:
AMAZON
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.

This is one of those problems.

Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105

Food for thought :

Even though it might not be required in this problem, in some cases, you might be required to order the operations cleverly so that the numbers do not overflow.
For example, if you need to calculate n! / k! where n! is factorial(n), one approach is to calculate factorial(n), factorial(k) and then divide them.
Another approach is to only multiple numbers from k + 1 ... n to calculate the result.
Obviously approach 1 is more susceptible to overflows.
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4
*/



//BETTER
//APPROACH- FIRST FIND DUPLICATE, THEN (SUM FROM 1 TO N)-(SUM OF ARRAY-DUPLICATE NO.)=MISSING NUMBER
//TC- O(3N)
//SC- O(1)


//BETTER
//APPROACH- X-Y=S1, X*X-Y*Y=S2 GET VALUE X+Y FROM HERE, THEN FIND VALUE OF X AND Y BY SOLVING BOTH, X-SUM FROM 1-N, Y-SUM OF ARRAY
//TC- O(N)
//SC- O(1)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long s1=0, s2=0;
    long long x=0, y=0;
    long long xx=0, yy=0;
    long long n=A.size();

    for(int i=0;i<n;i++){
        x=x+(long long)A[i];
        xx=xx+(long long)(A[i]*A[i]);
    }
    y=(n*(long long)(n+1))/(long long)2;
    yy=(n*(long long)(n+1)*(long long)(2*n+1))/(long long)6;

    s1=abs(x-y);
    s2=abs(xx-yy);

    int xno=(s1+s2)/2;
    int yno=(s2-s1)/2;

    vector<int> ans;
    ans.push_back(yno);
    ans.push_back(xno);
    return ans;
}



//BEST
//APPROACH- USING XOR-> X-Y=NUM, X-XOR OF ARRAY NOS, Y-XOR OF TOTAL NOS, TAKE NOS WHOSE 1ST BIT IS SET AS NUM IN 1 BASKET(1ST NO), REST IN OTHERS(2ND NO)
//TC- O(n)
//SC- O(1)

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    int x=A[0];
    int n=A.size();
    for(int i=1;i<n;i++){
        x=x^A[i];
    }
    int y=1;
    for(int i=2;i<=n;i++){
        y=y^i;
    }
    int num=x^y;
    //Getting the right most set bit of num- and from negation, -1 will make set bit as unset and
    //negation will make it set again hence set after end
    int setBitNo = num & ~(num - 1);

    int set1=0, set2=0;
    for(int i=0;i<n;i++){
        if(A[i] & setBitNo)    //setBitNo has 1000.., so output will be if 1st bit is set
            set1=set1^A[i];
        else
            set2=set2^A[i];
    }
    for(int i=1;i<=n;i++){
        if(i & setBitNo)
            set1=set1^i;
        else
            set2=set2^i;
    }
    int xno=set1;
    int yno=set2;

    int xcount=0;
    for(int i=0;i<n;i++){
        if(A[i]==xno)
            xcount++;
    }
    if(xcount>0)
        return {xno, yno};
    return {yno, xno};
}
