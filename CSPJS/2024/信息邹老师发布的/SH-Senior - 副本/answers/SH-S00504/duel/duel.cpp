#include<bits/stdc++.h>
using namespace std;
int n,a[100010],t[100010],v[100010];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)    
		cin>>a[i],t[a[i]]++,v[a[i]]++;
	for(int i=1,j=0;i<=100000;){
		for(;j<i;++j)
			if(t[j])
				break;
		if(i==j)
			i++;
		if(v[i]>=t[j])
			v[i]-=t[j],t[j]=0;
		else
			t[j]-=v[i],v[i]=0,++i;
	}
	int ans=0;
	for(int i=0;i<=100000;++i){
		ans+=t[i];
	}
	cout<<ans<<endl;
	return 0;
} 
