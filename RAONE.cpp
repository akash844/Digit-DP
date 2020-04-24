#include<bits/stdc++.h>
#define int long long
#define M 1000000007
#define deb(x) cout<<#x<<'='<<x<<endl;
using namespace std;
const int N=1e6;
int dp[10][40][40][2];
 
int g(string n, int pos=0, int sumo=0,int sume=0, bool tight=1)
{
    if (pos==n.length())
        return ((sume-sumo)==1);
    else if (dp[pos][sumo][sume][tight]!=-1)
        return dp[pos][sumo][sume][tight];
    else if (tight)
    {
        int res=0;
        for(int i=0; i<=n[pos]-'0'; i++)
        {
            if (i==(n[pos]-'0'))
            {
                if ((n.length()-pos)&1)
                    res+=g(n,pos+1,sumo+i,sume,1);
                else
                    res+=g(n,pos+1,sumo,sume+i,1);
            }
            else
            {
                if ((n.length()-pos)&1)
                    res+=g(n,pos+1,sumo+i,sume,0);
                else
                    res+=g(n,pos+1,sumo,sume+i,0);
            }
        }
        dp[pos][sumo][sume][tight]=res;
        return res;
    }
    else
    {
        int res=0;
        for(int i=0; i<=9; i++)
        {
            if ((n.length()-pos)&1)
                res+=g(n,pos+1,sumo+i,sume,0);
            else
                res+=g(n,pos+1,sumo,sume+i,0);
        }
        dp[pos][sumo][sume][tight]=res;
        return res;
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
    reverse(ans.begin(), ans.end());
    return ans;
}
 
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        if (l)
            l--;        
        string a=to_str(l);
        string b=to_str(r);
        //deb(a);
        //deb(b);
        memset(dp,-1,sizeof(dp));
        int ans1=g(b);
        memset(dp,-1,sizeof(dp));
        int ans2=g(a);
        cout<<ans1-ans2<<endl;
    }
} 
