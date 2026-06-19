#include<bits/stdc++.h>
#define maxn 100005
#define ll long long int 
using namespace std;
int t,n,m,_l,_v,_cnt,no_used;
int _pp[maxn];
struct _dtl {
	ll _left=0,_right=0;
};
struct node {
	int _dis;
	int vcar;
	int a;
	int  _headspeed;
	int  _endspeed;
};
node cars_informa[maxn];
_dtl _used[maxn];
int _speedrea(int _xx) {
	return (1ll*_v*_v-1ll*pow(cars_informa[_xx].vcar,2))/cars_informa[_xx].a/2+cars_informa[_xx]._dis;
}
bool cmp(_dtl a,_dtl b) {
	if(a._left==b._left)return a._right<b._right;
	return a._left<b._left;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	for(int _u=1; _u<=t; _u++) {
		memset(_used,0,sizeof(_used));
		memset(cars_informa,0,sizeof(cars_informa));
		_cnt=0;
		cin>>n>>m>>_l>>_v;
		for( int i=1; i<=n; i++) {
			cin>>cars_informa[i]._dis>>cars_informa[i].vcar>>cars_informa[i].a;
			if(cars_informa[i].vcar>_v) {
				cars_informa[i]._headspeed=cars_informa[i]._dis;
			} else {
				if(cars_informa[i].vcar<=_v&&cars_informa[i].a<=0) {
					cars_informa[i]._headspeed=-1;
				} else {
					cars_informa[i]._headspeed=_speedrea(i)+1;
				}
			}
			if(cars_informa[i].vcar>=_v&&cars_informa[i].a<0) {
				cars_informa[i]._endspeed=_speedrea(i);
			} else if(cars_informa[i]._headspeed==-1) {
				cars_informa[i]._endspeed=-1;
			} else {
				cars_informa[i]._endspeed=10000000;
			}
		}
		for( int i=1; i<=m; i++) {
			cin>>_pp[i];
		}
		for( int i=1; i<=n; i++) {
			int _seefirst=-1;
			for( int j=1; j<=m; j++) {
				if(_pp[j]>=cars_informa[i]._headspeed&&_pp[j]<=cars_informa[i]._endspeed) {
					if(_seefirst==-1) {
						_used[i]._left=j;
						_seefirst=1;
						_cnt++;
					}
					_used[i]._right=j;
				}
			}
		}
		sort(_used+1,_used+n+1,cmp);
		int carsum=_cnt;
		int ii=1,used_all=0;
		while(carsum!=0&&ii<=n) {
			int	maxsum=-1,maxnum=1;
			if(_used[ii]._left==0&&_used[ii]._right==0) {
				ii++;
				continue;
			}
			for( int j=_used[ii]._left; j<=_used[ii]._right; j++) {
				int nowsum=1;
				for( int _yy=ii+1; _used[_yy]._left<=j&&_used[_yy]._right>=j; _yy++) {
					nowsum++;
				}
				if(nowsum>maxsum) {
					maxsum=nowsum;
					maxnum=j;
				}
			}
			carsum-=maxsum;
			for(ii; ii<=n; ii++) {
				if(_used[ii]._left>maxnum)
					break;
			}
			used_all++;
		}
		cout<<_cnt<<" "<<m-used_all<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

