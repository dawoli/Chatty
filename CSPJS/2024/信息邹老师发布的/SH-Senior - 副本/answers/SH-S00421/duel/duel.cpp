#include<bits/stdc++.h>
using namespace std;
int n,a[100000],b[100000];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	if(b[1]+b[2]==n){
		if(b[1]>=b[2]) cout<<n-b[2];
		else cout<<n-b[1];
		return 0;
	}
	if(b[a[1]]==n){
		cout<<n;
		return 0;
	}
	sort(a+1,a+n+1);
	int l=1,n_=n;
	for(int r=1;r<=n;r++){
		if(a[r]-a[l]>0){
			l++;
			n_--;
		}
	}
	cout<<n_;
	return 0;
}
