/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/11/30
* @brief  
*
**/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Solution {
    public:
        string addBinary(string a, string b) {
            int al = a.size();
            int bl = b.size();

            if (al < bl) {
                for (int i = 0; i < bl-al; ++i) {
                    a.insert(a.begin(), '0');
                }
            } else {
                for (int i = 0; i < al-bl; ++i) {
                    b.insert(b.begin(), '0');
                }
            }
            return addBinarySub(a,b);
        }

        string addBinarySub(string a, string b) {
            string::reverse_iterator it_a = a.rbegin();
            string::reverse_iterator it_b = b.rbegin();
            string c;

            int carry = 0;
            for (; it_a != a.rend(); ++it_a, ++it_b) {
                if ((*it_a=='0' && *it_b=='0' && carry==1) || (*it_a=='1'&& *it_b=='0' && carry==0) || (*it_a=='0' && *it_b=='1' && carry==0)) {
                    cout<<"case1\n";
                    c.insert(c.begin(), '1');
                    carry = 0;
                } else if ((*it_a=='0' && *it_b=='1' && carry==1) || (*it_a=='1'&& *it_b=='0' && carry==1) || (*it_a=='1' && *it_b=='1' && carry==0)) {
                    cout<<"case2\n";
                    c.insert(c.begin(), '0');
                    carry = 1;
                } else if (*it_a=='0' && *it_b=='0' && carry==0) {
                    cout<<"case3\n";
                    c.insert(c.begin(), '0');
                    carry = 0;
                } else {
                    cout<<"case4\n";
                    c.insert(c.begin(), '1');
                    carry = 1;
                }
            }
            cout << c <<endl;
            if (carry==1) {
                c.insert(c.begin(), '1');
            }

            return c;
        }
};

int main() {
    string a="111";
    string b="111";

    Solution s;
    string c = s.addBinary(a, b);

    cout << c << endl;
}
