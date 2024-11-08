constexpr int NUM_FIELD_SIZE = 3;

std::string encodeLength(size_t len) {
  std::string strLen = std::to_string(len);
  while (strLen.length() != NUM_FIELD_SIZE) {
    strLen = "0" + strLen;
  }
  return strLen;
}

std::string encode(std::vector<std::string> &strs) {
  std::string res;
  for (auto str : strs) {
    res += encodeLength(str.length()) + str;
  }
  return res;
}

size_t decodeLength(std::string str, size_t pos) {
  std::string strLen = str.substr(pos, NUM_FIELD_SIZE);
  return std::stoi(strLen);
}

std::vector<std::string> decode(std::string s) {
  if (s.length() == 0) {
    return {};
  }

  size_t i = 0;
  std::vector<std::string> res;
  while (i < s.length()) {
    size_t len = decodeLength(s, i);
    i += NUM_FIELD_SIZE;
    res.push_back(s.substr(i, len));
    i += len;
  }

  return res;
}
