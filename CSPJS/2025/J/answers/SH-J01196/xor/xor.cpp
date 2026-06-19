#include<bits/stdc++.h> 
using namespace std;
int n,k,a[500009],x,x2,cnt,cnt2,l=1,r,r2;
bool b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	r=n;r2=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=2)b=1; 
	}
	if(b==0&&k==0){
		for(int i=0;i<n;i++){
			if(a[i]==0)cnt2++;
			if(i>=1&&a[i]==a[i-1]&&a[i]==1)cnt2++;
		}
		cout<<cnt2;
		return 0;
	}
	for(int i=1;i<=n;i++){
		x^=a[i];
		if(x==k){
			r=i;
			x=0;
			for(int j=l+1;j<=r;j++){
				for(int h=j;h<=r;h++){
					x^=a[h];
					if(x==k&&h<r){
						r=h;
						x=0;
					}
				}
			}
			cnt++;
			l=r+1;
			i=l;
			x=0;
		} 
	}
	cout<<cnt;
	return 0;
} 
