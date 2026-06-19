#include<bits/stdc++.h>
using namespace std;
int a[500005];
vector<pair<int,int> > ok;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]=a[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((a[i-1]^a[j])==k){
				ok.push_back({j,i});
			}
		}
	}
	sort(ok.begin(),ok.end());
	int last=0;
	int ans=0;
	for(auto i:ok){
		if(i.second>last){
			last=i.first;
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
