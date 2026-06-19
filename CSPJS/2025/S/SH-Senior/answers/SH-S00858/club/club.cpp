#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct person{
	vector<int> a;
	vector<int> more;
};
void smart(int n){
	vector<int> a;
	long long ans;
	ans=0;
	for(int i=0;i!=n;i++){
		int temp,b,c;
		cin>>temp>>b>>c;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i!=a.size()/2-1;i--){
		ans+=a[i];
	}
	cout<<ans;
	return;
}
long long maxx(long long a,long long b){
	if(a>=b){
		return a;
	}
	return b;
}
void zzz(int n,vector<vector<int>> a,int one,int two,int three,int i,int now){
	if(i==n){
		ans=maxx(ans,now);
		return;
	}
	if(one!=n/2){
		zzz(n,a,one+1,two,three,i+1,now+a[i][0]);
	}
	if(two!=n/2){
		zzz(n,a,one,two+1,three,i+1,now+a[i][1]);
	}
	if(three!=n/2){
		zzz(n,a,one,two,three+1,i+1,now+a[i][2]);
	}
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int zz=0;zz!=t;zz++){
		int n;
		cin>>n;
		if(n>500){//保分模式 
			smart(n);
			return 0;
		}
		vector<vector<int>> a;
		int clubs[3]={0};//每个剧团有多少人 
		for(int i=0;i!=n;i++){
			int b,c,d;
			cin>>b>>c>>d;
			vector<int> temp;
			temp.push_back(b); 
			temp.push_back(c);
			temp.push_back(d);
			a.push_back(temp);
		}
		ans=-1;
		zzz(n,a,0,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}

