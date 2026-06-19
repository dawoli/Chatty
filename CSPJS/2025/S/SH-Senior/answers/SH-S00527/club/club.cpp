#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=1e5+5;
int a[N][4];
int Sa[N];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(0);
	
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n;
		ll res=0;
		m=n/2;
		int c[3]={0,0,0};
		for(int i=0;i<n;i++){
			int d=0;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(a[i][j]>a[i][d])d=j;
			}
			a[i][3]=d;
			c[d]++;
			res+=a[i][d];
		}
		int d=-1;
		for(int i=0;i<3;i++)if(c[i]>m)d=i;
		if(d==-1){
			cout<<res<<endl;
			continue;
		}
		int id[3]={0,1,2};swap(id[0],id[d]);
		int len=0;
		for(int i=0;i<n;i++){
			if(a[i][3]!=d)continue;
			int mx=max(a[i][id[1]],a[i][id[2]]);
			Sa[len++]=a[i][d]-mx;
		}
		sort(Sa,Sa+len);
		for(int i=0;i+m<len;i++)res-=Sa[i];
		cout<<res<<endl;
	}
	
	cout<<flush;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

