#include "headers.h"

using namespace std;
 
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double sum = 0;
        // median count
        int count = (nums1.size() + nums2.size()) % 2 == 0 ? 2 : 1;
        // median index
        int median = (nums1.size() + nums2.size()) / 2;
        int start = count == 2 ? median - 1 : median;
        
        int i = 0, j = 0;
        int index = 0;
        int value = 0;
        int tmpcount =count;
        while (index <= median) {
                   
            if (index >= start && tmpcount-- > 0) {
                int value = 0;
                if (i < nums1.size() && j < nums2.size()) {
                    value = nums1[i] > nums2[j] ? nums2[j] : nums1[i];
                } else if (i >= nums1.size()) {
                    value = nums2[j];
                } else {
                    value = nums1[i];
                }
                sum += value;
            }
            if (i >= nums1.size()) {
                j++;
            } else if (j >= nums2.size()) {
                i++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
            
            index++;
        }
        return sum / count;
    }
};

int main(int argc, char **argv)
{
    vector<int> a = {1,2};
    vector<int> b = {3,4};
    Solution s;
    cout << s.findMedianSortedArrays(a, b) << endl;
    
}