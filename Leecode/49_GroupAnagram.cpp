// 给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
// 字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

// 示例 1:
// 输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// 输出: [["bat"],["nat","tan"],["ate","eat","tea"]]

// 示例 2:
// 输入: strs = [""]
// 输出: [[""]]

// 示例 3:
// 输入: strs = ["a"]
// 输出: [["a"]]

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::vector<std::vector<std::string>> result;
    std::unordered_map<std::string, int> groupList;
    for (auto it = strs.begin(); it != strs.end(); it++) 
    {
        std::string temp = *it;
        std::sort(temp.begin(), temp.end());
        if(groupList.find(temp) == groupList.end())
        {
            groupList[temp] = result.size();
            result.push_back({*it});
            continue;
        }
        result[groupList[temp]].push_back(*it);
    }
    return result;
}
