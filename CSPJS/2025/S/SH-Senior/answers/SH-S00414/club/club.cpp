#include<bits/stdc++.h>
#define max3(a,b,c) max(a,max(b,c))
#define int long long
using namespace std;
int t,n,aa1[100010],aa2[100010],aa3[100010];
//rp++
//froepen()
//LUOGU=909552
//IAFO
//Drater!!!
signed main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;int uans=0;
		vector<int> ch1,ch2,ch3;
		for(int i=1;i<=n;i++){
			cin>>aa1[i]>>aa2[i]>>aa3[i];
			int tmp=max3(aa1[i],aa2[i],aa3[i]);uans+=tmp;
			if(aa1[i]==tmp)ch1.push_back(i);
			else if(aa2[i]==tmp)ch2.push_back(i);
			else ch3.push_back(i);
		}vector<int> tmps;
		if(ch1.size()>n/2){
			for(int i:ch1){
				tmps.push_back(min(aa1[i]-aa2[i],aa1[i]-aa3[i]));
			}sort(tmps.begin(),tmps.end());
			int lu=ch1.size()-n/2;
			for(int i=0;i<lu;i++)uans-=tmps[i];
		}else if(ch2.size()>n/2){
			for(int i:ch2){
				tmps.push_back(min(aa2[i]-aa1[i],aa2[i]-aa3[i]));
			}sort(tmps.begin(),tmps.end());
			int lu=ch2.size()-n/2;
			for(int i=0;i<lu;i++)uans-=tmps[i];
		}else if(ch3.size()>n/2){
			for(int i:ch3){
				tmps.push_back(min(aa3[i]-aa2[i],aa3[i]-aa1[i]));
			}sort(tmps.begin(),tmps.end());
			int lu=ch3.size()-n/2;
			for(int i=0;i<lu;i++)uans-=tmps[i];
		}cout<<uans<<'\n';
	}
	return 0;
}
