#include<bits/stdc++.h>
using namespace std;
int t;
int n;
struct member{
	int cb[5];
	int maxc,midc,minc;
	int lc1,lc2;
}a[200005];


int maxx(int i){
	int x=max(a[i].cb[1],max(a[i].cb[2],a[i].cb[3]));
	if(x==a[i].cb[1]) return 1;
	if(x==a[i].cb[2]) return 2;
	return 3;
}
int minn(int i){
	int x=min(a[i].cb[1],min(a[i].cb[2],a[i].cb[3]));
	if(x==a[i].cb[1]) return 1;
	if(x==a[i].cb[2]) return 2;
	return 3;
}
int midd(int i){
	if(a[i].maxc!=1&&a[i].minc!=1) return 1;
	if(a[i].maxc!=2&&a[i].minc!=2) return 2;
	return 3;
}
void shuru(int i){
    cin>>a[i].cb[1]>>a[i].cb[2]>>a[i].cb[3];
	a[i].maxc=maxx(i);
	a[i].minc=minn(i);
	a[i].midc=midd(i);
	a[i].lc1=a[i].cb[a[i].maxc]-a[i].cb[a[i].midc];
	a[i].lc2=a[i].cb[a[i].midc]-a[i].cb[a[i].minc];
}

long long ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++) shuru(i);
		//cout<<1<<"!";
		vector<pair<int,int> > c1,c2,c3;
		for(int i=1;i<=n;i++){
			int maxi=a[i].maxc;
			if(maxi==1) c1.push_back(make_pair(a[i].lc1,i));
			else if(maxi==2) c2.push_back(make_pair(a[i].lc1,i));
			else c3.push_back(make_pair(a[i].lc1,i));
		}
		//cout<<2<<"!";
		ans=0;
		int j;
		sort(c1.begin(),c1.end());
		j=0;
		if(c1.size()>n/2)
			for(;j<(c1.size()-n/2);j++)
				ans+=a[c1[j].second].cb[a[c1[j].second].midc];
				
		for(;j<c1.size();j++)
			ans+=a[c1[j].second].cb[1];
		//cout<<ans<<"!";
		
		sort(c2.begin(),c2.end());
		j=0;
		if(c2.size()>n/2)
			for(;j<(c2.size()-n/2);j++)
			    ans+=a[c2[j].second].cb[a[c2[j].second].midc];
		for(;j<c2.size();j++)
			ans+=a[c2[j].second].cb[2];
		//cout<<ans<<"!";
			
		sort(c3.begin(),c3.end());
		j=0;
		if(c3.size()>n/2)
			for(;j<(c3.size()-n/2);j++)
				ans+=a[c3[j].second].cb[a[c3[j].second].midc];
		for(;j<c3.size();j++)
			ans+=a[c3[j].second].cb[3];
		//cout<<ans<<"!";
		
		cout<<ans<<endl;
	}
	return 0;
}
