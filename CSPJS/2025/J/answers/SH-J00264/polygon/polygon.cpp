#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int fl=1;
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]) fl=0;
	}if(fl && n<3){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==3){
		int q=a[1],w=a[2],e=a[3];
		if(q+w+e>2*e) cout<<1;
		else cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
