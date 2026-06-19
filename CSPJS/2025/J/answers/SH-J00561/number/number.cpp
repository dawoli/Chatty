#include <bits/stdc++.h>

using namespace std;
int nums[1000002];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	const int N = s.size();
	int n_index = 1;
	for (int i=0;i<=N-1;i++){
		if (s[i]>='0' && s[i] <='9'){
			nums[n_index] = (int)(s[i]-'0');
			n_index += 1;
		}
	}
	sort(nums+1,nums+n_index);
	for (int i=n_index-1;i>=1;i--){
		cout << nums[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
