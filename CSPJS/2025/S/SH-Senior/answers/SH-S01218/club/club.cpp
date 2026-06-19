#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
struct Node{
	int a,b,c;
}s[N];
bool check(int a,int b,int c){
	if(a >= b&&a >= c) return true;
}
int ans;
int ido[N],idt[N],ide[N],minn[N];
int flago, flage, flagt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	for(int i = 1;i <= t;i++){
		int n;
		cin >> n;
		flago = 0;
		flagt = 0;
		flage = 0;
		ans = 0;
		memset(ido,0,sizeof(ido));
		memset(idt,0,sizeof(idt));
		memset(ide,0,sizeof(ide));
		for(int j = 1;j <= n;j++){
			cin >> s[j].a >> s[j].b >> s[j].c;
			if(check(s[j].a,s[j].b,s[j].c)) {
				flago++;
				ans += s[j].a;
				ido[flago] = j; 
			}
			else if(check(s[j].b,s[j].a,s[j].c)){
				flagt++;
				ans += s[j].b;
				idt[flagt] = j;
			}
			else {
				flage++;
				ans += s[j].c;
				ide[flage] = j;
			}
		}
		memset(minn,0,sizeof(minn));
		if(flago > n/2){
			for(int j = 1;j <= flago;j++){
				minn[j] = s[ido[j]].a - max(s[ido[j]].b,s[ido[j]].c);
			}
			sort(minn+1,minn+flago+1);
			for(int j = 1;j <= flago-n/2;j++){
				ans -= minn[j];
			}
		}
		else if(flagt > n/2){
			for(int j = 1;j <= flagt;j++){
				minn[j] = s[idt[j]].b - max(s[idt[j]].a,s[idt[j]].c);
			}
			sort(minn+1,minn+flagt+1);
			for(int j = 1;j <= flagt-n/2;j++){
				ans -= minn[j];
			}
		}
		else if(flage > n/2){
			for(int j = 1;j <= flage;j++){
				minn[j] = s[ide[j]].c - max(s[ide[j]].b,s[ide[j]].a);
			}
			sort(minn+1,minn+flage+1);
			for(int j = 1;j <= flage-n/2;j++){
				ans -= minn[j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
