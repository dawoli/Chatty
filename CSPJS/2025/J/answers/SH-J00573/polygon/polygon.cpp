#include <bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int n;
void p(){
	b[0]++;
	for (int i=0;i<n;i++){
		if(b[i]==2){
			b[i]=0;
			b[i+1]++;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m=998244353,mx=-1;
	long long ans=0,sum=0,l=0;
	cin >>n;
	for (int i=0;i<n;i++){
		cin >>a[i];
	}
	for (int i=0;i<pow(2,n);i++){
		sum=0;
		mx=-1;
		l=0;
		for (int j=0;j<n;j++){
			if (b[j]){
				sum+=a[j];
				mx=max(a[j],mx);
				l++;
			}
		}
		p();
		if (sum>2*mx && l>=3) ans++;
	}
	cout <<ans;
	return 0;
}
