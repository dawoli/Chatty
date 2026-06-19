#include <bits/stdc++.h>
using namespace std;
bool a[60];
char t[2];
int main(){
	freopen("poker.in","r",stdin);freopen("poker.out","w",stdout);
	int n,cnt;
	cin>>n;
	
	for(int i=0;i<n;i++){
		cin >> t;
		
		a[(t[0]=='D'?0:(t[0]=='C'?1:(t[0]=='H'?2:3)))*13+(t[1]=='A'?0:(t[1]=='T'?9:(t[1]=='J'?10:(t[1]=='Q'?11:(t[1]=='K'?12:t[1]-'0'-1)))))]=true;
		//cout << t<<(t[0]=='D'?0:(t[0]=='C'?1:(t[0]=='H'?2:3)))*13+(t[1]=='A'?0:(t[1]=='T'?9:(t[1]=='J'?10:(t[1]=='Q'?11:(t[1]=='K'?12:t[1]-'0'-1)))))<<endl;
	}
	for(int i=0;i<52;i++){
		if(a[i]){
			cnt++;
		}
	}
	cout << 52-cnt;
	return 0;
} 
