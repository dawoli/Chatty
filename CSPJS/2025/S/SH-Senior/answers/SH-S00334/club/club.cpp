#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t,n,a[100010][3],dif[100010],maxn[100010],te[3],tm[3],ans[5],flag=0;
	bool idi[100010];
	memset(ans,0,sizeof(ans));
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		memset(idi,0,sizeof(idi));
		memset(tm,0,sizeof(tm));
		memset(te,0,sizeof(te));
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			tm[0]=a[j][0];
			tm[1]=a[j][1];
			tm[2]=a[j][2];
			sort(tm,tm+3);
			maxn[j]=tm[2];
			if(maxn[j]==a[j][0]) flag=0;
			else if(maxn[j]==a[j][1]) flag=1;
			else flag=2;
			ans[i]+=maxn[j];
			te[flag]++;
			dif[j]=maxn[j]-tm[1];
			if(te[flag]>n/2){
				int minn=20001,fl=0;
				for(int k=0;k<j;k++){
					if(maxn[k]!=a[k][flag]||idi[k]==true) continue;
					else{
						if(dif[k]<minn){
							minn=dif[k];
							fl=k; 
						}
					}
				}
				if(dif[j]>minn){
					idi[fl]=true;
					ans[i]-=minn;
				}
				else ans[i]-=dif[j];
				te[flag]--;
			}
		}
	}
	for(int i=0;i<t;i++)
		cout<<ans[i]<<endl;
	return 0;
}
