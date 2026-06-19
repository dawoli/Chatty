#include <bits/stdc++.h> 
using namespace std;


inline int read(){
	int x=0,f=1;
	char ch;
	ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int t;


int n;
struct man{
	int a,b,c,px;
};
man ba[100005];
bool cmp(man x,man y){
	return x.px>y.px;
}
int ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read(); 
	while(t--){
		ans=0;
		n=read();
		for(int i=0;i<n;i++){
			ba[i].a=read();
			ba[i].b=read();
			ba[i].c=read();
			ba[i].px=max(ba[i].a,max(ba[i].b,ba[i].c))*2+min(ba[i].a,min(ba[i].b,ba[i].c))-ba[i].a-ba[i].b-ba[i].c;
		//	ba[i].px=max(ba[i].a,max(ba[i].b,ba[i].c))*2-min(ba[i].a,max(ba[i].b,ba[i].c));
			
		//	ba[i].px=max(ba[i].a,max(ba[i].b,ba[i].c))*2-ba[i].a-ba[i].b- ba[i].c; 
		}
		sort(ba,ba+n,cmp);
		int cnta=0,cntb=0,cntc=0;
		for(int i=0;i<n;i++){
			man u=ba[i];
			if(cnta>=n/2){
				u.a=-1;
			}
			if(cntb>=n/2){
				u.b=-1;
			}
			if(cntc>=n/2){
				u.c=-1;
			}
		//	cout<<"u:";
		//	cout<<u.a<<" "<<u.b<<" "<<u.c<<" "<<u.px<<endl;
			int _max=max(u.a,max(u.b,u.c));
			ans+=_max;
			if(_max==u.a){
				cnta++;
			} else if(_max==u.b){
				cntb++;
			} else if(_max==u.c){
				cntc++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522



30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062




30
9478 19118 8151
13734 12377 2590
17271 16865 12064
18865 15914 6583
17881 2606 1461
7661 10745 2015
5626 1 13811
17093 17920 9103
1260 5941 6956
7029 8181 9418
16277 13988 354
14474 15227 4982
18507 16641 9235
16900 4898 4480
1289 3301 13793
19466 18556 6597
8834 261 19131
19944 18987 9560
14166 7854 1087
16689 3937 4380
18836 4342 18874
1751 16536 17990
10936 3627 1271
12006 16719 4693
12954 6746 5867
17098 16955 4125
18143 8067 2266
14889 8692 60
14736 14274 10644
16270 7210 3708
*/
