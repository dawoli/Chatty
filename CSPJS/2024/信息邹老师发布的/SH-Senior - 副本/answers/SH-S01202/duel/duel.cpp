#include<bits/stdc++.h>
using namespace std;
int n,a[100006],b[100006],t,h;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	t=1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]) a[i-1]=0;
		else{
			if(h>=t&&b[t]<a[i]) t++;
			h++;
			b[h]=a[i-1];
		}
	}
	cout<<h-t+2+n-n;
	return 0;
}
