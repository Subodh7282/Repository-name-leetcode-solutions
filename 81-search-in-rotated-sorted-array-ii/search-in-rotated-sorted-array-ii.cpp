class Solution {
public:
    bool search(vector<int>& A, int tarr) {
        int st = 0, end = A.size() - 1; // Fixed bound
        
        while (st <= end) {
            int mid = st + (end - st) / 2;
            
            // Fixed element check
            if (A[mid] == tarr) {
                return true;
            }
            
            // Fixed duplicate check
            if (A[st] == A[mid] && A[mid] == A[end]) {
                st++;
                end--;
                continue;
            }
            
            // Left half is sorted
            if (A[st] <= A[mid]) {
                if (A[st] <= tarr && tarr < A[mid]) { // Fixed condition
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (A[mid] < tarr && tarr <= A[end]) { // Fixed condition
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        
        return false;
    }
};