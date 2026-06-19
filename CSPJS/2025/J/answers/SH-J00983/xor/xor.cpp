#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;

int n,k;
int a[N];
int s[N];
bool vis[N];

struct node{
	int l,r;
}t[N];

int cal(int l,int r){
	return s[r]^s[l-1];
}

int main(){
	//cout<<(1<<20)<<endl;
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			vis[i]=1;
		}
		s[i]=s[i-1]^a[i];
	}
//	for(int i=1;i<=n;i++){
//		for(int j=i;j<=n;j++){
//			printf("[%d,%d]=%d\n",i,j,cal(i,j));
//		}
//	}
	int ans=0;
	int last=0;
	int cnt=0;
	int now=0;
	for(int j=1;j<=n;j++){
		now=j;
		if(vis[j]==1){
			last=j;
			ans++;
			continue;
		}
		for(int i=last+1;i<=j;i++){
			cnt++;
			//cout<<i<<" "<<j<<endl;
			if(cal(i,j)==k){
				//cout<<"**\n";
				ans++;
				last=j;
				break;
			}
		}
	}
	//cout<<cnt<<endl;
	//cout<<now<<endl;
	cout<<ans<<endl;
	
	
	return 0;
}
