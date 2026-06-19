#include<iostream>
#include<cstdio>
int cnt[1000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	std::cin>>T;
	for(int t=1;t<T;t++){
		int n;
		std::cin>>n;
		int ans=0;
		for(int i=1;i<=n;i++){
			int a;
			std::cin>>a;
			cnt[a]++;
			if(cnt[a]==2){
				ans+=a;
				cnt[a]-=2;
			}
		}
		std::cout<<ans<<"\n"; 
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
