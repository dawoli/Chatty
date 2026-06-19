#include<bits/stdc++.h>
using namespace std;
struct poker{
	char color,id;
}p[100];
int n,clen=0,ans = 0;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		bool t=0;
		cin >> s;
		char a = s[0];
		char b = s[1];
		if(i==0){
			p[clen].color = a;
			p[clen].id = b;
			clen++;
			ans++;
			continue; 
		}
		for(int j=0;j<clen;j++){
			if(p[j].color==a&&p[j].id==b){
				t = 1;
				break;
			}
		}
		if(!t){
			p[clen].color = a;
			p[clen].id = b;
			clen++;
			ans++;
		}
	}
	cout << 52-ans << endl;
	return 0;
} 
