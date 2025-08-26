class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result_intervals;
        // 舊區間為 null 的情況
        if(intervals.empty()) {
            result_intervals.push_back(newInterval);
            return result_intervals;
        }
        for(int i = 0;i < intervals.size();i++) {
            // 沒有重疊:新區間完全小於舊區間
            if(newInterval[1] < intervals[i][0]) {
                result_intervals.push_back(newInterval);
                while(i < intervals.size()) {
                    result_intervals.push_back(intervals[i]);
                    i++;
                }
                return result_intervals;
            }
            else {
                // 沒有重疊:新區間完全大於舊區間
                if(newInterval[0] > intervals[i][1]) {
                    result_intervals.push_back(intervals[i]);
                }
                // 有重疊:新區間和舊區間要比對最小值和最大值
                else {
                    int minimal = min(newInterval[0],intervals[i][0]);
                    int maximal = max(newInterval[1],intervals[i][1]);
                    newInterval[0] = minimal;
                    newInterval[1] = maximal;
                }
                // 若是最後一輪比較,要記得把新區間也加入結果裡面
                if(i == intervals.size() - 1) {
                    result_intervals.push_back(newInterval);
                }
            }
        }
        return result_intervals;
    }
};