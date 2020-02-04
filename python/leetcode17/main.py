#!/usr/bin/env python
# -*- coding:gbk -*-

#================================================================
#   Copyright (c) Tang Haiyu. All rights reserved.
#   
#   @file   main.py
#   @author tanghaiyu777@163.com
#   @date   2018/03/15
#   @brief 
#
#================================================================

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        code = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        res = []
        curr = ""
        index = 0
        self.lettercomb(digits, code, index, curr, res)
        return res

    def lettercomb(self, digits, code, index, curr, res):
        print index
        if index == len(digits):
            if len(curr) > 0:
                res.append(curr)
            return;
        for i in range(0, len(code[int(digits[index])])):
            print "num:%s" % digits[index]
            print "char:%s" % code[int(digits[index])][i]
            past = curr
            curr += code[int(digits[index])][i]
            index += 1
            self.lettercomb(digits, code, index, curr, res)
            index -= 1
            curr = past


if __name__ == "__main__":
    s = Solution();
    print s.letterCombinations("12");



