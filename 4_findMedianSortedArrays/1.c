double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2,
                              int nums2Size) {
  int doubleMiddle = (nums1Size + nums2Size) % 2 == 0 ? 1 : 0;
  int middleIndex = doubleMiddle ? (nums1Size + nums2Size) / 2 - 1
                                 : (nums1Size + nums2Size) / 2;
  printf("doubleMiddle: %d, middleIndex: %d\n", doubleMiddle, middleIndex);
  int i = 0, j = 0;
  int index = 0;
  while (i < nums1Size || j < nums2Size) {
    if (index == middleIndex) {
      break;
    }
    int tmp1 = 0;
    int tmp2 = 0;
    if (i < nums1Size && j < nums2Size) {
      tmp1 = nums1[i];
      tmp2 = nums2[j];
      tmp1 > tmp2 ? j++ : i++;
      index++;
    } else if (i < nums1Size) {
      i++;
      index++;
    } else {
      j++;
      index++;
    }
  }
  printf("i: %d, j: %d\n", i, j);
  return 0;
}

#define ARRAY_SIZE(nums) sizeof(nums) / sizeof(nums[0])

void main() {
  int nums1[] = {1, 3};
  int nums2[] = {2};

  double ret = findMedianSortedArrays(nums1, ARRAY_SIZE(nums1), nums2,
                                      ARRAY_SIZE(nums2));
  printf("result: %f", ret);
  return;
}