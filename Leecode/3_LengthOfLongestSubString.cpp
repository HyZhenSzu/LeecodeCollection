// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长 子串 的长度。

// 示例 1:
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

// 示例 2:
// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

// 示例 3:
// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

#include <iostream>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    std::string subString = s.substr(0, 1);
    int maxLength = 0;
    for (int i = 1; i < s.size(); i++)
    {
        int pos = subString.find(s[i]);
        // if(pos == -1)
        //     std::cout << s[i] << " is Not Found\n";
        // else
        //     std::cout << s[i] << " is in pos " << pos << "\n";
        if(pos != -1)
        {
            maxLength = subString.size() > maxLength ? subString.size() : maxLength;
            // std::cout << "Update maxLength : " << maxLength << "\n";
            subString = subString.substr(pos + 1, subString.size() - pos - 1);
        }
        subString += s[i];
        // std::cout << "Add character : " << s[i] << " Substring : " << subString << "\n" << std::flush;

    }
    maxLength = subString.size() > maxLength ? subString.size() : maxLength;
    // std::cout << "Update maxLength : " << maxLength << "\n" << std::flush;
    return maxLength;
}

// int main()
// {
//     std::string s = "anviaj";
//     lengthOfLongestSubstring(s); 
//     return 0;
// }