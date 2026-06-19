//40
#include<bits/stdc++.h>
using namespace std;
class ERR1 {};
bool good[1005][1005];
int n,m,k;
struct robot {
	int x,y,d,s=1;
	static void _upd(int d,int & x,int & y) {
		switch(d) {
			case 0: {
				y++;
				break;
			}
			case 1: {
				x++;
				break;
			}
			case 2: {
				y--;
				break;
			}
			case 3: {
				x--;
				break;
			}
			default: {
				throw ERR1();
			}
		}
	}
	void turn_right() {
		d=(d+1)%4;
	}
	void upd() {
		//cout<<'('<<x<<','<<y<<')'<<endl;
		int tx=x,ty=y;
		_upd(d,tx,ty);
		if(!(1<=tx&&tx<=n&&1<=ty&&ty<=m&&good[tx][ty])) {
			turn_right();
			cout<<1<<endl;
		}
		else {
			x=tx;
			y=ty;
			s++;
			cout<<2<<endl;
		}
		//cout<<'('<<x<<','<<y<<')'<<endl;
	}
};
int main() {
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++) {
		memset(good,0,sizeof good);
		cin>>n>>m>>k;
		for(int j=1;j<=n;j++) {
			for(int K=1;K<=n;K++) {
				char tmp;
				cin>>tmp;
				good[j][K]=(tmp=='.');
			}
		}
		robot r;
		cin>>r.x>>r.y>>r.d;
		r.upd();
	}
	return 0;
}
