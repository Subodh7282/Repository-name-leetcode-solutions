class Solution {
public:
    int findPeakElement(vector<int>& A) {
         int n = A.size();

        if(n==1) return 0;
        if(A[0]>A[1]) return 0;
        if(A[n-1]>A[n-2]) return n-1;

        int st = 1, end = n-2;

       while(st <=end) {
        int mid = st+(end-st)/2;

        if(A[mid-1]<A[mid] && A[mid+1]<A[mid]){
            return mid;
        } else if(A[mid-1]<A[mid]){
            st = mid+1;
        }else{
            end=mid-1;
        }
       } 
       return -1;
    }
};