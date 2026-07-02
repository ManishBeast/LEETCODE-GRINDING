class Solution {
public:
    
    bool checkValidString(string s) {
        int max=0;
        int min =0;
        int n =s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                max+=1;
                min+=1;
            }else if(s[i]==')'){
                min-=1;
                max-=1;
            }else{
                min-=1;
                max+=1;
            }
            if(min<0) min=0;
            if(max<0) return false; // bz this is only inxrease in every exacept * so if this negative means inspite of consideration of * this is false; 
        }
        return min==0;
    }
};