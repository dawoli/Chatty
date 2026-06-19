#include<bits/stdc++.h>
using namespace std;
//10
//136 136 136 2417 136 136 2417 136 136 136
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	long long int n,c=0;
	cin>>n;
	long long int a[n+1];

	long long int m=0,dssz=0;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
//		b[a[i]]++;
		if(m<a[i]) m=a[i];
	}
	int b[m+2]={0};
//	memset(b,0,max+1);
	for(long long int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(long long int i=0;i<=m;i++){
		if(b[i]!=0){
			dssz++;
		}
	}
	long long int d[dssz+2]={0};
	int j=1;
	for(long long int i=0;i<=m;i++){
		if(b[i]!=0){
			d[j]=b[i];
			j++;
		}
	}
	for(long long int i=0;i<=dssz;i++){
//		c+=max(0,d[i]-d[i+1]);
		if(0<d[i]-d[i+1]){
			c+=d[i]-d[i+1]; 
		}
	}
	cout<<c;
	return 0;
}
