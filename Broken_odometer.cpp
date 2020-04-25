#include<bits/stdc++.h>
#define M 1000000007
#define deb(x) cout<<#x<<'='<<x<<endl;
using namespace std;
const int N=1e6;
int dp[10][10][2];

string to_str(int n)
{
    string ans;
    while(n>0)
    {
        ans+=((n%10)+'0');
        n/=10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int g(string n,int pos=0, int c=0, bool tight=1)
{
    if (pos==n.length())
        return (c>0);
    else if (dp[pos][c][tight]!=-1)
        return dp[pos][c][tight];
    else if (tight)
    {
        int res=0;
        for(int i=0; i<=n[pos]-'0'; i++)
        {
            if (i==(n[pos]-'0'))
            {
                if(i==3)
                    res+=g(n,pos+1,c+1,1);
                else
                    res+=g(n,pos+1,c,1);
            }
            else
            {
                if(i==3)
                    res+=g(n,pos+1,c+1,0);
                else
                    res+=g(n,pos+1,c,0);
            }
        }
        dp[pos][c][tight]=res;
        return res;
    }
    else
    {
        int res=0;
        for(int i=0; i<=9; i++)
        {
            if (i==3)
                res+=g(n,pos+1,c+1,0);
            else
                res+=g(n,pos+1,c,0);
        }
        dp[pos][c][tight]=res;
        return res;
    }
}

signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s=to_str(n);
        memset(dp,-1,sizeof(dp));
        int ans=g(s);
        cout<<n-ans<<endl;
    }
}
