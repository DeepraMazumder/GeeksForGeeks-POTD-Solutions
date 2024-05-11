/*
Juggler Sequence is a series of integers in which the first term starts with a positive integer number a and the remaining terms are generated from the immediate previous term using the below recurrence relation:

Juggler Formula: https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/705067/Web/Other/2220ffd2-353d-4b30-b2aa-68fe4047f959_1685087657.png

Given a number n, find the Juggler Sequence for this number as the first term of the sequence until it becomes 1.

Example 1:

Input: n = 9

Output: 9 27 140 11 36 6 2 1

Explaination: We start with 9 and use above formula to get next terms.
 
Example 2:

Input: n = 6

Output: 6 2 1

Explaination: [61/2] = 2. [21/2] = 1. 

Your Task:
You do not need to read input or print anything. Your Task is to complete the function jugglerSequence() which takes n as the input parameter and returns a list of integers denoting the generated sequence.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)

Constraints:
1 ≤ n ≤ 100
*/

class Solution 
{
    public:
        vector<long long> jugglerSequence(long long n) 
        {
            vector<long long> ans;
            ans.push_back(n);
            while (n != 1) 
            {
                if (n % 2 == 0) n = sqrt(n);
                else n = sqrt(n) * sqrt(n) * sqrt(n);
                ans.push_back(n);
            }
            return ans;
        }
};
