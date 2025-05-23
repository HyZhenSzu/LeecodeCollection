// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。
// magazine 中的每个字符只能在 ransomNote 中使用一次。

// 示例 1：
// 输入：ransomNote = "a", magazine = "b"
// 输出：false

// 示例 2：
// 输入：ransomNote = "aa", magazine = "ab"
// 输出：false

// 示例 3：
// 输入：ransomNote = "aa", magazine = "aab"
// 输出：true

#include <iostream>
#include <string>
#include <unordered_map>

bool canConstruct(std::string ransomNote, std::string magazine) {
    std::unordered_map<char, int> magazineMap;
    for (auto it = magazine.begin(); it != magazine.end(); it++)
    {
        magazineMap[*it]++;
    }
    for (auto it = ransomNote.begin(); it != ransomNote.end(); it++)
    {
        if(magazineMap.find(*it) == magazineMap.end())
            return false;
        if(--magazineMap[*it] < 0)
            return false;
    }
    return true;
}