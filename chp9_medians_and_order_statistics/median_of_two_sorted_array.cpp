#define MIN(a,b) ((a) < (b) ? (a) : (b))
int findKthTwo(int *nums1, int *nums2, int size1, int size2, int k)
{
    if(size1 > size2)
        return findKthTwo(nums2, nums1, size2, size1, k);//always put the short one first
    if(size1 == 0)
        return nums2[k - 1];//fast jump out
    if(k == 1)
        return MIN(nums1[0], nums2[0]);
    int i = MIN(k / 2, size1);
    int j = MIN(k / 2, size2);
    if(nums1[i - 1] > nums2[j - 1])
        return findKthTwo(nums1, nums2 + j, size1, size2 - j, k - j);
    else
        return findKthTwo(nums1 + i, nums2, size1 - i, size2, k - i);
}


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{
    int mid1 = findKthTwo(nums1, nums2, nums1Size, nums2Size, (nums1Size + nums2Size + 2) >> 1);//put the k th
    int mid2 = findKthTwo(nums1, nums2, nums1Size, nums2Size, (nums1Size + nums2Size + 1) >> 1);
    return (mid1 + mid2) / 2.0;
}