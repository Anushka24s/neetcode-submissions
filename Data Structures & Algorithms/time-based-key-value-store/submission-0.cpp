class TimeMap {
public:
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return "";
        }

        vector<pair<int, string>>& arr = mp[key];

        int left = 0;
        int right = arr.size() - 1;

        string ans = "";

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (arr[mid].first <= timestamp) {
                // This is a valid answer,
                // but maybe there is a later valid timestamp.
                ans = arr[mid].second;
                left = mid + 1;
            }
            else {
                // Timestamp is too large.
                right = mid - 1;
            }
        }

        return ans;
    }
};
