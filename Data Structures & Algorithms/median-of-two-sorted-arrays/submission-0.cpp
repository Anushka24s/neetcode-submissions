class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         // Always binary search the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int left = 0;
        int right = m;

        // Number of elements that should be on the left side
        int half = (m + n + 1) / 2;

        while (left <= right) {

            // Partition nums1
            int partition1 = left + (right - left) / 2;

            // Partition nums2
            int partition2 = half - partition1;

            // Elements immediately around the partitions
            int nums1Left = (partition1 == 0) ? INT_MIN : nums1[partition1 - 1];
            int nums1Right = (partition1 == m) ? INT_MAX : nums1[partition1];

            int nums2Left = (partition2 == 0) ? INT_MIN : nums2[partition2 - 1];
            int nums2Right = (partition2 == n) ? INT_MAX : nums2[partition2];

            // Correct partition
            if (nums1Left <= nums2Right &&
                nums2Left <= nums1Right) {

                // Odd number of elements
                if ((m + n) % 2 == 1) {
                    return max(nums1Left, nums2Left);
                }

                // Even number of elements
                else {
                    int leftMax = max(nums1Left, nums2Left);
                    int rightMin = min(nums1Right, nums2Right);

                    return (leftMax + rightMin) / 2.0;
                }
            }

            // Too many elements taken from nums1
            else if (nums1Left > nums2Right) {
                right = partition1 - 1;
            }

            // Too few elements taken from nums1
            else {
                left = partition1 + 1;
            }
        }

        return 0.0;
    }
        
    
};
