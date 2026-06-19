#include <bits/stdc++.h>
using namespace std;
int n,q,i,j,p,ans;
string s[200001][2];
int sbd[200001][3];
string t[200001][2];
int df,d1,d2;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for (i=0;i<n;i++){cin >> s[i][0] >> s[i][1]; 
		sbd[i][0]=s[i][0].find("b")-s[i][1].find("b");
		sbd[i][1]=s[i][0].find("b");
		sbd[i][2]=s[i][0].length()-sbd[i][1]-1;}
	for (i=0;i<q;i++)cin >> t[i][0] >> t[i][1];
	for (i=0;i<q;i++){
		ans=0;
		if (t[i][0].length()!=t[i][1].length()){cout << 0 << endl;continue;}
		d1=t[i][0].find("b");
		d2=t[i][1].find("b");
		df=d1-d2;
		for (p=0;p<n;p++){
			if (sbd[p][0]==df and sbd[p][1] <= d1 and sbd[p][2] <= t[i][0].length()-d1-1)ans++;
		}

		cout << ans << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

