#include <bits/stdc++.h>
using namespace std;
char a[1001][1001];
bool b[1001][1001];
int ans[5];
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t,n,m,k,xxx1,yyy1,ddd1;
	cin>>t;
	memset(a,0,sizeof(a));
	for(int i=1;i<=t;i++){
		cin>>n>>m>>k>>xxx1>>yyy1>>ddd1;
		for(int xx=1;xx<=n;xx++){
			for(int yy=1;yy<=m;yy++){
				cin>>a[xx][yy];
				b[xx][yy]=0;
			}
		}
		if(k==1){
			if(a[xxx1][yyy1]=='.'){
				ans[i]++;
			}
			if(ddd1==0){
				if(a[xxx1][yyy1+1]=='.'){
					ans[i]++;
				}
			}
			if(ddd1==1){
				if(a[xxx1+1][yyy1]=='.'){
					ans[i]++;
				}
			}
			if(ddd1==2){
				if(a[xxx1][yyy1-1]=='.'){
					ans[i]++;
				}
			}
			if(ddd1==3){
				if(a[xxx1-1][yyy1]=='.'){
					ans[i]++;
				}
			}
		}
		else{
			if(a[xxx1][yyy1]=='.'){
				ans[i]++;
				b[xxx1][yyy1]=1;
			}
			for(int j=1;j<=k;j++){
				if(ddd1==0){
					if(a[xxx1][yyy1+1]=='x'||xxx1>n||xxx1<1||(yyy1+1)<1||(yyy1+1)>m){
						ddd1+=1;
						ddd1=ddd1%4;
						continue;
					}
					if(a[xxx1][yyy1+1]=='.'){
						if(b[xxx1][yyy1+1]==1){
							yyy1++;
							continue;
						}
						
						ans[i]++;
						yyy1++;
						b[xxx1][yyy1]=1;
						continue;
					}
					
					
				}
				if(ddd1==1){
					if(a[xxx1+1][yyy1]=='x'||(xxx1+1)>n||(xxx1+1)<1||yyy1<1||yyy1>m){
						ddd1+=1;
						ddd1=ddd1%4;
						continue;
					}
					if(a[xxx1+1][yyy1]=='.'){
						if(b[xxx1+1][yyy1]==1){
							xxx1++;
							continue;
						}
						ans[i]++;
						xxx1++;
						b[xxx1][yyy1]=1;
						continue;
					}
					
				}
				if(ddd1==2){
					if(a[xxx1][yyy1-1]=='x'||xxx1>n||xxx1<1||(yyy1-1)<1||(yyy1-1)>m){
						ddd1+=1;
						ddd1=ddd1%4;
						continue;
					}
					if(a[xxx1][yyy1-1]=='.'){
						if(b[xxx1][yyy1-1]==1){
							yyy1--;
							continue;
						}
						ans[i]++;
						yyy1--;
						b[xxx1][yyy1]=1;
						continue;
					}
					
				}	
				
				if(ddd1==3){
					if(a[xxx1-1][yyy1]=='x'||(xxx1-1)>n||(xxx1-1)<1||yyy1<1||yyy1>m){
						ddd1+=1;
						ddd1=ddd1%4;
						continue;
					}
					if(a[xxx1-1][yyy1]=='.'){
						if(b[xxx1-1][yyy1]==1){
							xxx1--;
							continue;
						}
						ans[i]++;
						xxx1--;
						b[xxx1][yyy1]=1;
						continue;
					}
					
				}
			}
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	} 
	return 0;
}
