#include <bits/stdc++.h>
using namespace std;
struct number {
	int val;
	bool c;
} num[20];
int n;
int main() {
	
	int T;
	cin >> T;
	while (T--) {
		cin >> n;
		for (int i=1; i<=n; i++) {
			cin >> num[i].val;
		}
		if (n==2) {
			if (num[1].val==num[2].val) cout << num[1].val;
			else cout << 0;
			return 0;
		}
		int maxn=-1;
		if (n==15) {
			for (int i=0; i<=1; i++) {
				for (int j=0; j<=1; j++) {
					for (int k=0; k<=1; k++) {
						for (int l=0; l<=1; l++) {
							for (int m=0; m<=1; m++) {
								for (int o=0; o=1; o++) {
									for (int p=0; p<=1; p++) {
										for (int q=0; q<=1; q++) {
											for (int r=0; r<=1; r++) {
												for (int s=0; s<=1; s++) {
													for (int t=0; t<=1; t++) {
														for (int u=0; u<=1; u++) {
															for (int v=0; v<=1; v++) {
																for (int w=0; w<=1; w++) {
																	for (int z=0; z<=1; z++) {
																		num[1].c=i;
																		num[2].c=j;
																		num[3].c=k;
																		num[4].c=l;
																		num[5].c=m;
																		num[6].c=o;
																		num[7].c=p;
																		num[8].c=q;
																		num[9].c=r;
																		num[10].c=s;
																		num[11].c=t;
																		num[12].c=u;
																		num[13].c=v;
																		num[14].c=w;
																		num[15].c=z;
																		int sum=0;
																		for (int uwu=2;uwu<=15;uwu++){
																			for (int i_=uwu;i_>=1;i_--){
																				if (num[uwu].c==num[i_].c){
																					if (num[uwu].val==num[i_].val){
																						sum+=num[uwu].val;
																					}
																					else sum+=0;
																				}
																			}
																		}
																		if (sum>maxn){
																			maxn=sum;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		cout << maxn;
	}
return 0;
}

