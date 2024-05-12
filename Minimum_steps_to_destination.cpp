/*
Given an infinite number line. You start at 0 and can go either to the left or to the right. The condition is that in the ith move, you must take i steps. Given a destination d, find the minimum number of steps
required to reach that destination.

Example 1:

Input: d = 2

Output: 3

Explaination: The steps takn are +1, -2 and +3.

Example 2:

Input: d = 10

Output: 4

Explaination: The steps are +1, +2, +3 and +4.

Your Task:
You do not need to read input or print anything. Your task is to complete the function minSteps() which takes the value d as input parameter and returns the minimum number of steps required to reach the
destination d from 0.

Expected Time Complexity: O(d)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ d ≤ 10000
*/

class Solution 
{
    public:
        int minSteps(int d) 
        {
            int ans=0;
            int i=0;
            while(ans<d || (ans-d)%2!=0)
            {
                i++;
                ans+=i;
                
            }
           return i;
        }
};
