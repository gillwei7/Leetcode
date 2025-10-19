class Solution {
public:
    /*
    由於需要回傳因數的數量和總和, 做一個 function 更容易, 且用 pair 回傳
    */ 

    /*
    這邊設定一個 function 可以回傳每個數因數的個數和總和,
    因數只要先取 number 開根號以下的數字就可以找到另一個比較大的因數, 可以找到根號以下的就可以結束了
    另外計算因數時, 如果找到超過四個因數也可以直接 return, 節省時間
    */
    pair<int, int> divisorNum(int number) {
        int cnt = 0;
        int sum = 0;
        for (int i = 1; i * i <= number; i++) {
            if (number % i == 0) {
                int j = number / i;
                if (i == j) { // number 是某個數的平方, 所以因數只有加一個
                    cnt++;
                    sum += i;
                } else {
                    cnt += 2;
                    sum += i + j;
                }
                if (cnt > 4) return {0, cnt}; // 因數大於 4 了, 不會等於 4, 先結束
            }
        }
        return {sum, cnt};
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto p = divisorNum(nums[i]);
            if (p.second == 4) {
                result += p.first;
            }
        }
        return result;
    }
};
