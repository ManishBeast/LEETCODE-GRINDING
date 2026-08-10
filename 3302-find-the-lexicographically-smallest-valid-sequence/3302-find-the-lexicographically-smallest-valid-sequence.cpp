class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> suffix(n+1,m);
        int j =m-1;
        int count =0;
        for(int i=n-1;i>=0;i--){
            if(j>=0 && word1[i]==word2[j]){
                j--;
            }
            suffix[i] = j+1;
        }
        int i = 0;
        j = 0;
        vector<int> ans;
        bool used = false;
        while(i<n && j<m){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }else if(!used){
                if(suffix[i + 1] <= j + 1){ // suffix mtlb kitna element match krna baaki h and j+1 means kitne element abhi available h as if required element to match toh km hona chahiye na total element left se otherwise kbhi match kr hi nhi paunga 
                    ans.push_back(i);
                    j++;
                    used = true;
                }
            }
            i++;
        }
        if(ans.size()!=m) return {};
        return ans;
    }
};