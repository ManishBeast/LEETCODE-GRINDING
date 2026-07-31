class Solution {
public:
    int maxDistance(string moves) {
        int R =0;
        int L =0;
        int U =0;
        int D =0;
        int blank =0;
        for(auto it:moves){
            if(it=='R')R++;
            else if(it=='L')L++;
            else if(it=='U')U++;
            else if(it=='D')D++;
            else blank++;
        }
        return abs(R-L)+abs(U-D)+blank;
    }
};