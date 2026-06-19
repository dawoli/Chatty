#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,ans;
struct monster{
	int r;bool los;
}mon[N];
bool c(monster a,monster b){
	return a.r<b.r;
}
int main(){
	cin>>n;
	ans=n;
	for(int i=0;i<n;i++){
		cin>>mon[i].r;
	}
	sort(mon,mon+n,c);//从小到大排，田忌赛马 
	for(int i=1;i<n;i++){//挨个打别人
		for(int j=0;j<i;j++){
			if(mon[i].r>mon[j].r and not mon[j].los){//大打小
				mon[j].los=1;
				ans--;//赶走一个 
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
