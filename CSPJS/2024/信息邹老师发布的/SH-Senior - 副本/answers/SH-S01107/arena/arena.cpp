#include<bits/stdc++.h>
using namespace std;
int t,n,m,K=0;
int cnt[10]={1,2,4,8,16,32,64,128,256,512};
int a[505],c[505],num[505];
char ch[10][300];
bool st[505];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	while(n>cnt[K]) K++;
	for(int i=0;i<=K;i++) cin>>ch[i+1];
	cin>>t;
	while(t--){
		long long ans=0;
		memset(st,true,sizeof(st));
		int x[4];
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=n;i++) num[i]=a[i]^x[i%4];
		for(int k=1;k<=m;k++){
			int x=0;
			while(c[k]>cnt[x]) x++;
			for(int i=1;i<=x+1;i++){
				for(int j=1;j<=c[k];j+=pow(2,i)){
					int lf=0,r=0;
					for(int l=j;l<j+pow(2,i);l++){
						if(st[l]&&lf&&!r) r=l;
						if(st[l]&&!lf) lf=l;
						if(lf&&r) break;
					}
					if(r>c[k]) st[r]=false;
					else
						if(ch[i][j/(int)pow(2,i)+1]){
							if(num[r]>=i) st[lf]=false;
						}
						else{
							if(num[lf]>=i) st[r]=false;
						}
				}
			}
			for(int i=1;i<=n;i++)
				if(st[i]){
					ans=ans^(k*i);
					break;
				}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
4 3
0 0 0 0
1 2 4
0 0
0
1
2 1 0 0
*/
