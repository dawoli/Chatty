#include<bits/stdc++.h>
using namespace std;
int a[200009],n,t,ans,f[200009],partner[200009],num[1000009],leng[200009],ance[200009];
void solveBF(){
	for(int i=0;i<(1<<n);i++){
			int r=0,b=0,c=0;
			for(int j=1;j<=n;j++){
				int clr=((i>>(j-1))&1);
				if (clr==0){
					if (a[r]==a[j]) c+=a[j];
					r=j;
				} 
				else{
					if (a[b]==a[j]) c+=a[j];
					b=j;
				}
			}
			ans=max(ans,c);
//			cout<<i<<' '<<c<<endl;
		}
		cout<<ans<<endl;
}
void solve(){
	for(int i=0;i<=200000;i++) f[i]=0;
	for(int i=0;i<=200000;i++) partner[i]=0;
	for(int i=0;i<=1000000;i++) num[i]=0;
	for(int i=0;i<=200000;i++) leng[i]=0;
	for(int i=1;i<=n;i++){
		partner[i]=num[a[i]];
		num[a[i]]=i;
		leng[i]=leng[partner[i]]+1;
		if (partner[i]==0) ance[i]=i;
		else ance[i]=ance[partner[i]];
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		f[i]=max(f[i],f[ance[i]-1]+(leng[i]-1)*a[i]);
	}
	cout<<f[n]<<endl;
	return ;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		if (n<=15) solveBF();
		else solve();
	}
	return 0;
}
