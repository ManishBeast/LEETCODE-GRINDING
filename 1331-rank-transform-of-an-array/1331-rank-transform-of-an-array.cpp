class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp=arr;
        sort(arr.begin(),arr.end());
        int rank =1;
        map<int,int> mpp;
        for(int i =0;i<arr.size();i++){
            if(mpp.find(arr[i])==mpp.end()){
                mpp[arr[i]]= rank;
                rank++;
            }
        }
        for(int i=0;i<arr.size();i++){
            temp[i] = mpp[temp[i]];
        }
        return temp;
    }
};