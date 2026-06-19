#include <bits/stdc++.h>
using namespace std;
int n;
struct newmem{
	int num;
	int down;
};
int tiaozhen(vector<newmem> a,vector<int> b,vector<int> c ,int sum){
	int l=a.size();
	while(l>n/2){
		int minx=INT_MAX,minn=0;
		for(int i=0;i<a.size();i++){
			int maxx=max(b[a[i].down],c[a[i].down]);
			if(minx>=a[i].num-maxx&&a[i].num>=0){
				minx=a[i].num-maxx;
				minn=i;
			}
		}
		a[minn].num=-1;
		sum-=minx;
		l--;
	}
	return sum;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		vector<int> a(n,0),b(n,0),c(n,0);
		vector<newmem> na,nb,nc;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				na.push_back({a[i],i});
				sum+=a[i];
			}else if(b[i]>=a[i]&&b[i]>=c[i]){
				nb.push_back({b[i],i});
				sum+=b[i];
			}else{
				nc.push_back({c[i],i});
				sum+=c[i];
			}
		}
		if(na.size()>(n/2)){
			sum=tiaozhen(na,b,c,sum);
		}
		if(nb.size()>(n/2)){
			sum=tiaozhen(nb,a,c,sum);
		}
		if(nc.size()>(n/2)){
			sum=tiaozhen(nc,a,b,sum);
		}
		cout<<sum<<endl;
	}
	return 0;
}
