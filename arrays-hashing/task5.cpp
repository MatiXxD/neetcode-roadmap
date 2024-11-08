std::vector<int> topKFrequent(std::vector<int> &nums, int k) {
  std::unordered_map<int, int> counts;
  for (const auto &num : nums) {
    counts[num]++;
  }

  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>>
      heap;
  for (const auto &[num, count] : counts) {
    heap.push({count, num});
    if (heap.size() > k) {
      heap.pop();
    }
  }

  std::vector<int> res;
  for (int i = 0; i != k; ++i) {
    res.push_back(heap.top().second);
    heap.pop();
  }

  return res;
}
