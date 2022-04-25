class Solution {
public:
    bool check(int x, vector<int>& position, int m) {
        int pre = position[0], cnt = 1;
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - pre >= x) {
                pre = position[i];
                cnt += 1;
            }
        }
        return cnt >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1, right = position.back() - position[0];
        while (left < right) {
            int mid = (left + right) / 2 + 1;
            if (check(mid, position, m)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
