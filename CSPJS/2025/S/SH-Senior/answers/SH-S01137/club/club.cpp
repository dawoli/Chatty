#include<bits/stdc++.h>
using namespace std;
int a[114514][11],b[114514];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
int t;
cin>>t;
for(int abc=1;abc<=t;abc++){
	int n,c[10]={0,0,0,0,0,0};
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		a[i][4]=1;
		if(a[i][2]>a[i][1])a[i][4]=2;
		if(a[i][3]>a[i][a[i][4]])a[i][4]=3;
		c[4]+=a[i][a[i][4]];
		c[a[i][4]]++;
	}
	if(c[1]>n/2){
		int cur=0,d=c[1]-n/2;
		for(int i=1;i<=n;i++){
			if(a[i][4]==1){
				b[++cur]=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			} 
		}
		assert(cur==c[1]);
		sort(b+1,b+cur+1);
		for(int i=1;i<=c[1]-n/2;i++)c[4]-=b[i];
		cout<<c[4]<<endl;
		continue;
	}
	else if(c[2]>n/2){
		int cur=0,d=c[2]-n/2;
		for(int i=1;i<=n;i++){
			if(a[i][4]==2){
				b[++cur]=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			} 
		}
		assert(cur==c[2]);
		sort(b+1,b+cur+1);
		for(int i=1;i<=c[2]-n/2;i++)c[4]-=b[i];
		cout<<c[4]<<endl;
		continue;
	}
	else if(c[3]>n/2){
		int cur=0,d=c[3]-n/2;
		for(int i=1;i<=n;i++){
			if(a[i][4]==3){
				b[++cur]=min(a[i][3]-a[i][1],a[i][3]-a[i][2]);
			} 
		}
		assert(cur==c[3]);
		sort(b+1,b+cur+1);
		for(int i=1;i<=c[3]-n/2;i++)c[4]-=b[i];
		cout<<c[4]<<endl;
		continue;
	}
	cout<<c[4]<<endl;
}
	return 0;
} 
