class Solution_BinarySearch {
public:
    // K-th starts from 1.
    int getkth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        int len1 = nums1.size() - i;
        int len2 = nums2.size() - j;
        // Make sure the nums1 is shorter than nums2.
        if(len1 > len2) {
            return getkth(nums2, j, nums1, i, k);
        }
        if(len1 == 0) {
            return nums2[j + k - 1];
        }
        if(k == 1) {
            return min(nums1[i], nums2[j]);
        }

        int p1 = i + min(len1, k/2) - 1;
        int p2 = j + min(len2, k/2) - 1;

        if(nums1[p1] > nums2[p2]) {
            return getkth(nums1, i, nums2, p2 + 1, k - (p2 - j + 1));
        } else {
            return getkth(nums1, p1 + 1, nums2, j, k - (p1 - i + 1));
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k1 = (nums1.size() + nums2.size() + 1) / 2;
        int k2 = (nums1.size() + nums2.size() + 2) / 2;
        return (getkth(nums1, 0, nums2, 0, k1) + getkth(nums1, 0, nums2, 0, k2)) / 2.0;
    }
};


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
