// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。

// 示例 1:
// 输入: s = "anagram", t = "nagaram"
// 输出: true

// 示例 2:
// 输入: s = "rat", t = "car"
// 输出: false

#include <iostream>
#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
    if(s.size() != t.size()) return false;
    std::unordered_map<char, int> sMap, tMap;
    for(char c : s)
        sMap[c]++;
    for(char c : t)
        tMap[c]++;

    for (auto it = sMap.begin(); it != sMap.end(); it++)
    {
        if(it->second != tMap[it->first])
            return false;
    }
    return true;
}