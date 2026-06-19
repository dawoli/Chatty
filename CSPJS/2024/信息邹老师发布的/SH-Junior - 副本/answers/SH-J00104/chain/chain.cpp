#include<iostream>
#include<cstring>
using namespace std;
int T;
int l[100005],s[200005],pre[200005];
int n,k,q;
bool check(int c){
	for(int i=1;i<=pre[n];i++){
		if(s[i]==c){
			return 1;
		}
	}
	return 0;
}
bool dfs(int r,int c,int lst){
	if(r==1){
		for(int i=1;i<=n;i++){
			if(i==lst){
				continue;
			}
			for(int j=pre[i-1]+2;j<=pre[i];j++){
				if(s[j]==c){
					for(int len=2;len<=min(k,(j-pre[i-1]));len++){
						if(s[j-len+1]==1){
							return 1;
						}
					}
				}
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i==lst){
			continue;
		}
		for(int j=pre[i-1]+2;j<=pre[i];j++){
			if(s[j]==c){
				for(int len=2;len<=min(k,(j-pre[i-1]));len++){
					if(dfs(r-1,s[j-len+1],i)){
						return 1;
					}
				}
			}
		}
	}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>T;
	while(T--){
		memset(l,0,sizeof(l));
		memset(s,0,sizeof(s));
		memset(pre,0,sizeof(pre));
		cin>>n>>k>>q;
		for(int i=1;i<=n;i++){
			cin>>l[i];
			pre[i]=pre[i-1]+l[i];
			for(int j=pre[i-1]+1;j<=pre[i];j++){
				cin>>s[j];
			}
		}
		while(q--){
			int r,c;
			cin>>r>>c;
			if(check(c)){
				cout<<dfs(r,c,-1)<<endl;
			}else{
				cout<<0<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
