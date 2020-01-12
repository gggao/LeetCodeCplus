#include "headers.h"

using namespace std;

struct Item {
    int index;
    int value;
};

int comp(Item a, Item b) {
    return a.value < b.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Item> tmp;
        for (int i = 0; i < nums.size(); i++) {
            Item item = {i, nums[i]};
            tmp.push_back(item);
        }
        sort(tmp.begin(), tmp.end(), comp);
        vector<int> res;

        for (int i = 0; i < tmp.size(); i++) {
            for (int j = i + 1; j < tmp.size() && tmp[i].value + tmp[j].value <= target; j++) { 
                if (tmp[i].value + tmp[j].value == target) {
                    res.push_back(tmp[i].index);
                    res.push_back(tmp[j].index);
                    return res;
                }
            }
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    Solution solution = Solution();
    // vector<int> data = vector<int>{2, 7, 11, 1}; // 9
    // vector<int> data = vector<int>{0, 4, 3, 0};
    vector<int> data = vector<int>{-1, -2, -3, -4, -5};
    vector<int> res = solution.twoSum(data, -8);
    cout << res[0] << res[1] << endl;
}


