class Solution {
public:
    bool help(vector<int>& arr, int meet, int gap1, int gap2) {
        cout << meet << endl;
        auto it = lower_bound(arr.begin(), arr.end(), meet);
        while (it != arr.end()) {
            int val = *it;
            int count = upper_bound(it, arr.end(), val) -
                        lower_bound(it, arr.end(), val);
            int used = 0;
            if (val == gap1)
                used++;
            if (val == gap2)
                used++;

            if (count > used)
                return true;

            it = upper_bound(it, arr.end(), val);
        }
        return false;
    }

    int maxFreeTime(int eventTime, vector<int>& startTime,
                    vector<int>& endTime) {
        int n = startTime.size();
        vector<int> diff(n + 1, 0);
        diff[0] = startTime[0] - 0;
        for (int i = 1; i < n; i++) {
            diff[i] = startTime[i] - endTime[i - 1];
        }
        diff[n] = eventTime - endTime[n - 1];
        sort(diff.begin(), diff.end());
        for (auto it : diff)
            cout << it << " ";
        cout << endl;
        int maxi = diff[n];
        for (int i = 0; i < n; i++) {
            int meet = endTime[i] - startTime[i];
            int gap1 = startTime[i] - (i == 0 ? 0 : endTime[i - 1]);
            int gap2 = (i + 1 == n ? eventTime : startTime[i + 1]) - endTime[i];
            maxi = max(maxi, gap1 + gap2);
            bool ans = help(diff, meet, gap1, gap2);
            if (ans)
                maxi = max(maxi, meet + gap1 + gap2);
        }
        return maxi;
    }
}; 