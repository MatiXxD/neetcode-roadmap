int longestConsecutive(std::vector<int> &nums) {
  std::unordered_map<int, int> seqLens;

  int max = 0;
  for (const auto &num : nums) {
    if (!seqLens[num]) {
      seqLens[num] = seqLens[num - 1] + seqLens[num + 1] + 1;
      seqLens[num - seqLens[num - 1]] = seqLens[num];
      seqLens[num + seqLens[num + 1]] = seqLens[num];
      max = std::max(max, seqLens[num]);
    }
  }

  return max;
}
