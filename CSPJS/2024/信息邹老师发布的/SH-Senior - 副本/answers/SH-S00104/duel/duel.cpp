#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int r[N]={};
int cnt1=0;
int cnt2=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[i]>r[j]){
				cnt1=r[i];
				r[i]=r[j];
				r[j]=cnt1;
			}
			if(r[i]==r[j]){
				cnt2=1;
			}
		}
	}
	if(cnt2==0){
		cout<<1;
		return 0;
	}
	cnt2=n;
	cnt1=0;
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			if(r[i]==r[j]||j==cnt1)continue;
			else {
				cnt1=j;
				cnt2--;
				if(j==n){
					cout<<cnt2;
					return 0;
				}
				break;
			}
		}
	}
	cout<<cnt2;
	return 0;
}
