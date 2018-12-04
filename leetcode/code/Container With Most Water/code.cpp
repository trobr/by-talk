#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int> &height) 
    {
        //
        int max_area = 0;
        for (int s = 0, len = height.size() - 1, e = height.size() - 1; s < e;) {
            int min_val = 0;
            if (height[s] > height[e]) {
                min_val = height[e];
                e -= 1;
            }
            else {
                min_val = height[s];
                s += 1;
            }

            max_area = max((e - s + 1) * min_val, max_area);
            cout << "s:" << s 
                 << "\te:" << e
                 << "\tmax:" << max_area << endl;
        }

        return max_area;
    }
};

int main()
{
    int data[] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    vector<int> height(data, data + sizeof(data) / sizeof(data[0]));

    Solution su;
    cout << su.maxArea(height) << endl;
}