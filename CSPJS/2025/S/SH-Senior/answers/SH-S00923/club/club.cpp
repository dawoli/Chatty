#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	int t, i, j, a[10001], b[10001], c[10001], k, max;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>i;
		for(j=1;j<=i;j++){
			cin>>a[j]>>b[j]>>c[j];
			if(a[j]>=b[j]>=c[j]) k=a[j];
			if(a[j]>=c[j]>=b[j]) k=a[j];
			if(b[j]>=a[j]>=c[j]) k=b[j];
			if(b[j]>=c[j]>=a[j]) k=b[j];
			if(c[j]>=b[j]>=a[j]) k=c[j];
			if(c[j]>=a[j]>=b[j]) k=c[j];
			max+=k;
		}
		cout<<max<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
