using ll = long long;
class Solution {
public:
    ll gcd(ll a,ll b){
        while(b!=0){
            ll temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
    ll lcm(ll a,ll b){
        return (a/gcd( a, b))*b;
    }
    ll solve(vector<int>&coins,ll x){
        int n = coins.size();
        ll ans=0;
        for(int mask=1;mask<(1<<n);mask++){
            ll multiple=1;
            ll bits=0;
            for(int i=0;i<n;i++){
                if((mask & (1<<i))!=0){
                    bits++;
                    multiple = lcm(multiple,coins[i]);
                    if(multiple>x) break;
                }
            }
            if(multiple>x) continue;
            ll value = x/multiple;
            if(bits%2==1) ans+=value;
            else ans-=value; 
        }
        return ans;
    }
    ll findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        ll left = 1;
        ll right = 1LL*k*(*min_element(coins.begin(),coins.end()));
        while(left<right){
            ll mid = left + (right-left)/2;
            ll m = solve(coins,mid);
            if(m>=k){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};