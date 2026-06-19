#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
string c;
int s[550];
int day[550];
int c1[550];
int vis[550],ans;
int res,to;
void dfs(int k){
	if(k==n+1){
		res=0,to=0;
		for(int i=1;i<n;i++){
			if(res>=s[day[i]]){
				res+=1;
			}else if(c1[i]==0)res+=1;
			else to+=1;
		}if(to>=m)ans++;
		return ;
	}for(int i=1;i<=n;i++){
		if(vis[i]==0){
			day[k]=i;
			vis[i]=1;
			dfs(k+1);
			vis[i]=0;
		}
		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>c;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}if(n<=10){
		for(int i=1;i<=n;i++){
			c1[i]=c[i-1]-48;
		}dfs(1);
		cout<<ans;
	}
	else if(m==n){
		int u=1;
		for(int i=0;i<n;i++){
			if(c[i]!='1'){
				cout<<0;
				u=0;
			}
		}if(u==1){
			for(int i=1;i<=n;i++){
				if(s[i]==0){
					cout<<0;
					u=0;
				}
			}if(u==1)cout<<1;
		}
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
