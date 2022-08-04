// Jay Saraswati Mai ki jaayyyy // 

// Time Complexity : O(logR*2) //

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

ll dp[22][2];


ll COUNT(string &num,ll n,bool tight){
    
    if(n==0){
        return 1LL;
    }
    
    if(tight==false){
        return pow(10LL,n);
    }
    
    ll ans=0LL;
    
    string right=num.substr(num.length()-n);
    
    ans+=stoll(right);
    ans++;
    
    return ans;
    
}


ll func(string &num,ll n,bool tight){
    
    if(n==0){
        return 0LL;
    }
    
    if(dp[n][tight]!=-1){
        return dp[n][tight];
    }
    
    ll ans=0LL;
    
    ll ub=(tight ? num[num.length()-n]-'0' : 9);
    
    for(ll dig=0;dig<=ub;dig++){
        
        ans+=dig*COUNT(num,n-1,(tight&(ub==dig)));
        
        ans+=func(num,n-1,(tight&(ub==dig)));
        
    }
    
    return dp[n][tight] = ans;
    
}

int main(){
    
    int t;
    cin>>t;
    
    while(t--){
        
        ll l,r;
        cin>>l>>r;
        
        l--;
        
        string L=to_string(l);
        string R=to_string(r);
        
        memset(dp,-1,sizeof(dp));
        
        ll ans1=func(L,L.length(),true);
        
        memset(dp,-1,sizeof(dp));
        
        ll ans2=func(R,R.length(),true);
        
        cout<<(ans2-ans1)<<"\n";
        
    }
    
    return 0;
    
}