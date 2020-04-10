/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/06
* @brief  
*
**/

#include <iostream>
#include <string>

using namespace std;

int solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    
    if (S.size()<3) {
        return 0;
    }
    
    int count = 0;
    for (int i=0;i<S.size()-2;i+=3) {
        cout << "i: " << i << endl;
        if (S[i]==S[i+1] && S[i]==S[i+2]) {
        cout << "step " << i << endl;
            if (S[i]=='a') {
        cout << "step1 " << i << endl;
                if (i>=3) {
                    if (S[i-1] =='b'&&S[i-2]=='b') {
                        S[i+1]='b';
        cout << "step11 " << i << endl;
                        count++;
                    } else {
                        S[i]='b';
        cout << "step12 " << i << endl;
                        count++;
                    }
                }
            } else {
                if (i>=3) {
        cout << "step2 " << i << endl;
                    if (S[i-1]=='a'&&S[i-2]=='a') {
                        S[i+1]='a';
        cout << "step21 " << i << endl;
                        count++;
                    } else {
                        S[i]='a';
        cout << "step22 " << i << endl;
                        count++;
                    }
                }
            }
        } else {
                if (i>=3) {
                    if (S[i]==S[i-1]&&S[i-1]==S[i-2]) {
                        if (S[i]=='a') {
                            S[i-2]='b';
        cout << "step41 " << i << endl;
                            count++;
                        } else {
                            S[i-2]='a';
        cout << "step51 " << i << endl;
                            count++;
                        }
                    }
                    if (S[i]==S[i+1]&&S[i-1]==S[i]) {
                        if (S[i]=='a') {
                            S[i+1]='b';
        cout << "step61 " << i << endl;
                            count++;
                        } else {
                            S[i+1]='a';
        cout << "step71 " << i << endl;
                            count++;
                        }
                    }
                }
        }
    }

    return count;
}

int main() {
    string s="baabab";

    int ret = solution(s);

    cout << ret << endl;

    return 0;
}

