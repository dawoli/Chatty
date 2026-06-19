#include<bits/stdc++.h>
using namespace std;
long long t,n,c,a[200005],d[1000005];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int j=0;j<1000005;j++) d[j]=0;
		c=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i];
			d[a[i]]++;
		}
		for(int j=0;j<1000005;j++){
			if(d[j]>0) c+=j*(d[j]-1);
		}
		cout<<c<<endl;
	}
	return 0;
}
