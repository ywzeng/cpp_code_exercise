class Solution_InsertSort {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Insert Sort
        vector<int>::iterator p1 = nums1.begin();
        for(vector<int>::iterator p2 = nums2.begin(); p2 != nums2.end(); ++p2) {
            while(p1 != nums1.end()) {
                if(*p2 <= *p1) {
                    p1 = nums1.insert(p1, *p2) + 1;
                    break;
                }
                ++p1;
            }
            // Push all the items from num2 to num1.
            if(p1 == nums1.end()) {
                nums1.insert(nums1.end(), p2, nums2.end());
                break;
            }
        }
        int len = nums1.size();
        if(len % 2 == 0) {
            return (nums1[len/2-1] + nums1[len/2]) / 2.0;
        } else {
            return nums1[len/2] / 1.0;
        }
    }
};
