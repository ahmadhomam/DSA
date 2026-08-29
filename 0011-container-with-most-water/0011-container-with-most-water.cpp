class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0 ;
        int j = height.size()-1 ;
        int maxarea = 0 ;

        while(i<j){
            int h = min(height[i],height[j]) ;
            int l = j-i ;
            maxarea = max(maxarea,h*l) ;

            if(height[i]>height[j])
            j-- ;
            else
            i++ ;
        }

        return maxarea ;
        
    }
};