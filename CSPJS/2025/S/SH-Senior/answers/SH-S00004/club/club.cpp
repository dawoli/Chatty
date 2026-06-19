#include<bits/stdc++.h>
using namespace std;
int t,n;
struct node{
	int s1,s2,s3,sx;
	int total;
}s[100005];
bool cmp(node x,node y){
	return x.s2 > y.s2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		int k = n / 2; 
		int flag = 0;
		for(int i=1;i<=n;i++){
			cin >> s[i].s1 >> s[i].s2 >> s[i].s3;
			if(s[i].s1 == 0 && s[i].s3 == 0) flag++; 
			s[i].sx = max(s[i].s1,max(s[i].s2,s[i].s3));
		}
		int ans = 0;
		if(flag == n){
			sort(s + 1,s + n + 1,cmp);
			int sum = 0;
			for(int i=1;i<=n;i++){
				if(sum == k) break;
				ans += s[i].s2;
				sum++;
			}
			
		}
		else{
			for(int i=1;i<=n;i++){
				ans += s[i].sx;
			}
		}
		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0 
*/

