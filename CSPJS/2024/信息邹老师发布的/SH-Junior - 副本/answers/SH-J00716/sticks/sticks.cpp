#include<bits/stdc++.h>
using namespace std;
string s;
int t,n;
pair<string,int> nums[6] = {{"1",2},{"2",5},{"4",4},{"6",6},{"7",3},{"8",7}};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		if(n <= 1){
			cout << "-1\n";
			continue;
		}
		if(n == 2){
			cout << "1\n";
			continue; 
		}
		if(n == 3){
			cout << "7\n";
			continue; 
		}
		if(n == 4){
			cout << "4\n";
			continue; 
		}
		if(n == 5){
			cout << "2\n";
			continue; 
		}
		if(n == 6){
			cout << "6\n";
			continue; 
		}
		if(n == 7){
			cout << "8\n";
			continue; 
		}
		if(n == 8){
			cout << "10\n";
			continue;
		}
		int minimum = 1000000000;
		for(int i = 0; i < 6; i++){
			string tmp = nums[i].first;
			int nn = n - nums[i].second;
			int x = nn % 7;
			if(x == 1){
				nn -= 8;
				tmp += "01";
			}
			else if(x == 2){
				tmp += '1';
			}
			else if(x == 3){
				tmp += '7';
			}
			else if(x == 4){
				tmp += '4';
			}
			else if(x == 5){
				tmp += '2';
			}
			else if(x == 6){
				tmp += '0';
			}
			for(int i  = 0; i < nn/7; i++){
				tmp += '8';
			}
			int sss = tmp.size();
			if(sss < minimum){
				minimum = sss;
				s = tmp;
			}
		}
		cout << s << '\n';
	}
	return 0;
}
