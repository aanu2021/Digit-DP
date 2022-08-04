// Jay Saraswati Mai ki jaayyyy // 

// Time Complexity : O(logR*2*2*2) --> O(logR) //

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

ll dp[22][2][2][2];

ll func(string &num,ll n,bool even,bool leading,bool tight){
    
    if(n==0){
        return 1LL;
    }
    
    if(dp[n][even][leading][tight]!=-1){
        return dp[n][even][leading][tight];
    }
    
    ll ans=0LL;
    
    if(even){
        
        vector<ll>digits={0,2,4,6,8};
        
        ll ub=(tight ? num[num.length()-n]-'0' : 9);
        
        for(ll dig:digits){
            
            if(dig<=ub){
                
                ans+=func(num,n-1,false,false,(tight&(ub==dig)));
                
            }
            
        }
        
    }
    
    else{
        
        vector<ll>digits={1,3,5,7,9};
        
        if(leading){
            
            ans+=func(num,n-1,false,true,false);
            
        }
        
        ll ub=(tight ? num[num.length()-n] - '0' : 9);
        
        for(ll dig:digits){
            
            if(dig<=ub){
                
                ans+=func(num,n-1,true,false,(tight&(ub==dig)));
                
            }
            
        }
        
    }
    
    return dp[n][even][leading][tight] = ans;
    
}

int main(){
    
    ll l,r;
    cin>>l>>r;
    
    l--;
    
    string L=to_string(l);
    string R=to_string(r);
    
    memset(dp,-1,sizeof(dp));
    
    ll ans1=func(L,L.length(),false,true,true);
    
    memset(dp,-1,sizeof(dp));
    
    ll ans2=func(R,R.length(),false,true,true);
    
    cout<<(ans2-ans1)<<"\n";
    
    return 0;
    
}