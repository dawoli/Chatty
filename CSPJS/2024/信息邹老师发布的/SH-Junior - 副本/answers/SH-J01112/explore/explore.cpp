#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin>>T;
	int ans[T];
	int n,m,k;
	int a=0;
	for(int i=0;i<T;i++){
		cin>>n>>m>>k;
		int x[n],y[m],d[max(n,m)];
		cin>>x[i]>>y[i]>>d[i];
		int s[n][m];
		for(int j=0;j<n;j++){
			for(int l=0;l<m;l++){
				cin>>s[j][l];
			}
		}
		for(int j=0;j<k;j++){
			if(d[i]==0){
				if(s[x[i]][y[i]+1]=='.'){
					y[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]+1][y[i]]=='.'){
					x[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]-1]=='.'){
					y[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]-1][y[i]]=='.'){
					x[i]--;
					a=s[x[i]][y[i]];
				}
			}
			else if(d[i]==1){
				if(s[x[i]+1][y[i]]=='.'){
					x[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]-1]=='.'){
					y[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]-1][y[i]]=='.'){
					x[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]+1]=='.'){
					y[i]++;
					a=s[x[i]][y[i]];
				}
			}
			else if(d[i]==2){
				if(s[x[i]][y[i]-1]=='.'){
					y[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]-1][y[i]]=='.'){
					x[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]+1]=='.'){
					y[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]+1][y[i]]=='.'){
					x[i]++;
					a=s[x[i]][y[i]];
				}
			}
			else if(d[i]==3){
				if(s[x[i]-1][y[i]]=='.'){
					x[i]--;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]+1]=='.'){
					y[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]+1][y[i]]=='.'){
					x[i]++;
					a=s[x[i]][y[i]];
				}
				else if(s[x[i]][y[i]-1]=='.'){
					y[i]--;
					a=s[x[i]][y[i]];
				}
			}
			ans[i]++;
		}
	}
	for(int i=0;i<T;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
