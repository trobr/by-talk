#include <algorithm>
#include <iostream>
#include <vector>

//https://www.cnblogs.com/lichen782/p/leetcode_3Sum.html
//解法二

using namespace std;


class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0, lens = nums.size(); i < lens; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while(l < r) {
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    ++l;
                    continue;
                }
                if (r < lens - 1 && nums[r] == nums[r + 1]) {
                    --r;
                    continue;
                }

                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    vector<int> _ret;
                    _ret.push_back(nums[i]);
                    _ret.push_back(nums[l]);
                    _ret.push_back(nums[r]);
                    ret.push_back(_ret);
                    --r;
                    ++l;
                }
            }
        }

        return ret;
    }
};


int main()
{
    Solution su;
    //int arr[] = {-10, -3, -8, -3, 4, -1, -2, -4, -8, -5};
    int arr[] = {-1, 0, 1, 2, -1, -4};
    vector<int> nums(begin(arr), end(arr));
    vector<vector<int>> expp = su.threeSum(nums);
    system("pause");
}
