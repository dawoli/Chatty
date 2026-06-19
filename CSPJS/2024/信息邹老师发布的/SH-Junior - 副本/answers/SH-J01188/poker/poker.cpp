#include<iostream>
#include<cstring>
using namespace std;
int main(){
	freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	int i, j, u, n;
	string pokers[10010] = {};
	char styles[5] = {'D', 'C', 'H', 'S'};
	char num_or_letters[13] = {'A', '2', '3', '4', '5', '6', '7','8', '9', 'T', 'J', 'Q', 'K'};
	cin >> n;
	for(i = 0; i < n; i++) cin >> pokers[i];
	int count = 0;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 13; j++){
			string poker;
			poker += styles[i];
			poker += num_or_letters[j];
			bool flag = false;
			for(u = 0; u < 53; u++){
				if(pokers[u] == poker){
					flag = true;
					break;
				}
			}
			if(!flag){
				count++;
			}
		}
	}
	cout << count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
