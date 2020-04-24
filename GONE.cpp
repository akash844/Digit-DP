#include<bits/stdc++.h>
#define int long long
#define M 1000000007
#define deb(x) cout<<#x<<'='<<x<<endl;
using namespace std;
const int N=1e6;
bool p[80];
int dp[10][80][2];
void seive()
{
    memset(p,1,sizeof(p));
    p[1]=p[0]=0;
    for (int i=2; i*i<=80; i++) 
    { 
        if (p[i] == true) 
        { 
            for (int j=i*i; j<=80; j+=i) 
                p[j] = false; 
        } 
    } 
}

string to_str(int n)
{
    string ans;
    while(n>0)
    {
        int r=n%10;
        ans+=('0'+r);
        n/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int g(string n, int pos=0, int sum=0, bool tight=1)
{
    if (pos==n.length())
        return p[sum];
    else if (dp[pos][sum][tight]!=-1)
        return dp[pos][sum][tight];
    else if (tight)
    {
        int res=0;
        for(int i=0; i<=n[pos]-'0'; i++)
        {
            if (i==n[pos]-'0')
                res+=g(n,pos+1,sum+i,1);
            else
                res+=g(n,pos+1,sum+i,0);
        }
        dp[pos][sum][tight]=res;
        return res;
    }
    else
    {
        int res=0;
        for(int i=0; i<=9; i++)
        {
            res+=g(n,pos+1,sum+i,0);
        }
        dp[pos][sum][tight]=res;
        return res;
    }
}

signed main()
{
    
    seive();
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        l--;        
        string a=to_str(l);
        string b=to_str(r);
        memset(dp,-1,sizeof(dp));
        int ans1=g(b);
        memset(dp,-1,sizeof(dp));
        int ans2=g(a);
        cout<<ans1-ans2<<endl;
    }
}
