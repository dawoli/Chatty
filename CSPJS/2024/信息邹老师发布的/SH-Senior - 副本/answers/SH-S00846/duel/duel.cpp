#include<bits/stdc++.h>
using namespace std;
const int N=1e5+30;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}	
	sort(a+1,a+n+1);
	int j=1,i=1,ans=n;
	while(i<=n){
		while(a[i]<=a[j]&&i<n) i++;
		if(a[i]>a[j]){j++,ans--;}
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
