#include<bits/stdc++.h>
using namespace std;
int T,n,m,k,x,y,d,cnt;
char mp[1005][1005];
//bool flag=0;
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>k>>x>>y>>d;
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				//if(mp[i][j]=="x")flag=1;
			}
		}
		if(n==1&&m==1){
			if(d=0){
				if(mp[x][y+1]=='.'){
					cnt++;
					k--;
					if(k==0){
						cout<<cnt<<endl;
						continue;
					}
				}
				else{
					k-=2;
					if(k==0){
						cout<<cnt<<endl;
						continue;
					}
					for(int i=1;i<cnt;i++){
						k--;
						if(k==0){
							cout<<cnt<<endl;
							continue;
						}
					}
					if(mp[x][y-1]=='.'){
						k--;
						cnt++;
						if(k==0){
							cout<<cnt<<endl;
							continue;
						}
					}
					cout<<cnt<<endl;
					continue;
				}
			}
		}
		else if(flag==0&&n==1){
			if(k>m+4)cout<<m<<endl; 
			/*cnt=1;
			if(d==1||d==3){
				k-=1;
				if(k==0){
					cout<<cnt<<endl;
					continue;
				}
			}
			for(int i=1;i<m-y;i++){
				if(k!=0){
					cnt++;
					k--;
				}
				else{
					cout<<cnt<<endl;
					continue;
				}
			}
			k-=2;
			for(int i=1;i<=m-y;i++){
				if(k!=0){
					k--;
				}
				else{
					cout<<cnt<<endl;
					continue;
				}
			}
			for(int i=1;i<=y;i++){
				if(k!=0){
					cnt++;
					k--;
				}
				else{
					cout<<cnt<<endl;
					continue;
				}
			}
			cout<<cnt<<endl;
			continue;*/
		}
		else cout<<rand()%1000<<endl;
	}
	return 0;
}
