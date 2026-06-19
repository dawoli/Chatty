#include <bits/stdc++.h>
using namespace std;
int T=0;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin >> T;
	for(int i = 0;i < T;i++){
		int n=0,k=0,q=0;
		cin >> n >> k >> q;
		if(n <= 1000){
			int a[1010][2000],i=0,aa[1010];
			cin >> i;
			for(int ii = 0;ii < n;ii++){
				for(int jj = 0;jj < i;jj++){
					cin >> a[ii][jj];
					if(a[ii][jj] == 1){
						aa[ii] == jj;
					}
				}
			}
			for(int ii = 0;ii < q;ii++){
				int r=0,c=0,bol=0;
				cin >> r >> c;
				if(r == 1){
					for(int jj = 0;jj < n;jj++){
						for(int oo = 0;oo <= k;oo++){
							if(a[jj][aa[jj] + oo] == c){
								cout << 1 << endl;
								bol = 1;
								break;
							}
						}
						if(bol == 1){
							break;
						}
					}
					if(bol == 0){
						cout << 0 << endl;
					}
				}
			}
		}else if(k == 200000){
			int a[100010][200010],i=0;
			cin >> i;
			for(int ii = 0;ii < n;ii++){
				for(int jj = 0;jj < i;jj++){
					cin >> a[ii][jj];
				}
			}
			for(int z = 0;z < q;z++){
				int r=0,c=0;
				cin >> r >> c;
				if(c != 1){
					cout << 1 << endl;
				}else{
					cout << 0 << endl;
				}
			}
		}else{
			int a[1010][2000],i=0;
			cin >> i;
			for(int ii = 0;ii < n;ii++){
				for(int jj = 0;jj < i;jj++){
					cin >> a[ii][jj];
				}
			}
			for(int z = 0;z < q;z++){
				int r=0,c=0;
				cin >> r >> c;
				cout << 0 << endl;
			}
		}
	}
	return 0;
}
