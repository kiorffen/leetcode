#================================================================
#   Copyright Tang Haiyu. All rights reserved.
#   
#   @file   main.sh
#   @author tanghaiyu777@163.com
#   @date   2020/02/09
#   @brief 
#
#================================================================


#!/bin/bash

linenum=$(cat file.txt | wc -l)

allnum=$(cat file.txt|xargs|awk -F " " '{print NF}')

((rownum=$allnum/$linenum))

cat file.txt | xargs | awk -v ln=$linenum -v rn=$rownum -F " " '{
for(i=1;i<=rn;i++) {
    for (j=1;j<=ln;j++) {
        printf "%s",$(i+(j-1)*rn)
        if (j<ln) {printf " "}
    }
    printf "\n"
}
}'
    #for (j=1;j<=ln;j++) {
    #    print $(i+(ln-1)*rn)
    #}
