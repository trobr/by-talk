#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution
{
  public:
    string intToRoman(int num)
    {
        int level[] = {1000, 100, 10, 1};
        string roman_level[7] = {"M", "D", "C", "L", "X", "V", "I"};

        int idx = 0;
        string roman = "";
        while (idx < 7) {
            /* code */
            int v = num / level[idx / 2];
            if (v == 0) {
				idx += 2;
                continue;
            }
            else if (v >= 5) {
                if (v == 9) {
                    roman += roman_level[idx] + roman_level[idx - 2];
                }
                else {
                    roman += roman_level[idx - 1];
                    for (int i = 0; i < v - 5; ++i){
                        roman += roman_level[idx];
                    }
                }
                
            }
            else if (v == 4) {
                roman += roman_level[idx] + roman_level[idx - 1];
            }
            else {
                for (int i = 0; i < v; ++i) {
                    roman += roman_level[idx];
                }
            }

            num %= level[idx / 2];
            idx += 2;
        }

		return roman;
    }
};

int main()
{
    Solution su;
    std::cout << su.intToRoman(58) << endl;
	system("pause");
}