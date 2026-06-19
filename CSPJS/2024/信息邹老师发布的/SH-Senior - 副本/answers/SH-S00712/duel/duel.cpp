#include <iostream>
#include <cstdio>
using namespace std;
int n,r[100005],f[100005],v[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(r[i]>r[j]&&v[j]==0){
				f[j]=1;
				v[j]=1;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
