#include<bits/stdc++.h>

using namespace std;
int n;
long long k;
long long ans;
long long last=1;
long long cnt;
int a[500007];
struct node{
	int s;
	int e;
}t[500007];
bool cmp(node x,node y){
	return x.e<y.e;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			long long sum=0;
			for(int p=i;p<=j;p++){
				sum=sum^a[p];
			}
			if(sum==k){
				t[++cnt].s=i;
				t[cnt].e=j;	
			} 
		}
	}
	sort(t+1,t+1+cnt,cmp);
	for(int i=2;i<=cnt;i++){
		if(t[i].s>t[last].e){
			last=i;
			ans++;
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
