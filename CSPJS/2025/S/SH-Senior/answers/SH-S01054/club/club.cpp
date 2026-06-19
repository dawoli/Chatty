#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N=1e5+10;

int a1[N],a2[N],a3[N];
int vis[N];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int ans=0;
		int num1=0,num2=0,num3=0;
		for(int i=1;i<=n;i++){
			vis[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
				ans+=a1[i];
				num1++;
				vis[i]=1;
			} 
			else if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
				ans+=a2[i];
				num2++;
				vis[i]=2;
			} 
			else if(a3[i]>=a1[i]&&a3[i]>=a2[i]){
				ans+=a3[i];
				num3++;
				vis[i]=3;
			} 
		} 
//		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<endl;
//		}
		int lim=n/2;
//		cout<<ans<<endl;
		if(num1>lim){
//			cout<<1ll<<endl;
			int d=num1-lim;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(vis[i]==1){
					if(a2[i]>a3[i]){
						v.push_back(a1[i]-a2[i]);
					}
					else v.push_back(a1[i]-a3[i]);
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<d;i++){
				ans-=v[i];
			}
		}
		else if(num2>lim){
//			cout<<2ll<<endl;
			int d=num2-lim;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(vis[i]==2){
					if(a1[i]>a3[i]){
						v.push_back(a2[i]-a1[i]);
					}
					else v.push_back(a2[i]-a3[i]);
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<d;i++){
				ans-=v[i];
			}
		}
		else if(num3>lim){
//			cout<<3ll<<endl;
			int d=num3-lim;
			vector<int> v;
			for(int i=1;i<=n;i++){
				if(vis[i]==3){
					if(a1[i]>a2[i]){
						v.push_back(a3[i]-a1[i]);
					}
					else v.push_back(a3[i]-a2[i]);
				}
			}
			sort(v.begin(),v.end());
			for(int i=0;i<d;i++){
				ans-=v[i];
			}
		}
		cout<<ans<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<vis[i]<<endl;
//		}
	}
} 

/*

10 2020 14533 18961 2423 15344 16322 1910 6224 16178 2038 9963 19722 8375 10557 5444 3518 14615 17976 6188 13424 16615 8769 509 4394 958 3195 9953 16441 5313 10926

10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926

18961


*/
