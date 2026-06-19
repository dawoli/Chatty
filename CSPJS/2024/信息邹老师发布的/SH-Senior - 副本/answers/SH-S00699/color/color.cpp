#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int t,n,a[maxn],ans=0,max_ans=0;
void solve15(){
	max_ans=0;
	for(int i=0;i<(1<<n);i++){
		ans=0;
		vector<int> dig;int j=i;
		while(j>0){
			dig.push_back(j%2);
			j/=2;
		}
		int siz=dig.size();
		for(int j=0;j<n-siz;j++) dig.push_back(0);
		for(int j=1;j<n;j++){
			int near=-1;
			for(int k=0;k<j;k++){
				if(dig[k]==dig[j]){
					if(a[k]==a[j]){
						ans+=a[k];break;
					}
				}
			}
		}
		max_ans=max(ans,max_ans);
	}
	cout<<max_ans<<endl;
}
void solve(){
	
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i];
		if(n<=15) solve15();
		else solve();
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
