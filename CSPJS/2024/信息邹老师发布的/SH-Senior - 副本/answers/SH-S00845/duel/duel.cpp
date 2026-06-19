#include<bits/stdc++.h>
using namespace std;
int n,a[100005],num,c[100005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int pre=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			pre++;
		}
		else{
			num++;
			c[num]=pre;
			pre=1;
		}
	}
	num++;
	c[num]=pre;
	for(int i=1;i<num;i++){
		if(c[i]<c[i+1]){
			if((c[i+1]-c[i])>=ans)ans=0;
			else ans-=(c[i+1]-c[i]);
		}
		else{
			ans+=(c[i]-c[i+1]);
		}
	}
	ans+=c[num];
	cout<<ans<<endl;
	return 0;
}

