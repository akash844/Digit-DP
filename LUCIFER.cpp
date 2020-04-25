#include<bits/stdc++.h>
#define int long long
using namespace std;
bool p[105];
int dp[10][50][50][2];
void seive()
{
    memset(p,1,sizeof(p));
    p[0]=p[1]=0;
    for (int i=2; i*i<=100; i++) 
    { 
        if (p[i]) 
        { 
            for (int j=i*i; j<=100; j+=i) 
                p[j] = false; 
        } 
    } 
}

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

int g(string n,int pos=0,int sumo=0,int sume=0,bool tight=1)
{
    if (pos==n.length())
    {
        int diff=sume-sumo;
        if (diff<0)
            return 0;
        else
            return (p[diff]);
    }
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

signed main()
{
    int t;
    cin>>t;
    seive();
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        if(l)   l--;
        string a=to_str(l);
        string b=to_str(r);
        memset(dp,-1,sizeof(dp));
        int ans1=g(b);
        memset(dp,-1,sizeof(dp));
        int ans2=g(a);
        cout<<ans1-ans2<<endl;
    }
}
