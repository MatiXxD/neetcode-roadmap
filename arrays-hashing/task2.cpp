bool isAnagram(std::string s, std::string t) {
  if (s.length() != t.length()) {
    return false;
  }

  std::vector<int> letterCount(26, 0);
  for (size_t i = 0; i < s.length(); ++i) {
    letterCount[s[i] - 'a']++;
    letterCount[t[i] - 'a']--;
  }

  for (int val : letterCount) {
    if (val != 0) {
      return false;
    }
  }

  return true;
}
