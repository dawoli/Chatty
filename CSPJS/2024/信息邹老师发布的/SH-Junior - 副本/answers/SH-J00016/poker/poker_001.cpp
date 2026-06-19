#include<bits/stdc++.h>
using namespace std;
int n, cnt;
struct poke{
	char a;
	char b;
}N[52];
int main(){
    freopen("poker.in", "r", stdin);
	freopen("poker.out", "w", stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>N[i].a>>N[i].b;
		for(int j=0;j<52;j++){
			if(N[i].a==N[j].a&&N[i].b==N[j].b&&j!=i){
				N[i].a='0';
				N[i].b='0';
			}
		}
	}
	for(int i=0;i<52;i++){
		if(N[i].b!='A'&&N[i].b!='2'&&N[i].b!='3'&&N[i].b!='4'&&N[i].b!='5'&&N[i].b!='6'&&N[i].b!='7'&&N[i].b!='8'&&N[i].b!='9'&&N[i].b!='T'&&N[i].b!='J'&&N[i].b!='Q'&&N[i].b!='K'&&N[i].b!='0'){
			cnt++;
		}
	}
	for(int i=0;i<52;i++){
		if(N[i].b=='0'&&N[i].a=='0'){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
