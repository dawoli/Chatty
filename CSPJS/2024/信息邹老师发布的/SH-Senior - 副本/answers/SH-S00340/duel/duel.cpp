#include<bits/stdc++.h>
using namespace std;

int r[100010];
int cnt[100010];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> r[i];
    for(int i = 1;i <= n;i++)cnt[r[i]]++;
    int last = 0,ans = 0;
    for(int i = 1;i <= 100000;i++)
    {
        if(cnt[i] >= last)
        {
     	    ans += last;
    	    last = cnt[i];
     	}
   		 else ans += cnt[i];
    }
    cout << n - ans;
    return 0;
}
