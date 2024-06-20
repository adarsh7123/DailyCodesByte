class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int lo = 1;
        int hi = (position.back() - position[0]) / (m - 1); // max posible
        int ans = 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2; // check for mid

            if (canWePlace(position, mid, m)) {
                // set ans to mid and move lo to mid + 1
                ans = mid;
                lo = mid + 1;
            } else {
                // if not feasible move hi to mid -1
                hi = mid - 1;
            }
        }
        return ans;
    }

private:
    bool canWePlace(const vector<int>& arr, int dist, int balls) {
        int ballCnt = 1;
        int last = arr[0];
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] - last >= dist) {
                ballCnt++;
                last = arr[i];
            }
            if (ballCnt >= balls)
                return true;
        }

        return false;
    }
};