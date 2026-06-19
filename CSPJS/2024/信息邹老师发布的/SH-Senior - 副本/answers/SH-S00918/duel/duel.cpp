#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int ri[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int cnt=n;
	for(int i=1;i<=n;++i){
		cin>>ri[i];
	}
	sort(ri+1,ri+n+1);
	int j=1;
	for(int i=2;i<=n;++i){
		if(ri[j]!=-1 && ri[i]>ri[j]){
				ri[j]=-1;
				cnt--;
				j++;
		}
	}
	cout<<cnt;
	return 0;
}
