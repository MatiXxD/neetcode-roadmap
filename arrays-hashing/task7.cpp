std::vector<int> productExceptSelf(std::vector<int> &nums) {
  std::vector<int> prefix(nums.size());
  std::vector<int> suffix(nums.size());

  prefix[0] = suffix[nums.size() - 1] = 1;
  for (int i = 1; i != nums.size(); ++i) {
    prefix[i] = prefix[i - 1] * nums[i - 1];
    suffix[nums.size() - 1 - i] =
        suffix[nums.size() - i] * nums[nums.size() - i];
  }

  std::vector<int> result(nums.size());
  for (int i = 0; i != nums.size(); ++i) {
    result[i] = prefix[i] * suffix[i];
  }

  return result;
}
