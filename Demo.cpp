// Jay Saraswati Mai ki jaayyyy // 

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

ll dp[22][12][2][2];

ll func(string &num,ll n,ll prev,bool leading,bool tight){
    
    if(n==0){
        
        return 1LL;
        
    }
    
    if(dp[n][prev][leading][tight]!=-1){
        
        return dp[n][prev][leading][tight];
        
    }
    
    ll ans=0LL;
    
    ll ub=(tight ? num[num.length()-n]-'0' : 9);
    
    // if(leading){
        
    //     ans+=func(num,n-1,prev,true,false);
        
    // }
    
    for(ll dig=0;dig<=ub;dig++){
        
        if(dig==prev && leading==false){
            continue;
        }
        
        ans+=func(num,n-1,dig,(leading & (dig==0)),(tight&(ub==dig)));
        
    }
    
    return dp[n][prev][leading][tight]=ans;
    
}

int main(){
    
    ll l,r;
    cin>>l>>r;
    
    if(l==0){
        
        string R=to_string(r);
        
        memset(dp,-1,sizeof(dp));
        
        ll ans=func(R,R.length(),10,true,true);
        
        cout<<ans<<"\n";
        
    }
    
    else{
        
        l--;
        
        string L=to_string(l);
        string R=to_string(r);
        
        memset(dp,-1,sizeof(dp));
        
        ll ans1=func(L,L.length(),10,true,true);
        
        memset(dp,-1,sizeof(dp));
        
        ll ans2=func(R,R.length(),10,true,true);
        
        cout<<(ans2-ans1)<<"\n";
        
    }
    
    return 0;
    
}