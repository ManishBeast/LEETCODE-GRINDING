class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int maxi =0;
       
        for(int j=0;j<n;j++){
             map<float,int> mpp;
            for(int i=j+1;i<n;i++){
                float up = points[j][1]-points[i][1];
                float down = points[j][0]-points[i][0];
                if(down!=0){
                    float div = up/down;
                    mpp[div]++;
                }else{
                    mpp[1e5]++;
                }
            }
            for(auto it:mpp){
            int count = it.second;
            maxi = max(maxi,count);
            }
        }
        return maxi+1 ;
    }
};


