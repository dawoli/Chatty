#include<bits/stdc++.h>
#define N 100005
using namespace std;
int t,ans=0;
map<int,int> d;
map<int,int>::iterator it;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		int n,a[N];
		d.clear();
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			d[a[i]]++;
		}
		int tmp=0;
		for(it=d.begin();it!=d.end();it++){
//			cout<<it->second<<endl;
			if(it->second%2!=0) it->second--;
			tmp+=it->second;
		}
		if(tmp==0){
			cout<<0<<endl;
		}
		else{
			for(it=d.begin();it!=d.end();it++){
//				cout<<(it->second/2)*it->first<<endl;
				ans+=(it->second/2)*it->first;
			}
			cout<<ans<<endl;
		}
//		cout<<endl;
	}
	return 0;
}
