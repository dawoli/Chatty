#include<bits/stdc++.h>
using namespace std;
int n,r[114514],m[114514],ok[114514],m1=0xff,m2=-1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r[i];
		m[r[i]]++;
		ok[r[i]]++;
		m1 = min(m1,r[i]);
		m2 = max(m2,r[i]);
	}
	sort(r,r+n);
	for(int i=1;i<n;i++){
		if(r[i]!=r[i-1]){
			int t1,t2=r[i];//t1±»´ò,t2´ò
			for(int j=i-1;j>=0;j--){
				t1=r[j];
				if(m[t1]>0){
					int death = min(m[t1],ok[t2]);
					m[t1] -= death;
					ok[t2] -= death;
				}
				if(ok[t2]==0) break;
			}
		}
	}
	int ans=0;
	for(int i=m1;i<=m2;i++){
		ans += m[i];
	}
	cout<<ans;
	return 0;
}

