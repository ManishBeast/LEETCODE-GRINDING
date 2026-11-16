class Solution {
public:
    string digitSum(string s, int k) {
        while(s.length()>k){
            string ch ="";
            for(int i=0;i<s.size();i+=k){
                int sum=0;
                for(int j=i;j<min(i+k,(int)s.size());j++){
                    sum+=s[j]-'0'; // new thing mila s.size() unassigned value deta h na ki int datatype rememberrrrrrrrrrr
                }
                ch+=to_string(sum);
            }
            s=ch;
        }
        return s;
    }
};