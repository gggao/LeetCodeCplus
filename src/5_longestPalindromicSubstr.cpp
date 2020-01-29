#include "headers.h"

using namespace std;
 
 /**
  * 以每个字母为中心，向两边检查
  */
class Solution {
public:
    string longestPalindrome(string s) {
        // Palindromic center
        int index = 0;
        // substring index
        int start = 0, end = 0;
        for (; index < s.size(); index++) {
            // odd
            int shift = 1;
            while (index - shift >= 0 && index + shift < s.size() 
                   && s[index - shift] == s[index + shift]) shift++;
            shift--;
            if ( shift * 2 + 1 > end - start) {
                    start = index - shift;
                    end = index + shift + 1;
                }
                            
            // even
            shift = 1;
            if (index < s.size() - 1 && s[index] == s[index + 1] ) {
                while (index - shift >= 0 && index + shift + 1 < s.size() 
                   && s[index - shift] == s[index + shift + 1]) shift++;
                shift--;
                
                if (shift * 2 + 2 > end - start) {
                    start = index - shift;
                    end = index + shift + 2;
                }
            }
        }
        return s.substr(start, end - start);
    }
};
