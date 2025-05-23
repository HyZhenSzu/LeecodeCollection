// 给定一种规律 pattern 和一个字符串 s ，判断 s 是否遵循相同的规律。
// 这里的 遵循 指完全匹配，例如， pattern 里的每个字母和字符串 s 中的每个非空单词之间存在着双向连接的对应规律。

// 示例1:
// 输入: pattern = "abba", s = "dog cat cat dog"
// 输出: true

// 示例 2:
// 输入:pattern = "abba", s = "dog cat cat fish"
// 输出: false

// 示例 3:
// 输入: pattern = "aaaa", s = "dog cat cat dog"
// 输出: false

#include <iostream>
#include <string>
#include <unordered_map>

bool wordPattern(std::string pattern, std::string s) {
    std::unordered_map<char, std::string> patternMap;
    std::unordered_map<std::string, char> sMap;

    int index = 0;
    std::string word = "";
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ' || i == s.size() - 1)
        {
            if(i == s.size() - 1)
                word += s[i];
                
            if(word.size() < 0)
                continue;
            
            if(patternMap.find(pattern[index]) != patternMap.end() && patternMap[pattern[index]] != word)
                return false;
            if(sMap.find(word) != sMap.end() && sMap[word] != pattern[index])
                return false;

            patternMap[pattern[index]] = word;
            sMap[word] = pattern[index];
            index++;
            word = "";
            continue;
        }
        word += s[i];
    }
    return index == pattern.size();
}

int main()
{
    std::string pattern = "a";
    std::string s = "a";
    std::cout << wordPattern(pattern, s) << std::endl;
    return 0;
}