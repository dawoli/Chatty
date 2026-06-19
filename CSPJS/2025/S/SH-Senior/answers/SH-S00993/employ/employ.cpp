#include<bits/stdc++.h>
using namespace std;
int n,m,peo[1005],ans=0;
bool r[1005];
void jud(int arr[]){
//	for(int i=1;i<=n;i++){
//		cout<<arr[i];
//	}
//	cout<<'\n';
	int fl=0;
	for(int i=1;i<=n;i++){
		if(peo[arr[i]]<=fl||r[i]==0){
			fl++;
		}
	}
	if(n-fl>=m){
		ans++;
	}
}
void per(int arr[],bool flg[],int k){
	if(k==n){
		jud(arr);
		return;
	}
	for(int i=1;i<=n;i++){
		if(flg[i]==0){
			flg[i]=1;
			arr[k+1]=i;
			per(arr,flg,k+1);
			flg[i]=0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		r[i+1]=s[i]-'0';
	}
	bool spea=1;
	for(int i=1;i<=n;i++){
		cin>>peo[i];
	}
	int qq[15]={};
	bool rr[15]={};
	if(n>=12){
		cout<<0;
	}
	per(qq,rr,0);
	cout<<ans;
	return 0;
}

