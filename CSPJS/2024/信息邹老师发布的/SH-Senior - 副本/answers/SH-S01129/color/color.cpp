#include<iostream>
using namespace std;
int n,ans,lat1,lat2,T;
int a[200005];
int d[200005];
int judge(){
	int b=0;
	for(int i=n;i>=1;i--){
		if(d[i]==1) lat1=i;
		else lat2=i;
	}
	for(int i=1;i<=n;i++){
		if(lat2!=i&&d[i]==2&&d[i]==d[lat2]&&a[i]==a[lat2]){
			b+=a[i];
		}
		if(lat1!=i&&d[i]==1&&d[i]==d[lat1]&&a[i]==a[lat1]){
			b+=a[i];
			
		}
		if(d[i]==1) lat1=i;
		if(d[i]==2) lat2=i;
	}
	return b;
}
void dfs(int x){
	if(x==n+1){
		int y=judge();
		if(ans<=y) ans=y;
		return;		
	}
	d[x]=1;
	x++;
	dfs(x);
	x--;
	d[x]=2;
	x++;
	dfs(x);
	x--;
	return;
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.ans","w",stdout);
	cin>>T;
	while(T>0){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1);
		cout<<ans<<endl;
		T--;
		ans=0;
	}
	return 0;
}
