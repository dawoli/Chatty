#include <iostream>

int dp[100001] = {
	-1,-1,1,7,4,2,0,8
};//with zero

int ans[100001] = {
	-1,-1,1,7,4,2,6,8
};//without zero

int main()
{
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	for(int i = 8;i<=100000;i++){
		ans[i] = 0x7f7f7f;
		for(int k = 2;k<=7;k++)
			if(ans[i-k]!=-1)
				ans[i]  = std::min(ans[i],ans[i-k]*10+dp[k]);
		if(ans[i] == 0x7f7f7f)
			ans[i] = -1;
	}
	
	int t;
	std::cin>>t;
	for(int i = 0;i<t;i++){
		int k;std::cin >> k;
		std::cout << ans[k] << std::endl;
	} 
}
