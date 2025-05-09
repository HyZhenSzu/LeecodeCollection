// 编写一个函数来查找字符串数组中的最长公共前缀。
// 如果不存在公共前缀，返回空字符串 ""。

// 示例 1：
// 输入：strs = ["flower","flow","flight"]
// 输出："fl"

// 示例 2：
// 输入：strs = ["dog","racecar","car"]
// 输出：""
// 解释：输入不存在公共前缀。

#include <iostream>
#include <vector>
#include <string>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string prefix = strs[0];
    for (auto it = strs.begin(); it != strs.end(); it++)
    {
        std::string checkWord = *it;
        while(prefix.size() > 0)
        {
            while(checkWord.size() > prefix.size())
                checkWord.pop_back();
            if(checkWord.find(prefix) != -1)
                break;
            prefix.pop_back();
        }
        if(prefix.size() == 0)
            return "";
    }
    return prefix;
}