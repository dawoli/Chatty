#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int mon[200000],q[200000];
	for(int i=0;i<n;i++){
		cin>>mon[i];
	}
	sort(mon,mon+n);
	int a=mon[0],cnt=0;
	q[0]=1;
	for(int i=1;i<n;i++){
		if(mon[i]==a) q[cnt]++;
		else{
			a=mon[i];
			cnt++;
			q[cnt]++;
		}
	}
	//warn:q[0,cnt]
	
	int ans=n;
	int ar=0;
	
	ar=q[0];
	for(int i=1;i<=cnt;i++){
		ans-=min(ar,q[i]);
		ar-=min(ar,q[i]);
		ar+=q[i];
	}
	cout<<ans<<endl;
	return 0;
}
