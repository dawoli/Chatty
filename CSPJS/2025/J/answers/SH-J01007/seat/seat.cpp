#include<bits/stdc++.h>
using namespace std;

struct Stu{
	int num,id;
};

bool cmp(Stu a,Stu b){
	return a.num > b.num;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	vector<Stu> a;
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		int t;
		cin >> t;
		a.push_back({t,i});
	}
	sort(a.begin(),a.end(),cmp);
	int x=1,y=1;
	bool f=1;
	for(Stu it:a){
		if(it.id==1) break;
		if(f) y++;
		else y--;
		if(y>m) {
			y--,f=0,x++;
		}
		if(y<1){
			y++,f=1,x++;
		}
	}
	cout << x << " " << y;
}
