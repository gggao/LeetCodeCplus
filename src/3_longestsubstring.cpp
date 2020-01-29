#include "headers.h"

using namespace std;
 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, end = 0, max = s.size() > 0 ? 1 : 0;
        bitset<256> bitFlag;
        for (;end < s.size(); end++) {
            char c = s[end];
            if (bitFlag.test(c)) {
                // move start
                while (start < end && s[start] != c) {
                    bitFlag.reset(s[start]);
                    start++;
                };
                start++;
            } else {
                bitFlag.set(c);
                if (end - start + 1 > max) {
                    max = end - start + 1;
                }
            }
        }
        return max;
    }
};