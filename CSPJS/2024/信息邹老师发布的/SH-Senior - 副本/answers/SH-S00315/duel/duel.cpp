#include<bits/stdc++.h>
using namespace std;
int r[100005],n,m[100005],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	int a;
	for(int i=1;i<=n;i++){
		cin>>a;
		r[a]++;
		m[a]++;
	}
	for(int i=2;i<=100002;i++){
		if(m[i-1]>0&&r[i]>0){
			if(m[i-1]>r[i]){
				ans+=r[i];
				m[i-1]-=r[i];
			}else{
				ans+=m[i-1];
				m[i-1]=0;
			}
		}
		m[i]=m[i]+m[i-1];
	}
	ans=n-ans;
	cout<<ans<<endl;
	return 0;
} 
