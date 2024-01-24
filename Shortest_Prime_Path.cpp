/*
You are given two four digit prime numbers Num1 and Num2. Find the distance of the shortest path from Num1 to Num2 that can be attained by altering only single digit at a time such that every number that we get
after changing a digit is a four digit prime number with no leading zeros.

Example 1:

Input:
Num1 = 1033 
Num2 = 8179

Output: 6

Explanation: 1033 -> 1733 -> 3733 -> 3739 -> 3779 -> 8779 -> 8179. There are only 6 steps reuired to reach Num2 from Num1. and all the intermediate numbers are 4 digit prime numbers.

Example 2:

Input:
Num1 = 1033 
Num2 = 1033

Output: 0

Your Task:  
You don't need to read input or print anything. Your task is to complete the function solve() which takes two integers Num1 and Num2 as input parameters and returns the distance of the shortest path from Num1 to
Num2. If it is unreachable then return -1.

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1000<=Num1,Num2<=9999
Num1 and Num2 are prime numbers.
*/

class Solution
{   
public:
    int solve(int num1,int num2)
    {   
      int flag=0;
       vector<bool>prime(10000,true);
       vector<bool>visited(10000,false);
      for(int i=1000;i<=9999;i++)
      {
          for(int j=2;j*j<=i;j++)
          {
              if(i%j==0)
              {
                  prime[i]=false;
                  break;
              }
          }
       
      }
      queue<pair<int,int>>q;
      q.push({num1,0});
      visited[num1]=true;
      while(!q.empty())
      {
          auto top=q.front();
          q.pop();
          if(top.first==num2)
          {
              return top.second;
          }
          string s1=to_string(top.first);
          for(int i=0;i<4;i++)
          {
              for(char ch='0';ch<='9';ch++)
              {
                      char present=s1[i];
                  s1[i]=ch;
                  int temp=stoi(s1);
                  if(!visited[temp] && temp>=1000 && prime[temp]==true)
                  {
                      q.push({temp,top.second+1});
                      visited[temp]=true;
                  } 
                  s1[i]=present;
              }             
          }
      }
      return -1;
    }
};
