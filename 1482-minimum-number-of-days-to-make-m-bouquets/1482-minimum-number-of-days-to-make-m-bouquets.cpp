class Solution {
public:
    int check(vector<int>&bloomDay,int mid,int k){
        vector<int> time(bloomDay.size());
        int i =0;
        int cnt =0;
        int ans =0;
        while(i<bloomDay.size()){
            if(bloomDay[i]<=mid ){
                cnt++;
                if(cnt==k){
                cnt=0;
                ans++;
                }
            }else{
                cnt=0;
            }
            i++;
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if (1LL * m * k > bloomDay.size())
            return -1; //yeh bhi likhna h as u are assignning left and right something something so if contrain hi satisfied nhi h then u can't help right.
        int left = 1;
        int right = *max_element(bloomDay.begin(),bloomDay.end());
        while(left<right){
            int mid = (right-left)/2+left;
            int l = check(bloomDay,mid,k);
            if(l>=m){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};