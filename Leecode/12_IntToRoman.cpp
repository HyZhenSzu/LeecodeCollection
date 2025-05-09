// 七个不同的符号代表罗马数字，其值如下：

// 符号	值
// I	1
// V	5
// X	10
// L	50
// C	100
// D	500
// M	1000

// 罗马数字是通过添加从最高到最低的小数位值的转换而形成的。将小数位值转换为罗马数字有以下规则：
// 如果该值不是以 4 或 9 开头，请选择可以从输入中减去的最大值的符号，将该符号附加到结果，减去其值，然后将其余部分转换为罗马数字。
// 如果该值以 4 或 9 开头，使用 减法形式，表示从以下符号中减去一个符号，例如 4 是 5 (V) 减 1 (I): IV ，9 是 10 (X) 减 1 (I)：IX。仅使用以下减法形式：4 (IV)，9 (IX)，40 (XL)，90 (XC)，400 (CD) 和 900 (CM)。
// 只有 10 的次方（I, X, C, M）最多可以连续附加 3 次以代表 10 的倍数。你不能多次附加 5 (V)，50 (L) 或 500 (D)。如果需要将符号附加4次，请使用 减法形式。
// 给定一个整数，将其转换为罗马数字。


// 示例 1：
// 输入：num = 3749
// 输出： "MMMDCCXLIX"
// 解释：
// 3000 = MMM 由于 1000 (M) + 1000 (M) + 1000 (M)
//  700 = DCC 由于 500 (D) + 100 (C) + 100 (C)
//   40 = XL 由于 50 (L) 减 10 (X)
//    9 = IX 由于 10 (X) 减 1 (I)
// 注意：49 不是 50 (L) 减 1 (I) 因为转换是基于小数位

// 示例 2：
// 输入：num = 58
// 输出："LVIII"
// 解释：
// 50 = L
//  8 = VIII

// 示例 3：
// 输入：num = 1994
// 输出："MCMXCIV"
// 解释：
// 1000 = M
//  900 = CM
//   90 = XC
//    4 = IV

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::string intToRoman(int num) {
    const std::string ROMANS = "MDCLXVI";
    const int* INTS = new int[7]{1000, 500, 100, 50, 10, 5, 1};

    int pos = 0;
    std::string result;
    int times = 0;
    while(num > 0 && times < 20)
    {
        times++;
        // get a pos where the number less than the value of num.
        while(num < INTS[pos])
            pos++;
        std::cout << "Got pos : " << pos << " int : " << INTS[pos] << "\n";

        // 如果先用比最大数位更大的数减去这个数字，看范围即可知道是不是9or4开头的数字
        // x -- [400, 499] --> 500 - x -- [1, 100]
        // x -- [900, 999] --> 1000 - x -- [1, 100]
        // x -- [40, 49] --> 50 - x -- [1, 10]
        // x -- [90, 99] --> 100 - x -- [1, 10]
        // x -- [4] --> 5 - x -- [1]
        // x -- [9] --> 10 - x -- [1]
        int posB = 2 * ((pos - 1) / 2 + 1);
        std::cout << "Got posB : " << posB << "\n";
        if(pos - 1 >= 0 && INTS[pos - 1] - num <= INTS[posB])
        {
            result += ROMANS[posB];
            result += ROMANS[pos - 1];
            num -= INTS[pos - 1] - INTS[posB];
            continue;
        }
        result += ROMANS[pos];
        num -= INTS[pos];
    }
    return result;
}

int main()
{
    int num = 3749;
    std::cout << intToRoman(num);
    return 0;
}