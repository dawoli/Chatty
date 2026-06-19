#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a,y,k,cnt;
    cnt=1;
    cin >>n>>m;
    cin >> a;
    for(int i=2;i<=n*m;i++)
    {
        cin >> k;
        if(k>a){
            cnt++;
			}
    }
    int x=cnt/n+1;
    if(x%2==1)
    {
        y=cnt%n;
    }
    else{
        y=n+1-(cnt%m);
    }
    cout <<x<<" "<<y;
}
