#include<bits/stdc++.h>
using namespace std;
struct {
	int d,v,a;//位置，v0，a 
}nums[100005];
int pos[100005];
//int vis[100005]={0};
int marks[100005]={0};
int ans1=0;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;
	int n,m,l,v;//车数，测数，lenth，限速
	cin>>T;
	for(int i=1;i<=T;i++){
		//
		ans1=0;
		cin>>n>>m>>l>>v;
		//memset(vis,0,n+1);
		memset(marks,0,m+1);
		int js=m;
		for(int j=1;j<=n;j++){
			cin>>nums[j].d>>nums[j].v>>nums[j].a;
		}
		for(int j=1;j<=m;j++){
			cin>>pos[j];
			marks[j]=1;
		}
		for(int k=1;k<=n;k++){
			for(int p=1;p<=m;p++){
				double sped;
				int tem=2*nums[k].a*(pos[p]-nums[k].d)+(nums[k].v*nums[k].v);
				if(tem<=0){
					break;
				}
				else{
					sped=sqrt(tem);
				}
				if(sped>v){
					ans1++;// vis[k]=1;
					break;
				}
				if(sped>pos[p]&&marks[p]==1){
					marks[p]=0;
					js--;
				}
			}
		}
		cout<<ans1-1<<" "<<js-1<<endl;
		//
	}
	return 0;
}

