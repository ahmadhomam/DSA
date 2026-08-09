class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 3 step algo  .
        // 1st find the breaking point from the last (smaller than next element)
        // 2nd find the first element greater than the breaking point from the last and swap it .
        // 3rd reverse the remaining element in the array.


        int index = -1 ;
        int n= nums.size() ;
        if(n== 1)
        return ;

        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                index = i ;
                break ;
            }
        }

        if(index == -1)
        return reverse(nums.begin(),nums.end()) ;

        for(int i=n-1;i>=0;i--){
            if(nums[i] > nums[index]){
                swap(nums[i],nums[index]) ;
                break ;
            }
        }

        return reverse(nums.begin()+index+1,nums.end()); 
    }
};