#include <bits/stdc++.h>
using namespace std;
long long ans,n,m,i,o,p,k,q,j,ply,rd,l,rc1,rc2,rc3,rc4,t;
long long c,r;
int s[10000][50000];
int mis[100000][2];
int main(){
	cin >> t;
	for (rd=0;rd<t;rd++){
		cin >> n >> k >> q;
		for (i=0;i<n;i++){
			cin >> l;
			for (p=0;p<l;p++)cin >> s[i][p];
		}
		for (i=0;i<q;i++)cin >> mis[i][0] >> mis[i][1];
		for (i=0;i<q;i++){
			r,c = mis[i][0], mis[r][1];
			if (r==1){
				for (p=0;p<n;p++){
					rc1 = -1;
					rc2 = 0;
					for (o=0;o<n;o++){
						if (s[p][o] == 0)rc1 = o;
						if (s[p][o] == c and rc1 != -1){
							cout << 1 << endl;
							rc2 =1;
							break;
						}
					}
					if (rc2)break;
				}
				if (not rc2)cout << 0 << endl;
				continue;
			}
		}
	}
	return 0;
}

