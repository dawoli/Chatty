#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;

struct Stu{
	int a,b,c;
};

int cmp(Stu a,Stu b){
	if(a.a<b.a) return true;
	if(a.b<b.b) return true;
	if(a.c<b.c) return true;
	return false;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int ans=0,a[n+5]={},cnt[3]={},c[n+5]={};
		for(int i=1;i<=n;i++){
			int t[3];
			cin >> t[0] >> t[1] >> t[2];
			int mx=max(t[0],max(t[1],t[2]));
			ans+=mx;
			for(int j=0;j<3;j++) 
				if(t[j]==mx){
					cnt[j]++;
					c[i]=j;
					if(j==0) a[i]=max(t[1],t[2]);
					if(j==1) a[i]=max(t[0],t[2]);
					if(j==2) a[i]=max(t[1],t[0]);
					a[i]-=t[j];
					break;
					
				}
		}
		for(int k=0;k<3;k++){
			if(cnt[k]>n/2){
				vector<int> b;
				for(int i=1;i<=n;i++){
					if(c[i]==k) b.push_back(a[i]);
				}
				sort(b.begin(),b.end());
				for(int i=b.size()-1;i>=b.size()-cnt[k]+n/2;i--){
					ans+=b[i];
				}
			}
		}
		cout << ans << endl;
	}
}
