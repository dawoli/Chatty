#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200009;
int T,n;
int a[N][3];
int id1[N],id2[N],id3[N],rk1[N],rk2[N],rk3[N],vis[N],ans; 

bool cmp1(int &x,int &y){return a[x][0]>a[y][0];}
bool cmp2(int &x,int &y){return a[x][1]>a[y][1];}
bool cmp3(int &x,int &y){return a[x][2]>a[y][2];}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		int k1=0,k2=0,k3=0;							 
		for(int i=1;i<=n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			id1[i]=id2[i]=id3[i]=i;
		}
		sort(id1+1,id1+n+1,cmp1);
		sort(id2+1,id2+n+1,cmp2);
		sort(id3+1,id3+n+1,cmp3);
		for(int i=1;i<=n;i++){
			if(a[i][0]>a[i][1]&&a[i][0]>a[i][2]&&rk1[i]<=n/2+k1){
				ans+=a[i][0],vis[i]=1;
				if(rk2[i]<=n/2+k2)k2++;
				if(rk3[i]<=n/2+k3)k3++; 
			}
			if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]&&rk2[i]<=n/2+k2){
				ans+=a[i][1],vis[i]=1;
				if(rk1[i]<=n/2+k1)k1++;
				if(rk3[i]<=n/2+k3)k3++; 
				
			}
			if(a[i][2]>a[i][1]&&a[i][2]>a[i][0]&&rk3[i]<=n/2+k3){
				ans+=a[i][2],vis[i]=1;
				if(rk1[i]<=n/2+k1)k1++;
				if(rk2[i]<=n/2+k2)k2++;
				
			}
		}
		cout<<ans<<endl;						 				 
	}
	
	return 0;
}

