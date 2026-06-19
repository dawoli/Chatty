#include <bits/stdc++.h>
using namespace std;
int n,x,m[100005],p[100005],t,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++){
		cin >> x;
		if(m[x]==0){
			t++;
			p[t] = x;
		}
		m[x]++;
	}
	sort(p+1,p+t+1);
	for(int i = 1;i<=t;i++) ans+=max(0,m[p[i]]-m[p[i+1]]);
	cout << ans << endl;
	return 0;
}
