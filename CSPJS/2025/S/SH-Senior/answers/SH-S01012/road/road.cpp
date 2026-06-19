#include <bits/stdc++.h>
using namespace std;



int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k;
    cin >> n >> m >> k;
    long long ml[m][3];
    for(int i = 0;i<= m-1;i++)
    {
        cin >> ml[i][0] >> ml[i][1] >> ml[i][2];
    }
    long long kl[k];
    for(int i = 0;i<= k-1;i++)
    {
        cin >> kl[i];
    }
    return 0;
}

