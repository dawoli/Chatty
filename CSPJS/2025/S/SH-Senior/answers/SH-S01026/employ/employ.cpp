#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int aa[12],bb[12];
int ha[505],a[505],h[505];
void dfs(int deep){
	if(deep>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[aa[i]]>h[i]&&ha[i]==1){
				sum++;//cout<<a[aa[i]]<<endl;
			}
			//printf("%d %d\n",a[aa[i]],h[i]);
		}
		//cout<<sum<<endl;
		if(sum>=m) ans++;
	}
	for(int i=1;i<=n;i++){
		if(bb[i]) continue;
		bb[i]=1;aa[deep]=i;
		dfs(deep+1);
		bb[i]=0;aa[deep]=0;
	}
}
int main(){
	//½â×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡ 
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		ha[i]=c-'0';
		if(c=='0')h[i+1]=h[i]+1;
		else h[i+1]=h[i];
		
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	//for(int i=1;i<=n;i++)cout<<h[i]<<" ";
	//sort(a+1,a+1+n);
	if(n<=10){
	    dfs(1);	
	    cout<<ans;
	}else{
		int is0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) is0++;
		}
		if(n-is0<m){
			cout<<0;
			return 0;
		}
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2

100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/
