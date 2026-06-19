#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5+10;
int t,n,ans;
int a1[maxn],a2[maxn],a3[maxn],cho[maxn],cha[maxn],cnt1,cnt2,cnt3;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cnt1=cnt2=cnt3=ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a1[i],&a2[i],&a3[i]);
			if(a1[i]>=max(a2[i],a3[i])){
				cho[i]=1;
				cnt1++;
				ans+=a1[i];
				cha[i]=a1[i]-max(a2[i],a3[i]);
			}
			else if(a2[i]>=max(a1[i],a3[i])){
				cho[i]=2;
				cnt2++;
				ans+=a2[i];
				cha[i]=a2[i]-max(a1[i],a3[i]);
			}
			else{
				cho[i]=3;
				cnt3++;
				ans+=a3[i];
				cha[i]=a3[i]-max(a1[i],a2[i]);
			}
		}
		if(cnt1>(n/2)){
			vector<int> q1;
			for(int i=1;i<=n;i++){
				if(cho[i]==1) q1.push_back(cha[i]);
			}
			sort(q1.begin(),q1.end());
			for(int i=0;i<cnt1-(n/2);i++){
				ans-=q1[i];
			}
		}
		if(cnt2>(n/2)){
			vector<int> q2;
			for(int i=1;i<=n;i++){
				if(cho[i]==2) q2.push_back(cha[i]);
			}
			sort(q2.begin(),q2.end());
			for(int i=0;i<cnt2-(n/2);i++){
				ans-=q2[i];
			}
		}
		if(cnt3>(n/2)){
			vector<int> q3;
			for(int i=1;i<=n;i++){
				if(cho[i]==3) q3.push_back(cha[i]);
			}
			sort(q3.begin(),q3.end());
			for(int i=0;i<cnt3-(n/2);i++){
				ans-=q3[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
