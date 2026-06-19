#include<bits/stdc++.h>
using namespace std;
int n;
map<int,int> d;
map<int,int> a;
map<int,int>::iterator it;
map<int,int>::iterator it2;
map<int,int>::iterator it3;
map<int,int>::iterator it4;
long long ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		d[x]++;
		a[x]++;
	}
	it3=a.begin();
	for(it=d.begin();it!=d.end();it++){
		it4=a.begin();
		for(it2=d.begin();it2!=it;it2++){
			if(it3->second>=it2->second){
				it3->second-=it2->second;
				it2->second=0;
				it4->second=0;
			}
			else{
				it2->second-=it3->second;
				it4->second-=it3->second;
				it3->second=0;
			}
			it4++;
		}
		it3++;
	}
	for(it=d.begin();it!=d.end();it++){
		ans+=it->second;
	}
	cout<<ans<<endl;
	return 0;
}
