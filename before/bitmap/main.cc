/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2019/12/14
* @brief  
*
**/

#include <iostream>
#include <memory.h>
#include <stdlib.h>

class BitMap {
    public:
    BitMap(int n) {
        length = (n/32) + 1;
        bitmap = (int *)malloc(sizeof(int) * length);
        memset(bitmap, 0, length);
    }

    ~BitMap() {
        free(bitmap);
    }

    private:
    int *bitmap;
    int length;

    public:
    void set(int x) {
        bitmap[x/32] |= 1 << (31-x%32);
        std::cout<<bitmap[0]<<std::endl;
    }

    int get(int x) {
        return bitmap[x/32] &= 1 << (31-x%32);
    }

    void show() {
        std::cout<<length<<std::endl;
        for (int i =0; i<length;i++) {
            std::cout<<bitmap[i]<<std::endl;
        }
    }
};

int main() {

    BitMap b(40);
    b.set(30);
    std::cout << b.get(30) << std::endl;
    std::cout << b.get(7) << std::endl;
    b.show();

}

