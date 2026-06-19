#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010][5],cnt[5];
struct info{
	int v,id;
}d[100010];
int mi(int a,int b,int c){
	return a+b+c-max(a,max(b,c))-min(a,min(b,c));
}
bool cmp(info x,info y){
	return x.v>y.v; 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cnt[1]=cnt[2]=cnt[3]=0;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3])))a[i][4]=1;
			else if(a[i][3]==max(a[i][1],max(a[i][2],a[i][3])))a[i][4]=3;
			else a[i][4]=2;//the max 
		}
		for(int i=1;i<=n;i++)cnt[a[i][4]]++;
		int ans=0;
		for(int k=1;k<=3;k++){
			if(cnt[k]<=n/2){
				for(int i=1;i<=n;i++){
					if(a[i][4]==k){
				//		cout<<a[i][k]<<'\n';
						ans+=a[i][k]; 
					}
				}
			}
			else{
				int len=0;
				for(int i=1;i<=n;i++){
					if(a[i][4]==k){
						d[++len].v=a[i][k]-mi(a[i][1],a[i][2],a[i][3]);
						d[len].id=i;
					}
				}
				sort(d+1,d+1+len,cmp);
				for(int i=1;i<=n/2;i++){
				//	cout<<a[d[i].id][k]<<'\n';
					ans+=a[d[i].id][k];
				}
				for(int i=n/2+1;i<=len;i++){
				//	cout<<mi(a[d[i].id][1],a[d[i].id][2],a[d[i].id][3])<<'\n';
					ans+=mi(a[d[i].id][1],a[d[i].id][2],a[d[i].id][3]);
				}
					
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
