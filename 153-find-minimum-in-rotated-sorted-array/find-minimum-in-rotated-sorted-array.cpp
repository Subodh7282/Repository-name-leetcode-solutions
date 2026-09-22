class Solution {
public:
    int findMin(vector<int>& A) {
         int st= 0, end= A.size()-1;
          int ans=INT_MAX;

          while(st<=end){
            int mid= st+(end-st)/2;
            if(A[st]<= A[mid]){
                ans= min(ans,A[st]);
                st= mid+1;
            }else{
                end= mid-1;
                ans= min(ans, A[mid]);

            }
          }
          return ans;


    }
};