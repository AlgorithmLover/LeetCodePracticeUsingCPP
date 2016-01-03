#My Notes By Yche

## 2015 11/17 Find Duplicate Number:
* solution 1 from the perspective of numbers, use binary search on these nums to eliminate impossible choices. 
* solution 2 a little bit tricky use. 

+ slow: x+y 
+ fast: 2x+2y and we can figure out that y<=c 
+ x-1 = k*c - y -1 the node before the entrance of the ring 

```cpp
  	// With O(n) Time Complexity
    // Refer to the forum
    int findDuplicateCyclicList(vector<int> &nums) {
        if (nums.size() == 0)
            return 0;
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (fast != slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
```

## 2015 11 18 range sum array 
* solution use map to save index,deltaValue, use sum to save sum, and keep vector for nums when map.size square is about array size, we rebuild sum
* time complexity O(sqrt(n))

## 2015 12 08 single number 1-3 
* solution use bit operation with cosntant memory 
