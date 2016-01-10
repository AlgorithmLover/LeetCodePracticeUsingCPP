//
// Created by cheyulin on 1/4/16.
//
#include "../my_header.hpp"

using namespace std;

class Solution {
 public:
  void wiggleSort(vector<int> &nums) {
    if (nums.size() < 2) {
      return;
    }
    int nth = nums.size() / 2;
    nth_element(nums.begin(), nums.begin() + nth, nums.end());
//    cout << "Nth Number:" << *(nums.begin() + nth) << endl;
    int middle_value = *(nums.begin() + nth);
    int small_count = 0;
    int middle_count = 0;
    int big_count = 0;
    for (auto integer:nums) {
      if (integer == middle_value) {
        middle_count++;
      }
      else {
        integer < middle_value ? small_count++ : big_count++;
      }
    }
//    cout << "Small:" << small_count << " Middle:" << middle_count << " Big:" << big_count << endl;
    int middle_to_small_count = nums.size() % 2 == 0 ? nums.size() / 2 - small_count : nums.size() + 1 - small_count;
//    cout << "Middle To Small Count:" << middle_to_small_count << endl;

    int next = 0;
    //Init Middle As Small
    for (auto &integer:nums) {
      if (integer == middle_value) {
        swap(integer, nums[next]);
        next += 2;
      }
    }

//    Morph Middle As Big
    int rev_next = nums.size() % 2 == 0 ? nums.size() - 1 : nums.size() - 2;
    for (int i = 0; i < middle_count - middle_to_small_count; i++) {
      next -= 2;
      swap(nums[next], nums[rev_next]);
      rev_next -= 2;
    }

//   Swap Big And Small
    int index_of_big = middle_to_small_count * 2;
    int index_of_small = 1;
    while (true) {
      while (!(nums[index_of_big] > middle_value) && index_of_big < nums.size()) {
        index_of_big += 2;
      }
      while (!(nums[index_of_small] < middle_value) && index_of_small < nums.size()) {
        index_of_small += 2;
      }
      if (index_of_big > nums.size() || index_of_small > nums.size()) {
        break;
      }
      else {
        swap(nums[index_of_big], nums[index_of_small]);
      }
    }
  }
};

void test(initializer_list<int> init_vals) {
  vector<int> nums;
  for (auto integer: init_vals) {
    nums.push_back(integer);
  }
  Solution solution;
  solution.wiggleSort(nums);
  cout << "--------------" << endl;
  for (auto my_int:nums) {
    cout << my_int;
  }
  cout << endl;
  cout << "----" << endl;
}

int main() {
  test({1, 5, 1, 1, 6, 4});
  test({1, 3, 2, 2, 3, 1});
  test({6, 3, 2, 1, 4, 5});
}
