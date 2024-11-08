bool containsDuplicate(std::vector<int> &nums) {
  std::unordered_set<int> uniq;
  for (int num : nums) {
    if (uniq.contains(num)) {
      return true;
    }
    uniq.insert(num);
  }
  return false;
}
