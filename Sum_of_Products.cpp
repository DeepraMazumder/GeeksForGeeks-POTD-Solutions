/*
Given an array arr[] of size n. Calculate the sum of Bitwise ANDs ie: calculate sum of arr[i] & arr[j] for all the pairs in the given array arr[] where i < j.

Example 1:

Input:
n = 3
arr = {5, 10, 15}

Output: 15

Explanation: The bitwise Ands of all pairs where i<j are (5&10) = 0, (5&15) = 5 and (10&15) = 10. Therefore, the total sum = (0+5+10) = 15.

Example 2:

Input:
n = 4
arr = {10, 20, 30, 40}

Output: 46

Explanation: The sum of bitwise Ands of all pairs = (0+10+8+20+0+8) = 46.

Your Task:
You don't need to read input or print anything.Your Task is to complete the function pairAndSum() which takes an Integer n and an array arr[]  of size n as input parameters and returns the sum of bitwise Ands of
all pairs.

Expected Time Complexity:O(n)
Expected Auxillary Space:O(1)

Constraints:
1 <= n <= 10^5
1 <= arr[i] <= 10^8
*/

class Solution 
{
    public:
        long long pairAndSum(int n, long long a[]) 
        {
                long long ans=0;
                unordered_map<int,long long> ht;
                for(int i=0;i<n;i++)
                {
                    int c=0;
                    while(a[i]>0)
                    {
                        int k=a[i]&1;
                        if(k==1)
                            ht[c]++;
                        c++;
                        a[i]=a[i]/2;
                    }
                }
                for(auto &x:ht)
                {
                    //cout<<x.first<<" "<<x.second<<endl;
                    long long k=(x.second)*(x.second-(long long)1)/(long long)2;
                    //cout<<k<<endl;
                    ans=ans+(pow(2,x.first)*k);
                    //cout<<ans<<endl;
                }
                return ans;
        }
};
