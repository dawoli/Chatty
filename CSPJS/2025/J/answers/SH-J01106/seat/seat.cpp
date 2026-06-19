#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109];
int pai(){
	int ans=1;
	while(1){
		bool b=1;
		for(int i=1;i<n*m;i++)
			if(a[i]>a[i+1]){
				if(i==ans) ans++;
				swap(a[i],a[i+1]);
				b=0;
			}
		if(b) break;
	}
	return n*m-ans+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int l=pai();
	int an=0,am=0;
	an+=l/(2*n)*2;
	if(l%(2*n)>=1&&l%(2*n)<=n) an++;
	else if(l%(2*n)>n) an+=2;
	if(l%(2*n)==0) am=1;
	else if(l%(2*n)>=1&&l%(2*n)<=n) am=l%(2*n);
	else if(l%(2*n)>n) am=2*n-l%(2*n)+1;
	cout<<an<<' '<<am;
	return 0;
}
