#include<bits/stdc++.h>
using namespace std;
int n,m,ap[100010],K,x[4],a[100010],d[20][100010],num[100010],ct,out;
pair<int,int>c[100010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",ap+i);
	//cout<<"HA";
	for(int i=1;i<=m;i++){
		scanf("%d",&(c[i].first));
		c[i].second=i;
	}
	sort(c+1,c+1+m);
	int k=0;
	int nn=n-1;
	while(nn){
		k++,nn>>=1;
	}
	//cerr<<"HA";
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<(k-i));j++){
			char c;scanf("%c",&c);while(c!='0'&&c!='1')scanf("%c",&c);
			d[i][j]=(c=-'0');
		}
	}
	//cerr<<"HA";
	int T;cin>>T;
	if(n<=8){
		
		return 0;
	}
	while(T--){
		ct=out=0;
		for(int i=0;i<4;i++)cin>>x[i];
		//cerr<<x[3]<<endl;
		for(int i=1;i<=n;i++)a[i]=ap[i]^x[i%4],num[i]=i;
		int ind=1;
		if(c[ind].first==1){
			int f=ind;
			while(c[ind].first==c[f].first)out^=(c[ind].second*num[1]),ind++;
		}
		for(int j=0;j<k;j++){
			for(int i=1,g=1;i<=(1<<k);i+=(1<<(j+1)),g++){
				int host=i,co=i+(1<<j);
				if(d[j+1][g])host=i+(1<<j),co=i;
				if(a[host]>=j+1)a[i]=a[host],num[i]=num[host];
				else a[i]=a[co],num[i]=num[co];
			}
			if(c[ind].first==(1<<(j+1))){
				int f=ind;
				while(c[ind].first==c[f].first)out^=(c[ind].second*num[1]),ind++;
			}
		}
		cout<<out<<endl;
		//cerr<<out;
	}
	return 0;
}

