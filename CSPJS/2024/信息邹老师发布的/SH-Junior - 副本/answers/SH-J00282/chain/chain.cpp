#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int t,n,k_1,q,l[N],r,c;
int s[N][2009],pre[2009];
bool flag=false;
void dfs(int x,int y,int lth){
	if(flag)
		return;
	if(x==r+1){
		if(pre[lth]==c){
			flag=true;
		}
		return;
	}
	int pr[lth+1];
	for(int i=1;i<=lth;i++)
		pr[i]=pre[i];
	for(int i=1;i<=n&&!flag;i++){
		if(i==y)continue;
		for(int j=1;j<=l[i];j++){
			if(x==1&&s[i][j]!=1)continue;
			if(x!=1&&pre[lth]!=s[i][j])continue;
			for(int k=j+1;k<=min(j+k_1-1,l[i]);k++){
				if(k-j+1==lth){
					bool fg=true;
					for(int h=1;h<=lth;h++)
						if(pre[h]!=s[i][j+h-1]){
							fg=false;
							break;
						}
					if(fg)continue;
				}
				for(int h=j;h<=k;h++){
					pre[h-j+1]=s[i][h];
				}
				dfs(x+1,i,k-j+1);
				if(flag)
					break;
				for(int h=1;h<=lth;h++){
					pre[h]=pr[h];
				}
			}
		}
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>k_1>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			for(int j=1;j<=l[i];j++)
				cin>>s[i][j];
		}
		for(int i=1;i<=q;i++){
			cin>>r>>c;
			flag=false;
			for(int j=1;j<=2000;j++)
				pre[j]=0;
			dfs(1,0,0);
			if(flag)
				cout<<1<<endl;
			else
				cout<<0<<endl;
		}
	}
	return 0;
}
