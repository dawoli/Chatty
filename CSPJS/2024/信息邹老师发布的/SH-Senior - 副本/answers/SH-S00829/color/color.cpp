#include<bits/stdc++.h>
using namespace std;
int t,n,a[200010],ans;
int bucket[1000010];
bool flag;
int main(){
	cin>>t;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	while(t){
		cin>>n;
		memset(bucket,0,sizeof(bucket));
		ans=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			bucket[a[i]]++;
		}
		for(int i=0;i<n;i++){
			if(bucket[a[i]]>1){
				ans+=(bucket[a[i]]-1)*a[i];
				bucket[a[i]]=1;
			}
		}
		cout<<ans<<endl;
		t--;
	}
	return 0;
}
