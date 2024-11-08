std::vector<std::vector<std::string>>
groupAnagrams(std::vector<std::string> &strs) {
  std::unordered_map<std::string, std::vector<std::string>> poses;
  for (const std::string &str : strs) {
    std::string sorted(str.begin(), str.end());
    std::sort(sorted.begin(), sorted.end());
    poses[sorted].push_back(str);
  }

  std::vector<std::vector<std::string>> res;
  for (const auto [k, v] : poses) {
    res.push_back(v);
  }

  return res;
}
