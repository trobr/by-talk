#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;

        //sort(nums.begin(), nums.end());

        for (int i = 0, lens = nums.size(); i < lens; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                if (l > i + 1 && nums[l] == nums[l - 1]) {
                    ++l;
                    continue;
                }
                if (r < lens - 1 && nums[r] == nums[r + 1]) {
                    --r;
                    continue;
                }

                int sum = nums[i] + nums[l] + nums[r] - target;
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

    // k >= 3
    // sort befor
    vector<vector<int>> KSum(vector<int> &nums, int target, int k)
    {
        vector<vector<int>> ret;

        if (k == 3) {
            return threeSum(nums, target);
        }
        else {
            for (int i = 0, lens = nums.size(); i < lens - k + 1; ++i) {
                if (i != 0 && nums[i] == nums[i - 1]) {
                    continue;
                }

                vector<vector<int>> _ret;
                vector<int> _nums(nums.begin() + i + 1, nums.end());
                _ret = KSum(_nums, target - nums[i], k - 1);
                if (_ret.size() != 0) {
                    for (auto elm : _ret) {
                        elm.push_back(nums[i]);
                        ret.push_back(elm);
                    }
                }
            }

            return ret;
        }
    }

#ifdef USE_ORI_METHOD
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end());

        for (int i = 0, lens = nums.size() - 3; i < lens; ++i) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            vector<vector<int>> _ret;
            vector<int> _nums(nums.begin() + i + 1, nums.end());
            _ret = threeSum(_nums, target - nums[i]);
            if (_ret.size() != 0) {
                for (auto elm : _ret)
                {
                    elm.push_back(nums[i]);
                    ret.push_back(elm);
                }
            }
        }

        return ret;
    }
#else
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());

        return KSum(nums, target, 4);
    }
#endif
};

int main()
{
    Solution su;
    //int arr[] = {-10, -3, -8, -3, 4, -1, -2, -4, -8, -5};
    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<int> nums(begin(arr), end(arr));
    vector<vector<int>> expp = su.fourSum(nums, 0);
    system("pause");
}
