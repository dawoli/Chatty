#include<bits/stdc++.h>
#define N 200099
using namespace std;
int T;
int a[N];
int score;


int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);	
	cin>>T;
	for(int gg=1;gg<=T;gg++){
		cin>>n;
		score=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=2 and a[i]==a[i-1]){
				score+=a[i];
			}
		}
		cout<<score<<endl;

	}


	return 0;
}

