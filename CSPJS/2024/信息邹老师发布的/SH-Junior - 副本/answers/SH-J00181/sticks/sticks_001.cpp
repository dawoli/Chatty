#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin >> n;
	while(n--){
		ans = 0;
		int x,weishu,ans = 0;
		cin >> x;
		if(x % 7 == 0) weishu = x/7;
		else weishu = x/7+1;
		int st = weishu;
		while(weishu >= 1){
			if(weishu == 1 && x == 1)  ans = -1;
			else if(weishu == 1 && x != 1){
				ans *= 10;
				if(x == 2) ans+=1;
				if(x == 3) ans+=7;
				if(x == 4) ans+=4;
				if(x == 5) ans+=2;
				if(x == 7) ans+=8;
			}
			else{
				if((weishu-1)*7 >= x-6 && weishu != st){
					ans = ans*10;
					x -= 6;
				}
				else if((weishu-1)*7 >= x-2){
					ans = ans*10+1;
					x -= 2;
				}
				else if((weishu-1)*7 >= x-5){
					ans = ans*10+2;
					x -= 5;
				}
				else if((weishu-1)*7 >= x-7){
					ans = ans*10+3;
					x -= 7;
				}
				else if((weishu-1)*7 >= x-4){
					ans = ans*10+4;
					x -= 4;
				}
				else if((weishu-1)*7 >= x-3){
					ans = ans*10+7;
					x -= 3;
				}
				else{
					ans = ans*10+8;
					x -= 7;
				}
			}
			weishu--;
		}
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
