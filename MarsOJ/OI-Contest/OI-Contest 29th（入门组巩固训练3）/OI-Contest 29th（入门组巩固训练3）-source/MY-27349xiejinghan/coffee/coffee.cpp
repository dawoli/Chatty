#include<bits/stdc++.h>
using namespace std;
long long q,n,m,ans,cnt[8],c;
string s;
int main(){
	freopen("coffee.in","r",stdin);
	freopen("coffee.out","w",stdout);
	cin>>q;
	for(int p=1;p<=q;p++){
		ans=0,c=0,memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=5;i++){
			for(int j=1;j<=8;j++){
				cin>>s;
				if(s=="math") cnt[i]++,c++; 
			}
		}
		cin>>n>>m;
		int t=n/7,r=n%7;
		ans+=c*t;
		//cout<<ans<<" "<<r<<" ";
		if(r!=0){
			for(int i=0;i<r;i++){
				int j=m+i;
				if(j>7) j-=7;
				ans+=cnt[j];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
