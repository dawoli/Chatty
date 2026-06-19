#include<bits/stdc++.h>
using namespace std;
int rd(){
	char c=getchar();int x=0;
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
int t,n,a[100005][5],ans;
vector<int> s[5];
bool cmp(int x,int y){
	return a[x][0]>a[y][0];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;getchar();
		for(int i=1;i<=n;i++){
			a[i][1]=rd();a[i][2]=rd();a[i][3]=rd();
			if(a[i][1]>=a[i][2] && a[i][1]>=a[i][3]){
				ans+=a[i][1];s[1].push_back(i);
				if(a[i][2]>a[i][3]) a[i][0]=a[i][1]-a[i][2];
				else a[i][0]=a[i][1]-a[i][3];
			}
			else if(a[i][2]>=a[i][1] && a[i][2]>=a[i][3]){
				ans+=a[i][2];s[2].push_back(i);
				if(a[i][1]>a[i][3]) a[i][0]=a[i][2]-a[i][1];
				else a[i][0]=a[i][2]-a[i][3];
			}
			else{
				ans+=a[i][3];s[3].push_back(i);
				if(a[i][2]>a[i][1]) a[i][0]=a[i][3]-a[i][2];
				else a[i][0]=a[i][3]-a[i][1];
			}
		}
		if(s[1].size()>n/2){
			sort(s[1].begin(),s[1].end(),cmp);
			for(int i=s[1].size()-1;i>=n/2;i--)
			ans-=a[s[1][i]][0];
		}
		else if(s[2].size()>n/2){
			sort(s[2].begin(),s[2].end(),cmp);
			for(int i=s[2].size()-1;i>=n/2;i--)
			ans-=a[s[2][i]][0];
		}
		else if(s[3].size()>n/2){
			sort(s[3].begin(),s[3].end(),cmp);
			for(int i=s[3].size()-1;i>=n/2;i--)
			ans-=a[s[3][i]][0];
		}
		cout<<ans<<endl;
		ans=0;s[1].clear();s[2].clear();s[3].clear();
		for(int i=1;i<=n;i++)
		a[i][0]=a[i][1]=a[i][2]=a[i][3]=0;
	}
	return 0;
}
