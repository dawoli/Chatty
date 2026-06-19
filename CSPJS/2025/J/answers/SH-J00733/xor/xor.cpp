#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,f=1,ans,cntr,FFF=1;
vector<pair<int,int>> v;
int a;
int b[500005];
int c[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a>1) FFF=0; 
		c[i]=a^c[i-1];
		b[i]=a^b[i-1];
//		cout<<b[i]<<'\n';
		if(c[i]==k) cnt++,c[i]=0;
	}
	if(k>1000||FFF&&k==1){
		cout<<cnt;
		goto end;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((b[i-1]^b[j])==k){
				v.push_back({i,j});
//				cout<<i<<' '<<j<<'\n';
				break;
			} 
		}
	}
	ans=v.size();
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++){
		for(int j=0;j<i;j++){
			if(v[j].first==0&&v[j].second==0) continue;
			if(v[i].first<=v[j].second){
				v[i]={0,0},ans--;
				++cntr;
				break;
			}
		}
	}
//	cout<<cntr<<' ';
	cout<<ans;
	end:;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
