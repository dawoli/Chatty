#include<bits/stdc++.h>
using namespace std;
int n,r[100005],f[100005],x=2,cnt;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	for(int i=1;i<=n;i++){
//		cout<<r[i];
		while(r[i]>=r[x]&&x<=n){
			x++;
		}
		if(r[i]<r[x]){
			f[i]=1;
//			cout<<r[i]<<" "<<r[x]<<endl;
			x++;
		}
	}
	for(int i=1;i<=n;i++){
		if(f[i])cnt++;
	} 
	cout<<n-cnt<<endl;
	return 0;
}

