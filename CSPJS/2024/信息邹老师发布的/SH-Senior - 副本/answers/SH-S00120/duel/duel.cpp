#include<bits/stdc++.h>
using namespace std;
int n;
int _blod[100005],_cnt;
int _smalestdata,_smalestnum;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	_cnt=n;
	for(int i=1;i<=n;i++){
		cin>>_blod[i];
	}
	sort(_blod+1,_blod+n+1);
	_smalestdata=_blod[1];
	_smalestnum=1;
	for(int i=1;i<=n-1;i++){
		if(_blod[i+1]>_smalestdata){
			_cnt--;
			_smalestdata=_blod[++_smalestnum];
		}
	}
	cout<<_cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
