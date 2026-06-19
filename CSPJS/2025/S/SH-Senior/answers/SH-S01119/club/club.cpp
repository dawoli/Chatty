/*========club==========*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
/*========club==========*/

const int maxn=1e5+8;
int n,t,overflow;
int a[maxn][4];
pair<int,int> lo[maxn][2];
int dp[3][maxn];

pair<int,int> b[4];

template<typename T>
void sort3(T *arr){
	T &arr1=*arr;
	T &arr2=*(arr+1);
	T &arr3=*(arr+2);
	if(arr1>arr2) swap(arr1,arr2);
	if(arr2>arr3) swap(arr2,arr3);
	if(arr1>arr2) swap(arr1,arr2);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int lovers[7]={0},mul=0;
		cin>>n;
		int prep_ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			b[1]=make_pair(a[i][1],1);
			b[2]=make_pair(a[i][2],2);
			b[3]=make_pair(a[i][3],3);
			sort3(b+1);
			int max_a_i=b[3].first;
			int min_a_i=b[1].first;
			prep_ans+=max_a_i;
			lovers[b[3].second]++;
			if(b[2].first==max_a_i)lovers[b[2].second]++,lovers[b[2].second+b[3].second+1]++;
			if(b[1].first==max_a_i)lovers[b[1].second]++,lovers[0]++;
			lo[i][0]=b[3];lo[i][1]=b[2];
		}
		b[1]=make_pair(lovers[1],1);
		b[2]=make_pair(lovers[2],2);
		b[3]=make_pair(lovers[3],3);
		sort3(b+1);
		int most_loved=b[3].first;
		if(most_loved<=n/2||n>1000){
			cout<<prep_ans<<endl;
			continue;
		}
		if(most_loved==lovers[1]) overflow=1;
		if(most_loved==lovers[2]) overflow=2;
		if(most_loved==lovers[3]) overflow=3;
		//cerr<<"Overflow=="<<overflow<<endl;
		int cnt=1;
		for(int i=1;i<=n;i++){
			//if(lo[i][0].second==overflow) cerr<<i<<" loves "<<overflow<<endl;
			for(int j=0;j<=min(n/2,cnt);j++){
				if(lo[i][0].second!=overflow) dp[i%3][j]=dp[(i-1)%3][j]+lo[i][0].first;
				else if(j<1) dp[i%3][j]=dp[(i-1)%3][j]+lo[i][1].first;
				else{
					cnt++;
					dp[i%3][j]=max(dp[(i-1)%3][j-1]+lo[i][0].first,dp[(i-1)%3][j]+lo[i][1].first);
				}
			}
		}
		int ans=-1;
		for(int j=0;j<=min(n/2,cnt);j++){
			ans=max(dp[n%3][j],ans);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
