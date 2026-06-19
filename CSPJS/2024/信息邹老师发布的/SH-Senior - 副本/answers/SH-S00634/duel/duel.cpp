#include<bits/stdc++.h>
using namespace std;
int n,a[100005],sta[100005],tot=1;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt++;
		else{
			sta[tot++]=cnt;
//			cout<<"cnt="<<cnt<<endl;
			cnt=1;
		}
	}sta[tot++]=cnt;
//	for(int i=1;i<=tot;i++)cout<<sta[i]<<" ";
//	cout<<endl;
	int ans=0,pool=sta[1];
	for(int i=2;i<=tot;i++){
		if(sta[i]>=pool){
			ans+=pool;
			pool=sta[i];
		}else{
			ans+=sta[i];
		}
//		cout<<"ans="<<ans<<"pool="<<pool<<endl;
	}printf("%d\n",n-ans);
	return 0;
} 

