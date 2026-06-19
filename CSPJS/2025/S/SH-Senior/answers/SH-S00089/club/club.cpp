#include<bits/stdc++.h>
using namespace std;
int ans,n,ca,cb,cc,ta,tb,tc,t;
vector<int> alt[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		alt[0].clear();
		alt[1].clear();
		alt[2].clear();
		ca=cb=cc=ans=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&ta,&tb,&tc);
			int d=max(max(ta,tb),tc);
			if(d==ta){
				ca++;
				alt[0].push_back(ta-max(tb,tc));
			}
			else if(d==tb){
				cb++;
				alt[1].push_back(tb-max(ta,tc));
			}
			else{
				cc++;
				alt[2].push_back(tc-max(tb,ta));
			}
			ans+=d;
		}
		if(ca>n/2){
		sort(alt[0].begin(),alt[0].end());
			for(int i=0;i<ca-n/2;i++)
				ans-=alt[0][i];
		}
		if(cb>n/2){
		sort(alt[1].begin(),alt[1].end());
			for(int i=0;i<cb-n/2;i++)
				ans-=alt[1][i];
		}
		if(cc>n/2){
		sort(alt[2].begin(),alt[2].end());
			for(int i=0;i<cc-n/2;i++)
				ans-=alt[2][i];
		}
		cout<<ans<<endl;
	}
}
