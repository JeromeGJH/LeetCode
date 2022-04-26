class Solution {
public:
  int maximumRemovals(string s, string p, vector<int>& removable) {
    int left = 0, right = removable.size() - 1;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (check(s, p, removable, mid)) left = mid + 1;
      else right = mid - 1;
    }
    return left;
  }

  bool check(string s, string& p, vector<int>& removable, int index) {
    int i = 0, j = 0;
    for (int k = 0; k <= index; ++k) s[removable[k]] = '#'; 
    while (i < s.size() && j < p.size()) {
      if (s[i] == p[j]) j++;
      i++;
    }
    return j == p.size();
  }
};
