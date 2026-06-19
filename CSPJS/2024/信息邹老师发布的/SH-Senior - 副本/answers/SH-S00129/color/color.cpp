#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N],num[N];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		memset(a,0,sizeof a);
		memset(num,0,sizeof num);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			num[a[i]]++;
		}
		int ans1=0;
		for(int i=1;i<=n;i++)
			if(i*(num[i]-1)>ans1)ans1=i*(num[i]-1);
		int ans2=0;
		int pre1=a[1],pre2=a[2];
		for(int i=3;i<=n;i++){
			if(a[i]==pre2||a[i]==pre1)ans2+=a[i];
			pre2=pre1,pre1=a[i-2];
		}
		cout<<max(ans1,ans2)<<endl;
	}
	return 0;
}
