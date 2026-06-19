#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct SS{
	string s[2];
	int pos[2],dif,x,y;
	int ls;
}S[MAXN];
struct TT{
	string t[2];
	int pos[2],dif,x,y,idx;
	int lt;
}T[MAXN];

bool cmp(SS s1, SS s2){
	if(s1.dif==s2.dif){
		if(s1.x == s2.x) return s1.y<s2.y;
		return s1.x<s2.x;
	}
	return s1.dif<s2.dif;
}
bool cmp2(TT s1, TT s2){
	if(s1.dif==s2.dif){
		if(s1.x == s2.x) return s1.y<s2.y;
		return s1.x<s2.x;
	}
	return s1.dif<s2.dif;
}

bool cmp3(SS s1,SS s2){
	return s1.ls > s2.ls;
}

int n,q;
bool check(string ss,int l){
	int cnta=0,cntb=0;
	for(int i=0;i<l;++i){
		char c=ss[i];
		if(c=='a') cnta++;
		else if(c=='b') cntb++;
		else return 0;
	}
	if(cntb==1) return 1;
	return 0;
}
int ans[MAXN];

int pos[MAXN][2];
int calcpos(string ss,int l){
	for(int i=0;i<l;++i){
		char c=ss[i];
		if(c=='b') return i;
	}
}
void solveB(){
	for(int i=1;i<=n;++i){
		S[i].pos[0]=calcpos(S[i].s[0],S[i].ls);
		S[i].pos[1]=calcpos(S[i].s[1],S[i].ls);
		S[i].dif=S[i].pos[0]-S[i].pos[1];
		S[i].x=S[i].pos[0]-S[i].dif;
		S[i].y=S[i].ls-S[i].x-1-S[i].dif;
	}
	for(int i=1;i<=q;++i){
		T[i].pos[0]=calcpos(T[i].t[0],T[i].lt);
		T[i].pos[1]=calcpos(T[i].t[1],T[i].lt);
		T[i].dif=T[i].pos[0]-T[i].pos[1];
		T[i].x=T[i].pos[0]-T[i].dif;
		T[i].y=T[i].lt-T[i].x-1-T[i].dif;
	}
	sort(S+1,S+1+n,cmp);
	sort(T+1,T+1+q,cmp2);
	int pp=1,qq=1,lastp;
	while(qq<=q){
		lastp=pp;
		while(S[pp].dif<T[qq].dif && pp<=n) pp++;
		if(pp>n || S[pp].dif>T[qq].dif){
			ans[T[qq].idx]=0;
			qq++;
			continue;
		}
		if(pp==lastp){
			for(int i=pp;S[i].dif==T[qq].dif && S[i].x<=T[qq].x;++i){
				if(S[i].y<=T[qq].y) ans[T[qq].idx]++;
			}
		}
		else{
			lastp=pp;
			for(int i=pp;S[i].dif==T[qq].dif && S[i].x<=T[qq].x;++i){
				if(S[i].y<=T[qq].y) ans[T[qq].idx]++;
			}
		}
		qq++;
	}
	for(int i=1;i<=q;++i) cout << ans[i] << endl;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin >> n >> q;
	for(int i=1;i<=n;++i){
		cin >> S[i].s[0] >> S[i].s[1];
	}
	for(int i=1;i<=q;++i){
		cin >> T[i].t[0] >> T[i].t[1];
	}
	bool flag=1;
	for(int i=1;i<=n;++i){
		S[i].ls=S[i].s[0].length();
		flag&=check(S[i].s[0],S[i].ls);
		flag&=check(S[i].s[1],S[i].ls);
	}
	for(int i=1;i<=q;++i){
//		ans[i]=-1;
		T[i].lt=T[i].t[0].length();
		flag&=check(T[i].t[0],T[i].lt);
		int tmp=T[i].t[1].length();
		flag&=check(T[i].t[1],T[i].lt);
		if(T[i].lt!=tmp) ans[i]=0;
		T[i].idx=i;
	}
	if(flag){
		solveB();
	}
	else{
		for(int i=1;i<=q;++i){
			int anss=0;
			int fails=T[i].lt,faile=-1;
			for(int k=0;k<T[i].lt;++k){
				if(T[i].t[0][k]!=T[i].t[1][k]){
					fails=min(fails,k);
					faile=max(faile,k);
				}
			}
			int rep=faile-fails+1;
			sort(S+1,S+1+n,cmp3);
			for(int j=1;j<=n;++j){
				bool flag=1;
				if(S[j].ls<rep) break;
				for(int k=max(faile+1-S[j].ls,0);k<=fails;++k){
//					cout << k << "@" << endl;
					for(int pp=0;pp<S[j].ls;++pp){
//						cout << pp << ' ' << k+pp << endl;
						if(k+pp<fails || k+pp>faile){
							if(S[j].s[0][pp]!=S[j].s[1][pp] || S[j].s[0][pp]!=T[i].t[0][k+pp]){
								flag=0;
//								cout << "!" << S[j].s[0][pp] << S[j].s[1][pp] << T[i].t[0][k+pp] << T[i].t[1][k+pp] << endl;
								break;
							}
						}
						else{
							if(S[j].s[0][pp]!=T[i].t[0][k+pp] || S[j].s[1][pp]!=T[i].t[1][k+pp]){
								flag=0;
								break;
							}
						}
					}
					if(flag) anss++;
				}
				
//				cout << flag << S[j].s[0] << "!" << endl;
			}
			cout << anss << endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
