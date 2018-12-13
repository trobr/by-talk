#include <iostream>
#include <vector>
#include <algorithm>

//https://www.cnblogs.com/lichen782/p/leetcode_3Sum.html

using namespace std;

#if 1
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;

        if (nums.size() < 3) {
            return ret;
        }

        sort(nums.begin(), nums.end());

        int critical_count = -1;
        for (int idx = 0, lens = nums.size() - 1; idx < lens; ++idx) {
            if (nums[idx] <= 0 && nums[idx + 1] >= 0) {
                critical_count = idx + 1;
                break;
            }
        }

        int last_left = nums[0];
        int last_right = *(nums.end() - 1);
        for (int left = 0; left <= critical_count; ++left) {
            int left_val = nums[left];
            
            //避免重复
            if (left_val == last_left && left != 0) {
                continue;
            }
            else {
                last_left = left_val;
            }
            for (int right = nums.size() - 1; right >= critical_count; --right) {
                int right_val = nums[right];
                if (right - left == 1) {
                    continue;
                }

                //避免重复
                if (right_val == last_right && right != nums.size() - 1) {
                    continue;
                }
                else {
                    last_right = right_val;
                }

                //track
                if (left_val == -3 && right_val == 4) {
                    int track;
                }

                int need = -(left_val + right_val);
                int sidx = -1;
                if (need >= 0) {
                    if (right > critical_count) {
                        if (binary_search(nums.begin() + critical_count, nums.begin() + right, need)){
                            sidx = lower_bound(nums.begin() + critical_count, nums.begin() + right, need) - nums.begin();
                        }
                    }
                }
                else {
                    if (critical_count > left) {
                        if (binary_search(nums.begin() + left + 1, nums.begin() + critical_count, need)){
                            sidx = lower_bound(nums.begin() + left + 1, nums.begin() + critical_count, need) - nums.begin();
                        }
                    }
                }

                if (sidx != -1) {
                    vector<int> _ret;
                    _ret.push_back(left_val);
                    _ret.push_back(right_val);
                    _ret.push_back(nums[sidx]);
                    ret.push_back(_ret);
                }
            }
        }
        
        return ret;
    }
};
# else
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
    }
};
#endif

int main()
{
    Solution su;
    int arr[] = {-10, -3, -8, -3, 4, -1, -2, -4, -8, -5};
    //int arr[] = {-1, 0, 1, 0};
    vector<int> nums(begin(arr), end(arr));
    vector<vector<int>> exp = su.threeSum(nums);
    system("pause");
}

