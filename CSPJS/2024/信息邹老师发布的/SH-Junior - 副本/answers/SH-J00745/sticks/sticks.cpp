#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int num,stick;
};
long long mn;NODE a[10];
void work(int x,bool b,long long sum){
	if(x == 0){
		if(sum < mn && sum > 0){
			mn = sum;
		}
		return ;
	}
	if(b == 0){
		for(int i = 1;i <= 7;i++){
			if(i == 6) continue;
			if(a[i].stick <= x){
				if(a[i].num >= sum % 10 || a[i].num == 0){
					work(x-a[i].stick,1,sum * 10 + a[i].num);
				}
			}
			else{
				break;
			}
		}
	}
	if(b == 1){
		for(int i = 1;i <= 7;i++){
			if(i == 5) continue;
			if(a[i].stick <= x){
				if(a[i].num >= sum % 10 || a[i].num == 0){
					work(x-a[i].stick,1,sum * 10 + a[i].num);
				}
			}
			else{
				break;
			}
		}
	}
	return ;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[6].num = 0;a[6].stick = 6;
	a[1].num = 1;a[1].stick = 2;
	a[4].num = 2;a[4].stick = 5;
	a[3].num = 4;a[3].stick = 4;
	a[2].num = 7;a[2].stick = 3;
	a[7].num = 8;a[7].stick = 7;
	a[5].num = 6;a[5].stick = 6;
	int n;cin>>n;
	for(int i = 1;i <= n;i++){
		mn = INT_MAX;
		int x;cin>>x;
		if(x % 7 == 0){
			string s = "";
			for(short int j = 1;j <= x/7;++j){
				s+='8';
			}
			cout<<s;
			printf("\n");
			continue;
		}
		if(x % 7 == 1){
			string s = "";
			s+="10";
			for(short int j = 1;j <= (x-8)/7;++j){
				s+='8';
			}
			cout<<s;
			printf("\n");
			continue;
		}
		work(x,0,0);
		if(mn == INT_MAX) cout<<-1<<endl;
		else cout<<mn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
