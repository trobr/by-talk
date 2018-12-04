#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int solution(void)
{
    char line[100000] = { 0 };

    int run = 1;
    while (cin.getline(line, 100000)) {
        /* code */
        vector<int> data;
        unordered_set<int> data_map;

        for (int i = 0; i < 100000 && line[i] != 0;) {
            int start = i;
            while (line[i++] != ',')
                ;
            line[i - 1] = 0;
            data.push_back(atoi(line + start));
        }

        for (int i = 0; i < data.size(); i++) {
            int num = data[i];
            data_map.insert(num);
            cout << num << "\t";
        }

        cout << endl
             << "datamap:" << endl;
        for (auto iter = data_map.begin(); iter != data_map.end(); iter++) {
            cout << *iter << "\t";
        }
        cout << endl;

        /**/
        int max = 1;
        int cnt = 1;
        for (auto iter = data_map.begin(); iter != data_map.end(); cnt = 1) {
            int ele = *iter;
            int tmp = ele;
            cout << endl
                 << "@" << __LINE__ << ":" << ele << endl;
            data_map.erase(iter++);
            auto tmp_iter = iter;

            iter = data_map.find(--ele);
            while (iter != data_map.end()) {
                /* code */
                cout << "@" << __LINE__ << ":" << ele << endl;
                ++cnt;
                data_map.erase(iter++);
                iter = data_map.find(--ele);
            }

            ele = tmp;
            cout << ele << "\t" << cnt << endl;

            iter = data_map.find(++ele);
            while (iter != data_map.end()) {
                /* code */
                cout << "@" << __LINE__ << ":" << ele << endl;
                ++cnt;
                data_map.erase(iter);
                iter = data_map.find(++ele);
            }

            if (cnt > max) {
                max = cnt;
            }
            if (cnt == 1) {
                iter = tmp_iter;
            }
        }
        cout << max << endl;
    }
}

int main()
{
    solution();
}