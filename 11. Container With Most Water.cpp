class Solution {
public:
    int maxArea(vector<int>& height) {
        int result_pre = 0, result_now;
	// Check 所有的長方形面積大小, 尋找最大的可能性
	// i從0到最高, j 從i+1到最高
        for(int i = 0; i < height.size(); i++)
        {
            for(int j = i+1; j < height.size(); j++)
            {
	        //長方形面積為為取兩根中的較低值 * 相減的絕對值
                result_now = min(height[i], height[j]) * abs(height[i] - height[j]);
		//如果新的結果較高的話就更新結果
                result_pre = max(result_pre, result_now);
            }
        }
        return result_pre;
    }
};
