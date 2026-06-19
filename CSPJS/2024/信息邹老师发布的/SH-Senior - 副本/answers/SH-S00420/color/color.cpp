#define mp(x, y) make_pair(x, y)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int N = 2e5 + 5;

int T;
int n;
ll a[N], dpt[N][2];
PII dp[N];


int main(){
	freopen("color.in","r", stdin);
	freopen("color.out","w", stdout);
	cin>> T;
	while(T--){
		cin>> n;
		for(int i = 1; i <= n; i++)
			cin>> a[i];
		for(int i = 1; i <= n; i++){
			for(int j = i - 1; j >= 1; j--){
				if(a[i] == a[j]){
					dpt[i][dp[j].second] = dp[i - 1].first + a[j];
					dpt[i][!dp[j].second] = dp[i - 1].first;
					
					if(dpt[i][1] > dpt[i][0])
						dp[i] = mp(dpt[i][1], 1);
					else
						dp[i] = mp(dpt[i][0], 0);				
					break;
				}
				else{
					dp[i] = dp[i - 1]; 
				}
			}
		}
		
		cout<< dp[n].first<< endl; 
	}
	return 0;
} 
