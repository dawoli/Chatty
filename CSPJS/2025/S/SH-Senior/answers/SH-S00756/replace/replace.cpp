#include<bits/stdc++.h>
using namespace std;
int n,q,l1,l2,cnt;
string s1[200010],s2[200010];
string t1,t2;
bool check1(int r,int t){
	int cnt3 = 0;
	bool f = false;
	for(int i = t;i < l1;i++){
		if(f){
			if(t1[i] != t2[i]){
//				cout <<3 << endl;
				return false;
			}
		}
		if(!f){
			if(t1[i] != s1[r][cnt3]){
//				cout <<p[i] <<" " <<o[cnt1] <<endl;
				return false;
			}
			if(s2[r][cnt3] != t2[i]){
//				cout <<2 <<endl;
				return false;
			}
			cnt3++;
			if(cnt3 == s1[r].length()){
				f = true;
			}
		}
	}
	return true;
}
int check(int r){
//	cout <<o <<" " <<p <<endl;
	int cnt1 = 0,cnt2 = 0;
//	bool f = false;
	for(int i = 0;i < l1;i++){
		if(t1[i] == s1[r][0] && s2[r][0] == t2[i]){
//			cout <<i <<endl;
			if(check1(r,i)){
				cnt2++;
			}
			else if(t1[i] != t2[i]){
				break;
			}
		}
		else if(t1[i] != t2[i]){
			break;
		}
	}
	return cnt2;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i = 1;i <= n;i++){
		cin >> s1[i] >>s2[i];
	}
	for(int i = 1;i <= q;i++){
		cin >> t1 >> t2;
		l1 = t1.length();
		l2 = t2.length();
		cnt = 0;
		if(l1 != l2){
			printf("0\n");
			continue;
		}
		for(int k = 1;k <= n;k++){
			int cnt1 = 0,cnt2 = 0;
//	bool f = false;
			for(int j = 0;j < l1;j++){
				if(t1[j] == s1[k][0] && s2[k][0] == t2[j]){
//			cout <<i <<endl;
					if(check1(k,j)){
						cnt2++;
					}
					else if(t1[j] != t2[j]){
						break;
					}
				}
				else if(t1[j] != t2[j]){
					break;
				}
			}
			cnt += cnt2;
//			cout <<cnt <<endl;
		}
//		cout <<i<<endl;
		printf("%d\n",cnt);
	}
	return 0;
}
