#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][5],b[N];
vector<int> tmp;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n,c1=0,c2=0,c3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int s=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==s) b[i]=1,c1++;
			else if(a[i][2]==s) b[i]=2,c2++;
			else b[i]=3,c3++;
			ans+=s;
		}
		if(c2>n/2){
			swap(c1,c2);
			for(int i=1;i<=n;i++){
				swap(a[i][1],a[i][2]);
				if(b[i]==1) b[i]=2;
				else if(b[i]==2) b[i]=1;
			}
		}
		if(c3>n/2){
			swap(c1,c3);
			for(int i=1;i<=n;i++){
				swap(a[i][1],a[i][3]);
				if(b[i]==1) b[i]=3;
				else if(b[i]==3) b[i]=1;
			}
		}
		if(c1>n/2){
			for(int i=1;i<=n;i++){
				if(b[i]==1) tmp.push_back(a[i][1]-max(a[i][2],a[i][3]));
			}
			sort(tmp.begin(),tmp.end());
			for(int i=0;i<c1-n/2;i++) ans-=tmp[i];
			tmp.clear();
		}
		cout<<ans<<"\n";
	}
	return 0;
}
