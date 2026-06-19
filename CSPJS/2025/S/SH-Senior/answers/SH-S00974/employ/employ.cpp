#include<bits/stdc++.h>
using namespace std;
long long jiecheng(int n){
	long long ans=1;
	for(int i=n;i>=1;i++){
		ans*=i;
		ans%= 998244353;
	}
	return ans;
}
bool b[501][501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int c[501]={0};
	string s;
	cin>>s;
	int cc=0;
	int fancc=0;
	int ans=1;
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])num++;
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0')cc++;
	}
	int f[501][501][501];
	for(int i=0;i<n;i++){
		int count=0;
		if(s[i]=='0')count++;
		for(int j=1;j<=n;j++){
			if(c[i]<=s[i])b[i][j]=1;
			if(count>=c[i])b[i][j]=1;
		}
	}
	int bulu[501]={0};
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
		if(b[i][j])bulu[i]++;
		
		}
	}
	
	/*for(int i=0;i<n;i++){
		if(s[i]=='0'){
			for(int j=1;j<=n;j++){
				;
			}
		}
		for(int j=1;j<=n;j++){
			int z=0;
			for(int l=0;l<=n;l++){
				if(f[i][j])
			}
			if(s)
			for(int l=0;l<=n;l++){
				if(f[i][j])
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++)
		if(n-j>=m)
		maxx=max(maxx,f[n-1][i][j]);
	}*/
	if(m>num){
		cout<<0;
	}
	else if(cc==0){
		
		
	}
	else if(m==1){
		
	}else if(m==n){
		if(cc>0||num!=n)cout<<0;
		else cout<<jiecheng(n);
	}
	return 0;
} 
