// 给定一个单词数组 words 和一个长度 maxWidth ，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
// 你应该使用 “贪心算法” 来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
// 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
// 文本的最后一行应为左对齐，且单词之间不插入额外的空格。

// 注意:

// 单词是指由非空格字符组成的字符序列。
// 每个单词的长度大于 0，小于等于 maxWidth。
// 输入单词数组 words 至少包含一个单词。
 

// 示例 1:
// 输入: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// 输出:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

// 示例 2:
// 输入:words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// 输出:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
//      因为最后一行应为左对齐，而不是左右两端对齐。       
//      第二行同样为左对齐，这是因为这行只包含一个单词。

// 示例 3:
// 输入:words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"]，maxWidth = 20
// 输出:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    std::vector<std::string> textBlock;
    int usedWidth = 0;
    int beginPos = 0;
    int i = 0;
    while (i < words.size())
    {
        usedWidth += words[i].size();
        if(usedWidth + i - beginPos <= maxWidth)
        {
            i++;
            continue;
        }

        usedWidth -= words[i].size();
        int numOfSpace = maxWidth - usedWidth;
        int numOfWords = i - beginPos;
        std::string temp = words[beginPos];
        for (int j = beginPos + 1; j < i; j++)
        {
            // count number of space in every loop.
            int space = numOfSpace / (numOfWords - 1);
            if(numOfSpace % (numOfWords - 1) != 0)
                space++;
            numOfSpace -= space;
            numOfWords--;

            for (int k = 0; k < space; k++)
                temp += " ";
            temp += words[j];
        }
        while(temp.size() < maxWidth)
            temp += " ";
        textBlock.push_back(temp);
        beginPos = i;
        usedWidth = 0;
    }
    std::string temp = words[beginPos];
    beginPos++;
    while(beginPos < i)
    {
        temp += " ";
        temp += words[beginPos++];
    }
    while(temp.size() < maxWidth)
        temp += " ";
    textBlock.push_back(temp);
    return textBlock;
}

int main()
{
    std::vector<std::string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    int maxWidth = 20;
    std::vector<std::string> result = fullJustify(words, maxWidth);
    for (auto it = result.begin(); it != result.end(); it++)
        std::cout << *it << "\n" << std::flush;
    return 0;
}