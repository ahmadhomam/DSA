class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int i=0; int j= arr.size()-1;
        int cnt = 0;
        while(i<=j){
            int sum = arr[i]+arr[j];
            if(sum == target){
                if(arr[i] == arr[j]){
                    int n = j-i+1;
                    cnt += (n*(n-1))/2;
                    break;
                }else {
                    int prev_i =i, prev_j = j;
                    while(i<j && arr[i]==arr[prev_i]) i++;
                    while(j>=i && arr[j]== arr[prev_j]) j--;
                    cnt += (i-prev_i)*(prev_j-j);
                }
            }
            if(sum>target){
                j--;
            }
            if(sum<target) i++;
        }
        return cnt;
    }
};