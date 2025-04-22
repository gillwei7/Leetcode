// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
// 除了一般的 binary search, 要多紀錄一個 min Bad version
// 因為最後一次把 middle 置換掉不會是 bad version
    int firstBadVersion(int n) {
        long long int start = 0;
        long long int end = n;
        long long int minBadVersion = n; 
        long long int mid;

        while(start <= end) {
            mid = (start + end) / 2;
            if( isBadVersion(mid) ) {
                // 記得這邊要把目前是 bad version 的 middle 記錄下來
                minBadVersion = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return minBadVersion;
    }
};