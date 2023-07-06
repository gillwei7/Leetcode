/*
Intuition
Simply do recursion and generate all the possible combinations to check if that combination result in target if not backtrack.

Approach
We ca use backtracking like the same way we generate all the sub sets of array here the thing is we have to check if the sum of that subset result in target or not . And also we should check repeatedly for the same element also so not call for i+1 instead i.

Complexity
Time complexity:O(n*2^n)
Space complexity:O(n*2^n)

*/

class Solution {
public:
    vector<vector<int>> ans;
    void backtrack( vector<int>&arr, int start, int remain, vector<int>& temp ){
        if(remain < 0) return;
        if(remain == 0) ans.push_back(temp);
        for(int i = start; i < arr.size(); i++ ){
            temp.push_back(arr[i]);
            backtrack(arr, i, remain - arr[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        backtrack(candidates, 0, target, temp);
        return ans;
    }
};