// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int start = 0;
        long long int end = n;
        long long int minBadVersion = n;
        long long int mid;

        while(start <= end) {
            mid = (start + end) / 2;
            if( isBadVersion(mid) ) {
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