#include<bits/stdc++.h>
#define int long long
int a[114514][4],t[114514],n,s,c,x[4];
using namespace std;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int q;cin>>q;
	while(q--){
		memset(t,0,sizeof(t));
		memset(a,0,sizeof(a));
		c=s=x[0]=x[1]=x[2]=x[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3])s+=a[i][1],x[1]++,a[i][0]=1;
			else if(a[i][2]>=a[i][3])s+=a[i][2],x[2]++,a[i][0]=2;
			else s+=a[i][3],x[3]++,a[i][0]=3;
			
		}
		if(x[1]>=x[2]&&x[2]>=x[3])x[0]=1;
		else if(x[2]>=x[3])x[0]=2;
		else x[0]=3;
		if(x[x[0]]<=n/2){
			cout<<s<<"\n";continue;
		}
		for(int i=1;i<=n;i++){
			if(a[i][0]!=x[0])continue;
			if(x[0]==1)t[++c]=a[i][1]-max(a[i][2],a[i][3]);
			if(x[0]==2)t[++c]=a[i][2]-max(a[i][1],a[i][3]);
			if(x[0]==3)t[++c]=a[i][3]-max(a[i][2],a[i][1]);
		}sort(t+1,t+c+1);
		for(int i=1;i<=c-n/2;i++){
			s-=t[i];
		}cout<<s<<"\n";
	}
}
