#include<bits/stdc++.h>
using namespace std;
int n,m,k,city; 
int mp[10025][10025],c[15],a[15][10005];

int ans=999999,tans=0;
//void init(){
//	for(int i=1;i<=city;i++){
//		for(int j=1;j<=city;j++){
//			nmp[i][j]=mp[i][j];
//		}
//	}
//}
void print(){
	for(int i=1;i<=city;i++){
		for(int j=1;j<=city;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
} 
void build(){
	int ma=mp[1][1],mi=999999,aim;
	for(int i=2;i<=city;i++){
		ma=max(ma,mp[1][i]);
		if(mp[1][i]<mi && mp[1][i]!=0){
			mi=mp[1][i];
			aim=i;
		}
	}
	while(ma!=0){
		tans+=mp[1][aim];
		mp[1][aim]=0;
		mp[aim][1]=0;
		cout<<aim<<endl;
		print();
		if(aim>m){
			for(int i=1;i<=city;i++){
				mp[aim][i]-=c[aim-m];
				mp[i][aim]-=c[aim-m];
			}
			mp[aim][aim]=0;
		}
		for(int i=1;i<=city;i++){
			mp[1][i]=min(mp[1][i],mp[aim][i]);
			mp[i][1]=mp[1][i];
		}
		mi=999999;
		ma=mp[1][1];
		for(int i=1;i<=city;i++){
			ma=max(ma,mp[1][i]);
			if(mp[1][i]<mi && mp[1][i]!=0){
				mi=mp[1][i];
				aim=i;
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//memset(mp,0x1111,sizeof(mp));
	for(int i=1;i<=10020;i++){
		for(int j=i;j<=10020;j++){
			mp[i][j]=999999;
		}
	}
	scanf("%d%d%d",&n,&m,&k);
	city=m;
	for(int i=0;i<m;i++){
		int ta,tb;
		scanf("%d%d",&ta,&tb);
		scanf("%d",&mp[ta][tb]);
		mp[tb][ta]=mp[ta][tb];
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		mp[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=m+1;j<=m+k;j++){
			mp[i][j]=c[j-m]+a[j-m][i];
			mp[j][i]=mp[i][j];
		}
	}
	city=m+k;
	build();
	printf("%d\n",tans);
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
