// 再度複習區間是否重疊, 需要比較新進來的interval 最小值, 是否比原interval最大值還要小
// 這樣的話就可以確定是重疊

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> result;
       if(intervals.size() == 0) return result; // 檢查intervals是否為空
       sort(intervals.begin(), intervals.end()); // Interval 的問題總是需要先進行排序
       result.push_back(intervals[0]); // 首先先把interval[0]放進去, 再從[1]開始一個一個比較
       int j = 0; // result 的比較從[0]開始
       for(int i = 1;i < intervals.size();i++)
       {
           // 如果新進來的interval有跟原本的interval重疊到
           if(result[j][1] >= intervals[i][0] )
           {
               // 重新設定目前的interval區間, 因為intervals已經排序過了, 不會有後面的interval最小值反而比較小的情況 
               result[j][1] = max(result[j][1], intervals[i][1]);
           }
           else // 如果新進來的interval沒有跟原本的interval重疊到
           {
               // 不用重新設定區間, 只要把現在的interval加入即可
               j++;
               result.push_back(intervals[i]);
           }
       }
       return result;
    }
};