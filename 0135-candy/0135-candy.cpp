class Solution {
public:
    int candy(vector<int>& rating) {
        int n= rating.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        
        // yeh sochna is difficult bro .....
        // left se chekc krte chlo abd right se check krte chlo and bro done dono ka max lelo

        for(int i=1;i<n;i++){
            if(rating[i-1]<rating[i]){
                left[i] = left[i-1]+1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(rating[i+1]<rating[i]){
                right[i] = right[i+1]+1;
            }
        }
        int ans=0;
        for(int i=0;i<left.size();i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};