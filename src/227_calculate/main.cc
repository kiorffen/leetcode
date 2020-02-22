/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/22
* @brief  
*
**/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calculate1(string s) {
        int ret = 0;
        if (s.size()==0) {
            return 0;
        }

        int num = 0;
        stack<int> stk;
        char c;
        char sign = '+';
        int pre;
        for (int i=0;i<s.size();i++) {
            c = s[i];
            if (isdigit(c)) {
                num = num*10 + (c-'0');
            }

            if ((!isdigit(c)&&c!=' ') || i==s.size()-1) {
                cout << "num: " << num << endl;
                switch(sign) {
                case '+':
                    stk.push(num);
                    break;
                case '-':
                    stk.push(-num);
                    break;
                case '*':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre*num);
                    break;
                case '/':
                    pre = stk.top();
                    stk.pop();
                    stk.push(pre/num);
                    break;
                }
                sign = c;
                num = 0;
            }
        }

        cout << "size: " << stk.size() << endl;;
        while (!stk.empty()) {
            ret+=stk.top();
            cout << "tmp: " << stk.top() <<  endl;;
            stk.pop();
        }

        return ret;
    }
    bool isdigit(char c) {
        if (c>='0' && c<='9') {
            return true;
        } 

        return false;
    }
    int calculate(string s) {
        int ret = 0;
        if (s.size()==0) {
            return 0;
        }

        stack<long> nums;
        int num = -1;
        for (auto c:s) {
            if (c==' ') {
                if (num>=0) {
                    nums.push(num);
                    num = -1;
                }
                continue;
            } else if (c=='*' || c=='/' || c=='+' || c=='-') {
                if (num>=0) {
                    nums.push(num);
                    num = -1;
                }
                add_op(nums,c);
            } else {
                if (num>=0) {
                    num = num*10 + (c-'0');
                } else {
                    num = c-'0';
                }
            }
        }
        if (num>=0) {
            nums.push(num);
            num=-1;
        }

        if (nums.size()==0) {
            return ret;
        }
        if (nums.size()==1) {
            return nums.top();
        }

        stack<long> nums1;
        while (!nums.empty()) {
            nums1.push( nums.top());
            nums.pop();
        }

        stack<long> s1;
        long num1, num2, op;
        while (nums1.size() >=3) {
            num1 = nums1.top();
            nums1.pop();
            op = nums1.top();
            nums1.pop();
            num2 = nums1.top();
            nums1.pop();
            cout << "n1:" << num1 << " op: " << op << " nums2: " << num2 << endl;
            if (op==-1 || op==-2) {
                s1.push(num1);
                s1.push(op);
                nums1.push(num2);
            }
            if (op==-3) {
                nums1.push(num1*num2);
            }
            if (op==-4) {
                nums1.push(num1/num2);
            }
        }
        s1.push(nums1.top());

        //while (!s1.empty()) {
        //    cout << s1.top() << " ";
        //    s1.pop();
        //}
        //cout <<"s1"<< endl;
        //while (!nums1.empty()) {
        //    cout << nums1.top() << " ";
        //    nums1.pop();
        //}
        //cout <<"nums1"<< endl;

        stack<long> s2;
        while (!s1.empty()) {
            s2.push( s1.top());
            s1.pop();
        }
        while (s2.size()>=3) {
            num1 = s2.top();
            s2.pop();
            op = s2.top();
            s2.pop();
            num2 = s2.top();
            s2.pop();
            cout << "n1:" << num1 << " op: " << op << " nums2: " << num2 << endl;
            if (op==-1) {
                s2.push(num1+num2);
            }
            if (op==-2) {
                s2.push(num1-num2);
            }
        }

        ret = s2.top();

        return ret;
    }

    void add_op(stack<long>& nums, char c) {
        if (c=='+') {
            nums.push(-1);
        } else if (c=='-') {
            nums.push(-2);
        } else if (c=='*') {
            nums.push(-3);
        } else {
            nums.push(-4);
        }
    }
};

int main() {
    Solution s;

    int ret = s.calculate1("14/3*2");

    cout << ret << endl;

    return 0;
}
