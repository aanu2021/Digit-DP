// Jay Saraswati Mai ki jaayyyy // 

// Time Complexity : O(logR*X*2*10) //

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll M = 1e9 + 7;

ll fact[200005];

ll mod(ll a){
    return ((a%M)+M)%M;
}

ll mul(ll a,ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a,ll b){
    return mod(mod(a)+mod(b));
}

ll dp[22][182][2];

ll func(string &num,ll n,ll x,bool tight){
    
    if(n==0){
        
        if(x==0){
            return 1LL;
        }else{
            return 0LL;
        }
        
    }
    
    if(dp[n][x][tight]!=-1){
        return dp[n][x][tight];
    }
    
    ll ans=0LL;
    
    ll ub=(tight ? num[num.length()-n]-'0' : 9);
    
    for(ll dig=0;dig<=ub;dig++){
        
        ans+=func(num,n-1,x-dig,(tight&(dig==ub)));
        
    }
    
    return dp[n][x][tight] = ans;
    
}

int main(){
    
    ll l,r,X;
    cin>>l>>r>>X;
    
    l--;
    
    string L=to_string(l);
    string R=to_string(r);
    
    memset(dp,-1,sizeof(dp));
    
    ll ans1=func(L,L.length(),X,true);
    
    memset(dp,-1,sizeof(dp));
    
    ll ans2=func(R,R.length(),X,true);
    
    cout<<(ans2-ans1)<<"\n";
    
    return 0;
    
}