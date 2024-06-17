/*
Given the coordinates of the endpoints(p1,q1, and p2,q2) of the two line segments. Check if they intersect or not. If the Line intersects return true otherwise return false.

Examples

Input: p1=(1,1), q1=(10,1), p2=(1,2), q2=(10,2)

Output: false

Explanation:The two line segments formed by p1-q1 and p2-q2 do not intersect.

Input: p1=(10,0), q1=(0,10), p2=(0,0), q2=(10,10)

Output: true

Explanation: The two line segments formed by p1-q1 and p2-q2 intersect.

Expected Time Complexity: O(1)
Expected Auxillary Space: O(1)

Constraints:
-10^6 <= X,Y(for all points) <= 10^6
*/

class Solution 
{
    public:
        string doIntersect(int p1[], int q1[], int p2[], int q2[]) 
        {
            double m1 = (double)(q1[1] - p1[1]) / (double)(q1[0] - p1[0]);
            double m2 = (double)(q2[1] - p2[1]) / (double)(q2[0] - p2[0]);
            if(m1 == m2)
            {
                return "false";
            }
            bool chk211 = p2[1]-p1[1] - m1*(p2[0]-p1[0]) >0?true:false;
            bool chk212 = q2[1]-p1[1] - m1*(q2[0]-p1[0]) >0?true:false;
            bool chk121 = p1[1]-p2[1] - m2*(p1[0]-p2[0]) >0?true:false;
            bool chk122 = q1[1]-p2[1] - m2*(q1[0]-p2[0]) >0?true:false;
            if((chk211==true && chk212 == true) || (chk211==false && chk212 == false) || 
            (chk121 == true && chk122 == true) || (chk121 == false && chk122 == false))
            {
                return "false";
            }
            return "true";
        }
};
