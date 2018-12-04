#include <bits/stdc++.h>

using namespace std;

// class Solution {
//   public:
//     int lengthOfLongestSubstring(string s)
//     {
//         unordered_set<int> exsit;
//         int max_sub_str = 0;
//         int start = 0;
//         int end = 0;
//         bool is_restart = true;
//
//         for (int i = 0, len = s.length(); i < len; i++) {
//             char ele = s[i];
//             if (exsit.find((int)ele) == exsit.end()) {
//                 if (is_restart) {
//                     // start = end;
//                     start = i;
//                     end = start;
//                     is_restart = false;
//                 }
//                 ++end;
//                 exsit.insert((int)ele);
//                 cout << ele << endl;
//             } else {
//                 cout << "****************************" << endl;
//                 if (end - start > max_sub_str) {
//                     max_sub_str = end - start;
//                 }
//
//                 i = start;
//                 exsit.clear();
//                 is_restart = true;
//             }
//         }
//
//         if (end - start > max_sub_str) {
//             max_sub_str = end - start;
//         }
//
//         return max_sub_str;
//
// };

class Solution {
  public:
    void printlist(unordered_map<int, int> &exist)
    {
        cout << "now exist ::::  ";
        for (auto iter = exist.begin(); iter != exist.end(); iter++) {
            cout << (char)(iter->first);
        }
        cout << endl;
    }
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int, int> exist;
        int max_sub_str = 0;
        int start = 0;
        int end = 0;
        bool is_restart = true;

        for (int i = 0, len = s.length(); i < len; i++) {
            char ele = s[i];
            auto iter = exist.find((int)ele);
            if (iter == exist.end()) {
                if (is_restart) {
                    is_restart = false;
                }
                ++end;
                exist.insert(pair<int, int>(int(ele), i));
                // cout << ele;
            } else {
                // cout << "\n************" << ele
                //      << " is exist****************\n";
                // printlist(exist);
                // cout << "\tstart: " << start << "\t end: " << end << endl;
                if (end - start > max_sub_str) {
                    max_sub_str = end - start;
                }

                --i;

                int tmp = iter->second + 1;
                for (int k = iter->second; k >= start; --k) {
                    char target = s[k];
                    // cout << "now delete idx:" << k << "  char: " << target
                    //     << endl;
                    auto finder = exist.find((int)target);
                    if (finder != exist.end()) {
                        exist.erase(finder);
                    }
                    // cout << "----------k:" << k << "\tlast:" << last << endl;
                }

                start = tmp;

                // printlist(exist);
                // cout << "\tstart: " << start << "\t end: " << end << endl;
                // cout << "****************************\n\n";
            }
        }

        // cout << "\nstart:" << start << "\t end: " << end << endl;
        if (end - start > max_sub_str) {
            max_sub_str = end - start;
        }

        return max_sub_str;
    }
};

int main()
{
    string str =
        "mldydtwyhdsqaylwpekgzbnvyqnrajrouupxqlxxospqqapgfzmgcbccrptsym";
    Solution su;
    int len = su.lengthOfLongestSubstring(str);
    cout << endl;
    cout << len << endl;
}