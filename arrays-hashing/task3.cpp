std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> numsToTarget;
  for (int i = 0; i != nums.size(); ++i) {
    if (numsToTarget.find(nums[i]) != numsToTarget.end()) {
      return {numsToTarget[nums[i]], i};
    }
    numsToTarget.insert({target - nums[i], i});
  }
  return {};
}
