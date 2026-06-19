#include <bits/stdc++.h>
using namespace std;
int a[500005];
bool b[500005];
int s(int a,int b){
	bool u[3][20];
	int l1=0,l2=0,sum=0;
	while(a){
		u[0][l1]=a%2;
		a/=2;
		l1++;
	}
	while(b){
		u[1][l2]=b%2;
		b/=2;
		l2++;
	}
	for (int i=0;i<max(l1,l2);i++){
		u[2][i]=!(u[0][i]||u[1][i])&&u[0][i]&&u[1][i];
	}
	for (int i=max(l1,l2);i>=0;i--){
		sum=sum*2+u[2][i];
	}
	return sum;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,t=0;
	bool fg=0,fg1=0;
	cin >>n>>k;
	for (int i=0;i<n;i++){
		cin >>a[i];
		if (a[i]==0) fg=1;
	}
	if (k==1 || k==0){
		if (fg){
			cout <<ans/2;
		}
		else {
			if(k==1){
				for (int i=0;i<n;i++){
					if (fg1){
						fg1=0;
						continue;
					}
					if (a[i]==1) ans++;
					else{
						if (!a[i+1]){
							ans++;
							fg1=1;
						}
					}
				}
			}
			else{
				for (int i=0;i<n;i++){
					if (fg1){
						fg1=0;
						continue;
					}
					if (a[i]==0) ans++;
					else{
						if (a[i+1]){
							ans++;
							fg1=1;
						}
					}
				}
			}
		}
	}
	else{
		for(int i=0;i<n;i++){
			if (a[i]==k){
				ans++;
				b[i]=1;
			}
		}
		for (int i=2;i<=n;i++){
			for (int j=0;j<n-i;j++){
				fg1=0;
				for (int l=0;l<i;l++){
					if (b[j+l]){
						fg1=1;
						break;
					}
				}
				if (fg1) continue;
				t=0;
				for (int l=0;l<i;l++){
					t=s(t,a[j+l]);
				}
				if (t==k){
					ans++;
					for (int l=0;l<i;l++){
						b[j+l]=1;
					} 
				}
			}
		}
	}
	cout <<ans;
	return 0;
}
