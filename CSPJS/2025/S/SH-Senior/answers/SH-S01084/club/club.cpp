#include<bits/stdc++.h>//小菜比第一次S组，T1估计能骗25分（话说今年T1这么难的吗QWQ) 
using namespace std;//Luogu用户名：Manor，快来炸我私信 
long long n,ans,a[100005][5],first[50005],second[50005],third[50005];
void dfs(int s1,int s2,int s3){
	if(s1+s2+s3==n){
		long long s=0;
		for(int i=1;i<=s1;i++) s+=first[i];
		for(int i=1;i<=s2;i++) s+=second[i];
		for(int i=1;i<=s3;i++) s+=third[i];
		ans=max(ans,s);
		return;
	}
	if(s1<n/2){
		first[s1+1]=a[s1+s2+s3+1][1];
		dfs(s1+1,s2,s3);
	}
	if(s2<n/2){
		second[s2+1]=a[s1+s2+s3+1][2];
		dfs(s1,s2+1,s3);
	}
	if(s3<n/2){
		third[s3+1]=a[s1+s2+s3+1][3];
		dfs(s1,s2,s3+1);
	}
}
int main(){
	freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		bool flag1=true,flag2=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][2]!=0) flag1=false;
			if(a[i][3]!=0) flag2=false;
		}
		ans=0;
		if(flag1 && flag2){//特性A
			vector<long long> vec;
			for(int i=1;i<=n;i++) vec.push_back(a[i][1]);
			sort(vec.begin(),vec.end());
			for(int i=n-1;i>=n/2;i--) ans+=vec[i];
		}
		else dfs(0,0,0);//暴力
		cout<<ans<<"\n";
	}
	return 0;
}
/*听说膜拜CCF能增加分数QWQ 
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
stO  CCF
*/
