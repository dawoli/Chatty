#include<bits/stdc++.h>
using namespace std;
int n,r[100020],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>r[i];
	sort(r+1,r+n+1);
	for(int i=1,pos=1;i<=n;i++,pos++){
		while(r[pos]<=r[i]&&pos<=n)
			pos++;
		if(pos>n) break;
		else ans++;
	}
	cout<<n-ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
