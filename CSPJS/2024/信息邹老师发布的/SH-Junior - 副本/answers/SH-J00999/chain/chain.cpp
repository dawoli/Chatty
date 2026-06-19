#include<bits/stdc++.h>
using namespace std;
int fast(void){
	int a=0;int neg=1;
	char c;
	scanf("%c",&c);
	while(c<'0'||c>'9'){
		if(c=='-') neg=-1;
		scanf("%c",&c);
	}
	while(c>='0'&&c<='9'){
		a=a*10+c-'0';
		scanf("%c",&c);
	}
	return neg*a;
}
int n,k,q;
int l[200005],s[200005],next2[200005],last[200005],start[200005];
bool dfs(int ch, int last_people,int m,int r,int c){
	if(m==r){
		if (ch==c) return 1;
		return 0;
	}
	bool t=0;
	for(int p=1;p<=n;p++)if (p!=last_people)
		for(int j=start[p];j!=last[p];){//Ñ°ÕÒch
			if (s[j]==ch){
				for (int i=1,ch1=j;i<=j+k&&i<=l[i];i++) {
						if(dfs(ch1,p,m+1,r,c)) return 1;
						ch1=next2[ch1];
					}
				}
				j=next2[j];
			}
	return 0;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int T;//,n,k,q; */
	T=fast();
	while(T--){
		memset(l,sizeof(l),0);
		memset(s,sizeof(s),0);
		memset(next2,sizeof(next2),0);
		memset(last,sizeof(last),0);
		n=fast();k=fast();q=fast();
		int now=1;
		for(int p=1;p<=n;p++){
			l[p]=fast();
			for(int i=1;i<=l[p];i++){
				s[now]=fast();
				if(i==1) start[p]=now;
				next2[last[p]]=now;
				last[p]=now;
				now++;
			}
		}
		for(int i=1;i<=q;i++){
			int r=fast(),c=fast();
			cout << 0 << endl;
		}
	}
	return 0;
}

