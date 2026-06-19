#include <iostream>

using namespace std;

int atks[100005],attacked;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		int temp;
		cin >> temp;
		atks[temp]++;
	}
	for(int i=1;i<=100003;i++){
		if(attacked<=atks[i])attacked=atks[i];
	}
	cout << attacked;
	return 0; 
}
