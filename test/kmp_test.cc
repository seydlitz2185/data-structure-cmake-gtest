#include <gtest/gtest.h>
#include "../string/KMP.h"
#include <string.h>
// Demonstrate some basic assertions.
TEST(kmp_test, simple_kmp) {
    //这个例子来自于大二数据结构课上的例子
    //南京农业大学信息管理与信息系统专业 2020年9月
    //上课讲师为刘浏
    char s[12] ={'a','b','a','b','a','a','b','a','a','b','a','c'};
    int n = 12;
    char p[7] = {'a','b','a','a','b','a','c'};
    int m = 7;
    KMP k;
    k.Init(s,p,n,m);
    k.get_next();
    int match = k.match();
    EXPECT_EQ(match,6);
}