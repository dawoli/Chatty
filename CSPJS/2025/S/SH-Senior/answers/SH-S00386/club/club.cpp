#include<bits/stdc++.h>
using namespace std;
int t,n,a[100009],b[100009],c[100009];
void solve(){
	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	vector<int>x,y,z;
	for(int i=1;i<=n;i++){
		int k1=max(max(a[i],b[i]),c[i]);
		int k2=a[i]+b[i]+c[i]-k1-min(min(a[i],b[i]),c[i]);
		res+=k1;
		if(k1==a[i])x.push_back(k1-k2);
		else if(k1==b[i])y.push_back(k1-k2);
		else z.push_back(k1-k2);
	}
	if(x.size()>n/2){
		sort(x.begin(),x.end());
		for(int i=0,j=x.size();i<x.size();i++){
			res-=x[i];
			j--;
			if(j<=n/2)break;
		}
	}
	else if(y.size()>n/2){
		sort(y.begin(),y.end());
		for(int i=0,j=y.size();i<y.size();i++){
			res-=y[i];
			j--;
			if(j<=n/2)break;
		}
	}
	else if(z.size()>n/2){
		sort(z.begin(),z.end());
		for(int i=0,j=z.size();i<z.size();i++){
			res-=z[i];
			j--;
			if(j<=n/2)break;
		}
	}
	cout<<res<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}
