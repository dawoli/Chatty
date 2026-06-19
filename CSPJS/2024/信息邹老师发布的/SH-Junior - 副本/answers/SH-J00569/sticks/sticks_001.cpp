#include <bits/stdc++.h>
using namespace std;
int t,n[55],shz[15],ba[55],yu[55];

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n[i];
	}
	shz[0]=6;
	shz[2]=1;
	shz[5]=2;
	shz[4]=4;
	shz[6]=6;
	shz[3]=7;
	for(int i=1;i<=t;i++){
		if(n[i]==1){
			ba[i]=-1;
			continue;
		}
		ba[i]=(n[i]-n[i]%7)/7;
		yu[i]=n[i]%7;
		if(ba[i]==0){
			yu[i]=shz[n[i]%7];
			continue;
		}
		if(yu[i]==1){
			yu[i]=10;
			ba[i]--;
		}else if(yu[i]==2){
			yu[i]=1;
		}else if(yu[i]==3){
			if(ba[i]==1){
				yu[i]=22;
				ba[i]--;
			}else{
				yu[i]=200;
				ba[i]-=2;
			}
		}else if(yu[i]==4){
			yu[i]=20;
			ba[i]--;
		}else if(yu[i]==5){
			yu[i]=2;
		}else if(yu[i]==6){
			yu[i]=6;
		}else if(yu[i]==0){
			yu[i]=0;
		}
	}
	for(int i=1;i<=t;i++){
		if(ba[i]==-1){
			cout << "-1"<<endl;
			continue;
		}
		if(yu[i]!=0){
			cout << yu[i];
		}
		for(int j=0;j<ba[i];j++){
			cout <<8;
		}
		cout << endl;
	}
	return 0;
}
