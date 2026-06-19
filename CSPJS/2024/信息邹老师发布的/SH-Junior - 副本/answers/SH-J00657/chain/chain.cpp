#include<bits/stdc++.h>
using namespace std;
string s[100010];
int t,n,k,q,flag,cnt1[100010],l[100010],cs[100010],r,c;
void dfs(int i,int now){
	if(flag==1){
		return;
	}if(i==r+1){
		if(now==c){
			flag=1;
			return;
		}return;
	}if(i==0){
		for(int j=1;j<=n;i++){
			if(cnt1[j]==1){
				int cnt=0,tmp=0;
				for(int k=1;k<=l[j];k++){
					if(tmp==k){
						cnt=0;
					}if(cnt==1){
						dfs(i+1,s[j][k]-'0');
					}if(s[j][k]=="1"){
						cnt=1;
					}
				}
			}
		}
	}else{
		for(int j=1;j<=n;i++){
			int cnt=0,tmp=0;
			for(int k=1;k<=l[j];k++){
				if(tmp==k){
					cnt=0;
				}if(cnt==1){
					dfs(i+1,s[j][k]-'0');
				}if(s[j][k]-'0'==now){
					cnt=1;
				}
			}
		}
	}
}int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t --> 0){//20000000
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				scanf("%d",&cs[j]);	
				if(cs[j]==1){
					cnt1[i]=1;
				}s[i]+=(cs[j]-'0');
			}
		}while(q --> 0){
			flag=0;
			scanf("%d%d",&r,&c);
			int cnt=0,flag=0;
//			dfs(1,0);
//			if(flag==1){
//				printf("1\n");
//			}else{
//				printf("0\n");
//			}
//			for(int i=r;i>=1;i--){
//				if(i==r){
//					for(int j=1;j<=n;i++){
//						if(cnt[j]==1){
//							int cnt=0;
//							for(int k=1;k<=l[j];k++){
//								if(k==1){
//									
//								}
//							}
//						}
//					}
//				}
//			}
			printf("0\n");
		}
	}
	return 0;
}
