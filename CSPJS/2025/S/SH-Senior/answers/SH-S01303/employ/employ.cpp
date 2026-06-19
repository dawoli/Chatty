#include <bits/stdc++.H>
using namespace std;
int n,m;
const int Mo = 998244353;
const int N = 500 + 10;
string s1;
int c[N];
int te;
int leng;
int suan = 1;
bool jian;
bool jian2;
bool jian3;
bool jian4;
int tongji;
int tongji2;
int maxnci;
void f(int x){
	for(int i = 1;i <= x;i++){
		suan *= i;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	te = true;
	leng = n;
	for(int i = 1;i <= n;i++){
		cin >> s1[i];
		if(s1[i] != '1'){
			te = false;
		}
	}
	for(int i = 1;i <= n;i++){
		cin >> c[i];
	}
	if(m==n){
		for(int i = 1;i <= n;i++){
			if(c[i]==0 or s1[i] == '0'){
				cout << 0;
				jian = true;
			}
		}
		if(!jian){
			f(n);
			cout << suan % Mo;
		}
	}else if(m == 1){
		for(int i = 1;i <= n;i++){
			if(s1[i] != '0'){
				jian3 = true;
				tongji++;
			}
			if(c[i] != 0){
				if(c[i] > maxnci){
					maxnci = c[i];
				}
				jian4 = true;
				tongji2++;
			}
		}
		if(jian3 and jian4){
			if((n - tongji2)>maxnci){
				cout << 1;
			}else{
				f(n);
				cout << suan % Mo;
			}
		}else{
			cout << 0;
		}
	}else if(te){
		for(int i = 1;i <= n;i++){
			if(s1[i] != '0'){
				tongji++;
			}
			if(c[i] != 0){
				if(c[i] > maxnci){
					maxnci = c[i];
				}
				tongji2++;
			}
		}
		f(n);
		cout << suan % Mo;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
