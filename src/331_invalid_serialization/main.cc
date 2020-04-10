/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/01
* @brief  
*
**/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if (preorder.size()==0) {
            return true;
        }
        int slot=1;
        char pre;
        for (auto ch:preorder) {
            if (ch==',') {
                slot-=1;
                if (slot<0) {
                    return false;
                }
                if (pre!='#') {
                    slot+=2;
                }

            } else {
                pre=ch;
            }
        }
        if (pre=='#') {
            slot-=1;
        } else {
            slot+=1;
        }

        return slot==0;
    }
};

int main() {
    Solution s;
    cout << s.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << endl;
    cout << s.isValidSerialization("1,#") << endl;
    cout << s.isValidSerialization("9,#,#,1") << endl;

    return 0;
}
