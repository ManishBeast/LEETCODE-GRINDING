class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right =height.size()-1;
        int maxi =0;
        while(left<right){
            int shorter = min(height[right],height[left]);
            int water = shorter*(right-left);
            maxi = max(maxi,water);
            if(shorter!=height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi ;
    }
};