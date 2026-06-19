#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100005],precnt=0,nowcnt=1,ans=0;//precnt上种怪物可攻击数量，nowcnt本种怪物数量，ans击败怪物数量
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
//	cout<<endl;
	for(int i=n-1;i>=1;i--){
		if(a[i+1]>a[i]){
			precnt+=nowcnt-1;
			nowcnt=1;
			ans++;
		}
		else{
			nowcnt++;
			if(precnt>0) precnt--,ans++;
		}
//		cout<<precnt<<" "<<nowcnt<<" "<<ans<<endl;
	}
	cout<<n-ans<<endl;
	return 0;
}
