#include "headers.h"

using namespace std;
 
// first version
// class Solution {
// public:
//     string convert(string s, int numRows) {
//         char* charp = new char[s.size() + 1];
//         vector<vector<char>> rows(numRows);
//         // init
//         string::iterator it = s.begin();
//         int index = 0;
//         int inc = 1;
//         while (it != s.end()) {
//             rows[index].push_back(*it);
//             it++;
//             if (numRows == 1) {
//                 continue;
//             }
//             index += inc;
//             if (index == -1) {
//                 index = 1;
//                 inc = 1;
//             }
//             if (index == numRows) {
//                 index = numRows -2;
//                 inc = -1;
//             }            
//         }

//         typedef typename vector<vector<char>>::iterator vvitType;
//         typedef typename vector<char>::iterator vitType;
//         vvitType vit = rows.begin();
//         index = 0;
//         while (vit != rows.end()) {
//             vitType subvit = vit->begin();
//             while (subvit != vit->end()) {
//                 charp[index++] = *subvit;
//                 subvit++;
//             }
//             vit++;
//         }
//         charp[s.size()] = 0;
//         string res(charp);
//         delete[] charp;
//         return res;
//     }
// };

/**
 * 每个周期的元素数量：cycle = (2*n -2), n 为行数
 * index 从 0 开始，周期 c 从 0 开始
 * 所以第 x 行，第 c 周期索引，中间的行数每个周期有两个索引： 
 * x + cycle * c , cycle - x + cycle * c
 * 
 */
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        int cycle = 2 * numRows - 2;
        for (int row = 0; row < numRows; row++) {
            int firstInd = row;
            int secondInd = (cycle - row) % cycle;
            while (firstInd < s.size()) {
                res += s[firstInd];
                if (firstInd != secondInd && secondInd < s.size()) {
                    res += s[secondInd];
                }
                firstInd += cycle;
                secondInd += cycle;
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    cout << solution.convert("PAYPALISHIRING", 4) << endl;
    cout << solution.convert("AB", 1) << endl;
}