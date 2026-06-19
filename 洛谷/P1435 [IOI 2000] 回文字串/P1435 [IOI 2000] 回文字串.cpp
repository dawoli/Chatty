#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> f;
string s;
int main()
{
    cin>>s;
    const int n=s.size();
    f.resize(n+1,vector<int>(n+1,0));
    for (int i=0;i<n;i++)
    {
        f[i][i]=0;
    }
    for (int i=1;i<n-1;i++)
    {
        if (s[i]==s[i-1])f[i-1][i]=0;
        else f[i-1][i]=1;
    }
    for (int L=2;L<n;L++)
    {
        for (int i=0;i+L<n;i++)
        {
            int j=i+L;
            f[i][j]=min(f[i+1][j]+1,f[i][j-1]+1);
            if (s[i]==s[j])
            {
                f[i][j]=min(f[i][j],f[i+1][j-1]);
            }
        }
    }
    cout<<f[0][n-1]<<endl;
    return 0;
}