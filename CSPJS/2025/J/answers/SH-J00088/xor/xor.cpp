#include<bits/stdc++.h>
using namespace std;
int n,k,cnt[1048580],s,a,lst,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a);
		s^=a;
		if(k==s||cnt[k^s]){
			if(lst<cnt[k^s]+1){
				lst=i;
				ans++;
			}
		}
		cnt[s]=i;
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
