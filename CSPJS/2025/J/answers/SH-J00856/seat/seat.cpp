#include<bits/stdc++.h>
using namespace std;
int n,m;
int sc[105],d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
		if(i==1) d=sc[i];
	}
	sort(sc+1,sc+1+n*m);
	int num=n*m-(lower_bound(sc+1,sc+1+n*m,d)-sc)+1;
	reverse(sc+1,sc+1+n*m);
	int y=num/(2*n)*2+1,x=num%(2*n);
	if(x>n||x==0) cout<<y+1<<' '<<n-abs(x-n)+1<<endl;
	else cout<<y<<' '<<x<<endl;
	return 0;
}
