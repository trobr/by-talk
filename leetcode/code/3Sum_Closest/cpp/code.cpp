#include <iostream>
#include <algorithm>
#include <vector>
#include <stdint.h>

using namespace std;

class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int min_val = INT32_MAX;

        sort(nums.begin(), nums.end());

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

                if (abs(sum) < abs(min_val)) {
                    min_val = sum;
                }

                if (sum > 0) {
                    --r;
                }
                else if (sum < 0) {
                    ++l;
                }
                else {
                    return target;
                }
            }
        }

        return min_val + target;
    }
};

int main()
{
    Solution su;
    int arr[] = {-1, 2, 1, -4};
    //int arr[] = {-1, 0, 1, 0};
    vector<int> nums(begin(arr), end(arr));
    int expp = su.threeSumClosest(nums, 1);
    system("pause");
}
