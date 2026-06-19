#include<bits/stdc++.h>
using namespace std;
int x[5][100005],p[100005],q[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++){
		memset(q,0,sizeof(q));
		int n;
		cin>>n;
		int cnt1=0,cnt2=0,cnt3=0,ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[1][i]>>x[2][i]>>x[3][i];
			if(x[1][i]>=x[2][i] && x[1][i]>=x[3][i]){
				p[i]=1;
				cnt1++;
				ans+=x[1][i];
			}
			else if(x[2][i]>=x[1][i] && x[2][i]>=x[3][i]){
				p[i]=2;
				cnt2++;
				ans+=x[2][i];
			}
			else{
				p[i]=3;
				cnt3++;
				ans+=x[3][i];
			}
		}
		int w,f;
		if(cnt1>n/2){
			w=1;
			f=cnt1-n/2;
		}
		else if(cnt2>n/2){
			w=2;
			f=cnt2-n/2;
		}
		else if(cnt3>n/2){
			w=3;
			f=cnt3-n/2;
		}
		else{
			cout<<ans<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(p[i]==1 && w==1)	q[++q[0]]=x[1][i]-max(x[2][i],x[3][i]);
			if(p[i]==2 && w==2)	q[++q[0]]=x[2][i]-max(x[1][i],x[3][i]);
			if(p[i]==3 && w==3)	q[++q[0]]=x[3][i]-max(x[1][i],x[2][i]);
		}
		sort(q+1,q+q[0]+1);
		for(int i=1;i<=f;i++)	ans-=q[i];
		cout<<ans<<endl;
	}
	return 0;
}

