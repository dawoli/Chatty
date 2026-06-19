#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N],s[N],L[N],R[N];
int main(){
	freeopen("xor.in","r",stdin);
	freeopen("xor.out","w",stdout);
	cin>>n>>k;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);
		s[i]=s[i-1]^a[i];
	}
	if(m==1){
		int p=0;
		for(int i=1;i<=n;i++){
			if(a[i]){
				p++;
			}
		}
		cout<<p<<endl;
		return 0;
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((s[j]^s[i-1])==k){
				//cout<<s[i-1]<<" "<<s[j]<<" "<<(s[j]^s[i-1])<<" "<<k<<endl;
				L[cnt]=i;
				R[cnt]=j;
				cnt++;
			}
		}
	}
//	for(int i=1;i<cnt;i++){
//		cout<<L[i]<<" "<<R[i]<<endl;
//	}
	int maxx=1,l,r;
	for(int i=1;i<cnt;i++){
		int sum=1,r=R[i];
		for(int j=i+1;j<cnt;j++){
			if(r<=L[j]){
				if(r>=R[j]){
					continue;
				}else{
					maxx=max(maxx,++sum);
					r=R[j];	
				}
				
			}
		}
	}
	cout<<maxx<<endl;
	return 0;
}
