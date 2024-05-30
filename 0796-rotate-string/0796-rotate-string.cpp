class Solution {
public:
  bool rotateString(string s, string goal) {
    if (s.length() != goal.length()) {
      return false; // Early exit if lengths differ
    }
    string combined = s + s; // Combine strings for easier search

    // Find the first occurrence of goal in the combined string
    size_t found = combined.find(goal);
    return found != std::string::npos; // Check if goal was found
  }
};
