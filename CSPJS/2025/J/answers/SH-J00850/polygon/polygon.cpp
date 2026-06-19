#include<bits/stdc++.h>
using namespace std;
long long ans;
int n;
vector<int> a;
void zzz(int mx,int all,int i,int size){
	if(n==i){
		if(all>(mx*2) and size>=3){
			if(ans==998244352){
				ans=0;
			}
			else{
				ans++;
			}
		}
		return;
	}
	zzz(mx,all,i+1,size);
	zzz(max(mx,a[i]),all+a[i],i+1,size+1);
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	ans=0;
	int mx=-1;
	for(int i=0;i!=n;i++){
		int temp;
		cin>>temp;
		a.push_back(temp);
		mx=max(mx,temp);
	}
	if(mx==1){
		vector<vector<int>> z;
		vector<int> fir;
		z.push_back(fir);
		fir.push_back(1);
		z.push_back(fir);
		long long ans=0;
		for(int i=2;i!=n+1;i++){
			vector<int> temp;
			temp.push_back(i);
			for(int j=0;j!=z[i-1].size()-1;j++){
				temp.push_back(z[i-1][j]+z[i-1][j+1]);
			}
			temp.push_back(1);
			z.push_back(temp);
		}
		for(int i=0;i!=z[n].size();i++){
			ans=(ans+z[n][i])%998244353;
		}
		cout<<ans;
		return 0;
	}
	zzz(-1,0,0,0);
	cout<<ans;
	return 0;
}

