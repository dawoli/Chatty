#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int n;
int a[4][100010];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int num1=0,num2=0,num3=0;
		multiset<int>s1,s2,s3;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[1][i]>>a[2][i]>>a[3][i];
			if(a[1][i]>=a[2][i]&&a[1][i]>=a[3][i]){
				num1++;
				ans+=a[1][i];
				int sec=a[1][i]-max(a[2][i],a[3][i]);
				s1.insert(sec);
				/*
				int sec=max(a[2][i],a[3][i]);
				if(s1.size()>=n/2){

				}else{
					s1.insert({sec})
				}*/
			}else if(a[2][i]>=a[1][i]&&a[2][i]>=a[3][i]){
				num2++;
				ans+=a[2][i];
				int sec=a[2][i]-max(a[1][i],a[3][i]);
				s2.insert(sec);
			}else{
				num3++;
				ans+=a[3][i];
				int sec=a[3][i]-max(a[1][i],a[2][i]);
				s3.insert(sec);
			}
		}
		if(num1>n/2){
			while(s1.size()>n/2){
				ans-=(*s1.begin());
				s1.erase(s1.begin());
			}
		}else if(num2>n/2){
			while(s2.size()>n/2){
				ans-=(*s2.begin());
				s2.erase(s2.begin());
			}
		}else if(num3>n/2){
			while(s3.size()>n/2){
				ans-=(*s3.begin());
				s3.erase(s3.begin());
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
