#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500000],b,mx;
struct p{
	long long s,e;
};
vector<p> ans;
bool cmp(p a,p b){
	return a.e<b.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			if(i==j){
				b=a[i];
			}else{
				b=b^a[j];
			}
			if(b==k){
				ans.push_back({i,j});
			}
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	int l=0;
	for(int i=0; i<ans.size(); i++){
		//cout<<ans[i].s<<' '<<ans[i].e<<endl;
		if(ans[i].s<=l){
			continue;
		}else{
			l=ans[i].e;
			mx++;
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
