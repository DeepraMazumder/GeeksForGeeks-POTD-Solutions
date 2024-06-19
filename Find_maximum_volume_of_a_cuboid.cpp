/*
You are given a perimeter & the area. Your task is to return the maximum volume that can be made in the form of a cuboid from the given perimeter and surface area.
Note: Round off to 2 decimal places and for the given parameters, it is guaranteed that an answer always exists.

Examples

Input: perimeter = 22, area = 15

Output: 3.02

Explanation: The maximum attainable volume of the cuboid is 3.02

Input: perimeter = 20, area = 5

Output: 0.33

Explanation: The maximum attainable volume of the cuboid is 0.33

Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints :
1 ≤ perimeter ≤ 10^9
1 ≤ area ≤ 10^9
*/

class Solution 
{
    public:
        double maxVolume(double perimeter, double area) 
        {
            double P = perimeter;
            double A = area;
            double sqrtTerm = sqrt(P * P - 24 * A);
            double dimension1 = (P - sqrtTerm) / 12.0;
            double dimension2 = (P / 4.0) - 2 * dimension1;
            double volume = pow(dimension1, 2) * dimension2;
            return round(volume * 100.0) / 100.0;
        }
};
