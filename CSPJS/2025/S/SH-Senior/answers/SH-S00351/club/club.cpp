#include<bits/stdc++.h>
#include<set>
using namespace std;
int t,n,a[100005][3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int tt=0;tt<t;tt++){
		multiset<int> s[3];
		long long ans=0;
		cin>>n;
		for(int i=0;i<n;i++){
			int ma=-1,mb=-1,ti=0,ls;
			for(int j=0;j<3;j++){
				cin>>a[i][j];
				if(ma<a[i][j]){
					ti=j;
					mb=ma;
					ma=a[i][j];
				}
				else if(mb<a[i][j]){
					mb=a[i][j];
				}
			}
			ans+=ma;
			ls=ma-mb;
			if(s[ti].size()==n/2){
				if(ls>*s[ti].begin()){
					ans-=*s[ti].begin();
					s[ti].erase(s[ti].begin());
					s[ti].insert(ls);
				}
				else{
					ans-=ls;
				}
			}
			else{
				s[ti].insert(ls);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
