#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m, a[101], i, s, t, cnt=0;
	cin>>n>>m;
	for(i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	for(i=1; i<=n*m; i++) {
		if(a[1]>=a[i]) cnt++;
		else cnt==cnt;
	}
	t=floor((n*m)/cnt);
	if(t==1) s=n*m-cnt+1;
	else if(t%2!=0&&t!=1) s=n*m-cnt-(t-1)*m+1;
	else if(t%2==0) s=m-(n*m-cnt+1-(t-1)*m)+1;
	cout<<t<<' '<<s;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
