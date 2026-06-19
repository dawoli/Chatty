#include<bits/stdc++.h>
using namespace std;
int T;
long long int score(vector<int>a){
	long long int ans=0;
	for(int i=1;i<a.size();i++){
		if(a[i]==a[i-1])ans+=a[i];
	}
	return ans;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		long long ans=INT_MIN;
		short bin[200010]={0};
		int n;
		int a[200010];
	
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(unsigned long long i=0;i<(1<<n);i++){
			bin[1]++;
			int w=1;
			while(bin[w]>1){
				bin[w]=0;
				bin[w+1]++;
				w++;
			}
			vector<int>red,blue;
			for(int j=1;j<=n;j++){
				
				if(bin[j]==1)red.push_back(a[j]);
				else	    blue.push_back(a[j]);
			}
			ans=max(ans,score(red)+score(blue));
		}
		printf("%lld\n",ans);
	}
	return 0;
}
