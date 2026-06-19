#include <bits/stdc++.h>
using namespace std;
int r[100100]={0},cnt=0;
int flag[100100]={0};
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		flag[a]++;
		if(flag[a]==1){
			r[cnt++]=a;
		}
	}
	sort(r,r+cnt);
	int ans=0;
	int Else=0;
	for(int i=1;i<cnt;i++){
		Else+=flag[r[i-1]];
		int Left=min(flag[r[i]],Else);
		flag[r[i-1]]-=Left;
		Else-=Left;
		ans+=Left;
	}
	cout<<n-ans;
	return 0;
}
