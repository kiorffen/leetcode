/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/27
* @brief  
*
**/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string res;
        string s(str);
        
        for (auto c:s) {
            if (c==' ') {
                res+="%20";
            } else {
                res+=c;
            }
        }
        strcpy(str, res.c_str());
	}
};
