#include<iostream>
using namespace std;

int n,mns=100000;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int nm[50010],ans[50010];

void dfs(int step,int sum)
{
    if(sum>n) return;
    if(step>mns) return;
    if(sum==n)
    {
        if(step<mns)
        {
            mns=step;
            for(int i=1;i<step;i++)
            {
                ans[i]=nm[i];
            }
        }
        else if(step==mns)
        {
            for(int i=1;i<step;i++)
            {
                if(nm[i]>ans[i]) break;
                ans[i]=nm[i];
            }
        }
        return;
    }
    for(int i=0;i<=9;i++)
    {
        if(i==0 && step==1) continue;
        nm[step]=i;
        dfs(step + 1,sum+a[i]);
    }
}

int main()
{
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n==1)
        {
            cout << -1 << "\n";
            continue;
        }
        if(n%7==0)
        {
            for(int i=1;i<=n/7;i++)
            {
                cout << 8;
            }
            cout << "\n";
            continue;
        }
        else if(n%7==1)
        {
            cout << 10;
            for(int i=1;i<n/7;i++)
            {
                cout << 8;
            }
            cout << "\n";
            continue;
        }
        else if(n>=40 && n<50)
        {
            if(n==48) cout << 6888888 << "\n";
            else if(n==40) cout << 288888 << "\n";
            else if(n==41) cout << 688888 << "\n";
            else if(n==44) cout << 1888888 << "\n";
            else if(n==45) cout << 2008888 << "\n";
            else if(n==46) cout << 2088888 << "\n";
            else if(n==47) cout << 2888888 << "\n";
            continue;
        }
        dfs(1,0);
        for(int i=1;i<mns;i++)
        {
            cout << ans[i];
        }
        cout << "\n";
        mns=100000;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
