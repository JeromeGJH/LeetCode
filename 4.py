class Solution:
    def find(nums1, nums2):
        m  = len(nums1)
        n = len(nums2)

        if m == 0:
            if n == 0:
                return 0
            elif n == 1:
                return nums2[0]
            else:
                return nums2[n//2] if n%2 != 0 else (nums2[n//2 - 1]+nums2[n//2])/2.0
        if n == 0:
            if m == 1:
                return nums1[0]
            if m > 1:
                return nums1[m//2] if m%2 != 0 else (nums1[m//2 - 1]+nums1[m//2])/2.0
        
        mid1 = nums1[m//2] if m%2 != 0 else (nums1[m//2 - 1]+nums1[m//2])/2.0
        mid2 = nums2[n//2] if n%2 != 0 else (nums2[n//2 - 1]+nums2[n//2])/2.0

        if mid1 < mid2:
            return Solution.find(nums2, nums1)
        elif mid1 == mid2:
            return mid1

        flag1 = m%2
        flag2 = n%2

        m2 = m//2
        n2 = n//2

        if flag1 + flag2 == 0:
            n2 -= 1
        
        flag = (flag1 + flag2)%2

        while(True):
            if m2 < 0 or n2 == n:
                break
            if nums1[m2] > nums2[n2]:
                m2 -= 1
                n2 += 1
            else:
                break
        
        if n2 == n:
            if m == n:
                return (nums2[n2-1] + nums1[m2+1])/2
            if flag == 1:
                if n > m:
                    return nums2[n2 - 1]
                else:
                    return max(nums1[m2], nums2[n2-1])
            else:
                return (nums1[m2+1]+max(nums1[m2], nums2[n2-1]))/2.0
        elif m2 < 0:
            if flag == 1:
                return nums2[n2-1]
            else:
                return (min(nums2[n2], nums1[m2+1])+nums2[n2-1])/2.0
        elif nums1[m2] < nums2[n2]:
            if flag == 0:
                return (max(nums1[m2], nums2[n2-1]) + min(nums1[m2+1], nums2[n2]))/2.0
            else:
                return max(nums1[m2], nums2[n2-1])
        elif nums1[m2] == nums2[n2]:
                return nums1[m2]

    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        return Solution.find(nums1, nums2)
    
  
