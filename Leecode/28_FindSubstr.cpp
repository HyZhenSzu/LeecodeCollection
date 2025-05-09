// 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

// 示例 1：
// 输入：haystack = "sadbutsad", needle = "sad"
// 输出：0
// 解释："sad" 在下标 0 和 6 处匹配。
// 第一个匹配项的下标是 0 ，所以返回 0 。

// 示例 2：
// 输入：haystack = "leetcode", needle = "leeto"
// 输出：-1
// 解释："leeto" 没有在 "leetcode" 中出现，所以返回 -1 。

#include <iostream>
#include <string>
#include <vector>

void bulidNext(std::string needle, std::vector<int>& next)
{
    int len = needle.size();
    next.push_back(0);
    int lenOfPrefix = 0;
    int i = 1;
    while(i < len)
    {
        if(needle[i] == needle[lenOfPrefix])
        {
            lenOfPrefix++;
            next.push_back(lenOfPrefix);
            i++;
            continue;
        }
        if(lenOfPrefix == 0)
        {
            i++;
            next.push_back(0);
        }
        else
            lenOfPrefix = next[lenOfPrefix - 1];
    }
}

int strStr(std::string haystack, std::string needle) {
    std::vector<int> next;
    bulidNext(needle, next);

    int i_hay = 0;
    int j_ned = 0;
    while(i_hay < haystack.size())
    {
        std::cout << "Compare " << haystack[i_hay] << " and " << needle[j_ned] << std::endl;
        if(haystack[i_hay] == needle[j_ned])
        {
            i_hay++;
            j_ned++;
        }
        else if(j_ned > 0)
            j_ned = next[j_ned - 1];
        else
            i_hay++;
        
        if(j_ned == needle.size())
            return i_hay - j_ned;
    }
    return -1;
}

int main()
{
    std::string haystack = "leedcode";
    std::string needle = "leedt";
    std::cout << strStr(haystack, needle) << std::endl;
    return 0;
}