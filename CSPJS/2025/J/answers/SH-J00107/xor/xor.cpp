#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N];
int t[N];
int idx;
struct node{
	int l,r;
}arr[N];
bool A=true,B=true;//Ãÿ ‚–‘÷ 
bool cmp(node a,node b){
	if(a.r!=b.r)return a.r<b.r;
	else return a.l<b.l;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=t[i-1]^a[i];
		if(a[i]!=1)A=false;
		if(a[i]>1)B=false;
	}if(A){
		if(k==1)cout<<n;
		else cout<<n/2;
	}else if(B){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1)cnt++;
			}cout<<cnt;
		}else{
			int cnt=0,sum=0;
			for(int i=1;i<=n+1;i++){//n+1
				if(a[i]==0){
					sum++;
					sum+=cnt/2;
					cnt=0;
				}else{
					cnt++;
				}
			}cout<<sum;
		}
	}else{
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if((t[j]^t[i-1])==k){
//					cout<<i<<' '<<j<<' '<<(t[j]^t[i-1])<<endl;
					idx++;
					arr[idx].l=i;
					arr[idx].r=j;
				}
			}
		}sort(arr+1,arr+idx+1,cmp);
		int R=0;
		for(int i=1;i<idx;i++){
//			cout<<arr[i].l<<' '<<arr[i].r<<' '<<(t[arr[i].r]^t[arr[i].l-1])<<"\n";
			if(arr[i].l>R){
				ans++;
				R=arr[i].r;
			}
		}
		cout<<ans;
	}
	return 0;
}
