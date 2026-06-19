#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
/*=====================*/
string ques;
int num[1000005]={-1};
/*=====================*/
bool cmp(int a,int b){
	return a > b;
}
/*=====================*/
void Solve(void)
{
	cin >> ques;
	int len = ques.length();
	int num_count = 0;
	for(int i = 0;i < len;i ++){
		if(ques[i] >=48 && ques[i] <=57){
			num[num_count] = ques[i] - 48;
			num_count++;
			//cout<<ques[i]<<" ";
		} 
	} 
	
	sort(num , num + len , cmp);
	
	for(int i = 0;i < num_count;i++){
		if(num[i] >= 0) cout << num[i];
		//else break;
	}
	return ;
}
/*=====================*/
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	Solve();
	return 0;
}
