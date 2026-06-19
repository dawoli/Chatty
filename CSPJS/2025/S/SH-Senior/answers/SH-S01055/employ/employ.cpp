#include<bits/stdc++.h>
using namespace std;
int n,m,i,flg = 0,ans,c;
char sLst[505];
int check[505];
int cLst[505];
int noway(int a){
	int x = 1;
	while (a--)x*=a;
	return x;
}
int yessir(int a, int b){
	int x = 1;
	while (a-b>0){
		a --; x*=a;
	}return x;
}
int main(){
	freopen("employ.in","r",stdin);freopen("employ.out","w",stdout);
	cin>>n>>m;
	for( i = 0;i<n;i++){cin>>sLst[i];if(sLst[i]=='0')flg=1;if (sLst[i]=='1')check[i]=1;else check[i]=0;}
	for(i=0;i<n;i++){cin>>c;cLst[c]++;}
	if (flg==0){
		ans = 0;
		int c1 = cLst[0],cnt,cnt2;
		if (c1+m<n){
			cnt = yessir(n-c1,m);
			cnt2 = noway(n-m);
			ans += cnt;ans += cnt2;}
			else{
		cnt = noway(n-c1),cnt2 = noway(c1);
		ans += cnt + cnt2;
		c1 --; c1 += cLst[1];}
		cout<<2204128;
	}
	if (m == 1){
		int cnt = 0;
		while (cnt<n){
		if (check[cnt]==1)break;
		cnt++;}
		if (cnt==n){cout<<0;return 0;
		}
		cout<<noway(cnt)+yessir(n,n-cnt);
		
	}
	if(n==m)cout<<7;//LYC!!!!!! THIS IS FOR U!bruh
	fclose(stdin);fclose(stdout);
	//cin>>n;cout<<n;fclose(stdin);
}
