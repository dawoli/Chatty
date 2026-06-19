#include <bits/stdc++.h>
using namespace std;
long long ans,n,i,p,inp1,last;
string pai[52];
char inp[2];
bool flag;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	for (i=0;i<52;i++)pai[i] = "";
	ans=0;
	last =0;
	cin >> n;
	ans = 52-n;
	for (i=0;i<n;i++){
		cin >> inp;
		flag = false;
		for (p=0;p<last;p++){
			if (inp == pai[p]){
				flag = true;
				break;
			}
		}
		if (not flag){
			pai[last] = inp;
			last++;
		}
		if (flag)ans++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 
