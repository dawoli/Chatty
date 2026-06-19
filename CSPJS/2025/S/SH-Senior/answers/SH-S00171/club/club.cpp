#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5+10;
int n;
int a[N][4];
int fir[N],sec[N],thi[N],cha[N];
void f(int q){
	int b = -1;
	if (a[q][1] > b){
		b = a[q][1];
		fir[q]=1;
	}
	if (a[q][2] > b){
		b = a[q][2];
		fir[q]=2;
	}
	if (a[q][3] > b){
		b = a[q][3];
		fir[q]=3;
	}
	if(fir[q] == 1){
        if(a[q][2] > a[q][3]){
            sec[q] = 2;
        }
        else{
            sec[q] = 3;
        }
	}
	if(fir[q] == 2){
        if(a[q][1] > a[q][3]){
            sec[q] = 1;
        }
        else{
            sec[q] = 3;
        }
	}
	if(fir[q] == 3){
        if(a[q][2] > a[q][1]){
            sec[q] = 2;
        }
        else{
            sec[q] = 1;
        }
	}
	cha[q] = a[q][fir[q]]-a[q][sec[q]];
}
int cnt[4];
bool cmp(int x,int y){
    return x < y;
}
int main(){
	
	freopen("club.in","w",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--){
        memset(cnt,0,sizeof(cnt));
        memset(fir,0,sizeof(fir));
        memset(sec,0,sizeof(sec));
        memset(thi,0,sizeof(thi));
        memset(cha,0,sizeof(cha));
        memset(a,0,sizeof(a));
		cin >> n;
		int ans = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			f(i);
		}
		for (int i = 1;i <= n;i++){
            cnt[fir[i]]++;
            ans += a[i][fir[i]];
		}
		//judge
		for (int k = 1;k <= 3;k++){
            if (cnt[k] > n/2){
                int aaa = cnt[k]-n/2;
                for (int i = 1;i <= n;i++){
                    if (fir[i] != k){ //move
                        cha[i] = 10000000;
                    }
                }
                sort(cha+1,cha+n+1,cmp);
                for (int i = 1;i <= aaa;i++){
                    ans -= cha[i];
                }
                break;
            }
		}
		cout << ans << endl;
	}
	return 0;
}
/*
3 4
4 2 1
3 2 4
5 3 4
3 5 1
ans:13





*/
