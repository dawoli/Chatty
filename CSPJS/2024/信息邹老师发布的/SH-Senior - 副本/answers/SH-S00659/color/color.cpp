#include<bits/stdc++.h>
using namespace std;
int red[200005]={0},blue[200005]={0};
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdin);
	int t;
	cin>>t;
	int ans[t]={0};
	for(int w=0;w<t;w++){
		int n,x=1,y=1;
		
		int A[200005][2]={0};
		bool visited[200005];
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>A[i][0];
		}
		int q,p;
		q=A[1][0];
		A[1][1]=1;
		p=1;
		visited[1]=true;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(A[j][0]==q && !visited[j]){
					 A[j][1]=p;
					 visited[j]=true;
				}
			}
			if(p==1){
				p=0;
			}
			if(p==0){
				p=1;
			}
			for(int o=1;o<=n;o++){
				if(!visited[0]){
					q=A[o][0];
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(A[i][1]==1){
				red[x]=A[i][0];
				x++;
			}
			else{
				blue[y]=A[i][0];
				y++;
				
			}
		}
		for(int i=1;i<x;i++){

			if(red[i]=red[i-1]){
				ans[w]+=red[i];

			}
		}

		for(int i=1;i<y;i++){

			if(blue[i]=blue[i-1]){
				ans[w]+=blue[i];
			}
		}
		red[200005]={0};
		blue[200005]={0};
	}
	for(int i=0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
