#include<bits/stdc++.h>
using namespace std;
int c[501][501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long tot=0;
	cin>>n>>m;
	for(int a=1;a<=n;a++){
		for(int b=1;b<=a;b++){
			if(a==b){
				c[a][b]=1;
			}else if(b==1){
				c[a][b]=a;
			}else{
				c[a][b]=c[a-1][b-1]+c[a-1][b]; 
				c[a][b]%=998244353;
			}
		}
	}
	for(int i=m;i<=n;i++){
		tot+=c[n][i];
	}
	cout<<tot;
	return 0;
}
