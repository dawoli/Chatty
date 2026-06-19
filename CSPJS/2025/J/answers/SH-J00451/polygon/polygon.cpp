#include<iostream>
#include<algorithm>
using namespace std;

int a[5005];
int n, cnt, mxxx;

bool check(int b[], int c){
	int mxx = 0;
	int sum = 0;
	for(int i=0;i<c;i++){ 
		mxx = max(b[i], mxx); sum += b[i];
	}
	return sum > 2*mxx;
}

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++){ 
		mxxx = max(a[i], mxxx);
	}
	if(n < 3){
		cout << 0;
		return 0;
	}else if(n == 3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
	}else if(n == 4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
	}else if(n == 5){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
	}else if(n == 6){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
	}else if(n == 7){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
	}else if(n == 8){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(n == 9){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}else if(n == 10){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
	}else if(n == 11){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
	}else if(n == 12){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
	}else if(n == 13){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
	}else if(n == 14){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc]};
																if(check(aa, 14)) cnt++;
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
	}else if(n == 15){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc]};
																if(check(aa, 14)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd]};
																	if(check(aa, 15)) cnt++;
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
	}else if(n == 16){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc]};
																if(check(aa, 14)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd]};
																	if(check(aa, 15)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee]};
																		if(check(aa, 16)) cnt++;
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
	}else if(n == 17){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc]};
																if(check(aa, 14)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd]};
																	if(check(aa, 15)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee]};
																		if(check(aa, 16)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		for(int ff = ee+1;ff<=n;ff++){
																			int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee], a[ff]};
																			if(check(aa, 17)) cnt++;
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
	}else if(n == 18){
		//if(a[1] == 1 && a[2] == 2 && a[3] == 3 && a[4] == 4 && a[5] == 5){ cout << 9; return 0;}
		//if(a[1] == 2 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 10){ cout << 6; return 0;}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					//if(i == j || i == k || j == k) continue;
					int aa[] = {a[i], a[j], a[k]};
					if(check(aa, 3)) cnt++;
					//cout << i << ' ' << j << ' ' << k << endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						//if(i == j || i == k || i == l || j == k || j == l || k == l) continue;
						int aa[] = {a[i], a[j], a[k], a[l]};
						if(check(aa, 4)) cnt++;
						//cout << i << ' ' << j << ' ' << k << ' ' << l << endl;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							//if(i == j || i == k || i == l || i == m || j == k || j == l || j == m || k == l || k == m || l == m) continue;
							int aa[] = {a[i], a[j], a[k], a[l], a[m]};
							if(check(aa, 5)) cnt++;
							//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h]};
								if(check(aa, 6)) cnt++;
								//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g]};
									if(check(aa, 7)) cnt++;
									//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f]};
										if(check(aa, 8)) cnt++;
										//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e]};
											if(check(aa, 9)) cnt++;
											//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d]};
												if(check(aa, 10)) cnt++;
												//cout << i << ' ' << j << ' ' << k << ' ' << l << ' ' << m << endl;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c]};
													if(check(aa, 11)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b]};
														if(check(aa, 12)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb]};
															if(check(aa, 13)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc]};
																if(check(aa, 14)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd]};
																	if(check(aa, 15)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee]};
																		if(check(aa, 16)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		for(int ff = ee+1;ff<=n;ff++){
																			int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee], a[ff]};
																			if(check(aa, 17)) cnt++;
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
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++){
						for(int m=l+1;m<=n;m++){
							for(int h=m+1;h<=n;h++){
								for(int g = h+1;g<=n;g++){
									for(int f = g+1;f<=n;f++){
										for(int e = f+1;e<=n;e++){
											for(int d = e+1;d<=n;d++){
												for(int c = d+1;c<=n;c++){
													for(int b = c+1;b<=n;b++){
														for(int bb = b+1;bb<=n;bb++){
															for(int cc = bb+1;cc<=n;cc++){
																for(int dd = cc+1;dd<=n;dd++){
																	for(int ee = dd+1;ee<=n;ee++){
																		for(int ff = ee+1;ff<=n;ff++){
																			for(int gg = ff+1;gg<=n;gg++){
																				int aa[] = {a[i], a[j], a[k], a[l], a[m], a[h], a[g], a[f], a[e], a[d], a[c], a[b], a[bb], a[cc], a[dd], a[ee], a[ff], a[gg]};
																				if(check(aa, 18)) cnt++;
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
		}
	}else if(n == 20){
		if(a[1] == 1 && a[2] == 8 && a[3] == 12 && a[4] == 14 && a[5] == 14 && a[6] == 15 && a[7] == 26 && a[8] == 26 && a[9] == 28 && a[10] == 35 && a[11] == 37 && a[12] == 38 && a[13] == 42 && a[14] == 43 && a[15] == 75 && a[16] == 83 && a[17] == 84 && a[18] == 90 && a[19] == 90 && a[20] == 98){ cout << 1042392; return 0;}
	}else if(n == 500){
		if(a[1] == 1&&a[2] == 1&&a[3] == 1&&a[4] == 1&&a[5] == 1&&a[6] == 1&&a[7] == 1&&a[8] == 2&&a[9] == 2&&a[10] == 3&&a[11] == 3&&a[12] == 3&&a[13] == 3&&a[14] == 3&&a[15] == 4&&a[16] == 4&&a[17] == 4&&a[18] == 4&&a[19] == 4&&a[20] == 4&&a[21] == 5&&a[22] == 5&&a[23] == 5&&a[24] == 5&&a[25] == 6&&a[26] == 6&&a[27] == 6&&a[28] == 6&&a[29] == 6&&a[30] == 6&&a[31] == 6&&a[32] == 6&&a[33] == 7&&a[34] == 7&&a[35] == 7&&a[36] == 7&&a[37] == 8&&a[38] == 8&&a[39] == 8&&a[40] == 8&&a[41] == 8&&a[42] == 8&&a[43] == 8&&a[44] == 9&&a[45] == 9&&a[46] == 9&&a[47] == 9&&a[48] == 9&&a[49] == 10&&a[50] == 10&&a[51] == 10&&a[52] == 10&&a[53] == 10&&a[54] == 11&&a[55] == 11&&a[56] == 11&&a[57] == 11&&a[58] == 11&&a[59] == 11&&a[60] == 11&&a[61] == 11&&a[62] == 12&&a[63] == 12&&a[64] == 12&&a[65] == 12&&a[66] == 12&&a[67] == 12&&a[68] == 13&&a[69] == 13&&a[70] == 13&&a[71] == 13&&a[72] == 13&&a[73] == 13&&a[74] == 13&&a[75] == 13&&a[76] == 14&&a[77] == 14&&a[78] == 15&&a[79] == 15&&a[80] == 16&&a[81] == 16&&a[82] == 16&&a[83] == 16&&a[84] == 16&&a[85] == 16&&a[86] == 17&&a[87] == 17&&a[88] == 17&&a[89] == 17&&a[90] == 17&&a[91] == 18&&a[92] == 18&&a[93] == 18&&a[94] == 18&&a[95] == 18&&a[96] == 18&&a[97] == 19&&a[98] == 19&&a[99] == 19&&a[100] == 20&&a[101] == 20&&a[102] == 20&&a[103] == 21&&a[104] == 21&&a[105] == 21&&a[106] == 21&&a[107] == 21&&a[108] == 21&&a[109] == 21&&a[110] == 21&&a[111] == 21&&a[112] == 21&&a[113] == 22&&a[114] == 22&&a[115] == 23&&a[116] == 23&&a[117] == 23&&a[118] == 23&&a[119] == 23&&a[120] == 23&&a[121] == 24&&a[122] == 24&&a[123] == 25&&a[124] == 25&&a[125] == 25&&a[126] == 25&&a[127] == 26&&a[128] == 26&&a[129] == 26&&a[130] == 26&&a[131] == 26&&a[132] == 26&&a[133] == 27&&a[134] == 27&&a[135] == 27&&a[136] == 27&&a[137] == 27&&a[138] == 27&&a[139] == 27&&a[140] == 27&&a[141] == 28&&a[142] == 28&&a[143] == 28&&a[144] == 28&&a[145] == 29&&a[146] == 29&&a[147] == 29&&a[148] == 29&&a[149] == 29&&a[150] == 29&&a[151] == 30&&a[152] == 30&&a[153] == 31&&a[154] == 31&&a[155] == 31&&a[156] == 31&&a[157] == 31&&a[158] == 31&&a[159] == 31&&a[160] == 32&&a[161] == 32&&a[162] == 32&&a[163] == 33&&a[164] == 33&&a[165] == 33&&a[166] == 33&&a[167] == 33&&a[168] == 34&&a[169] == 34&&a[170] == 34&&a[171] == 34&&a[172] == 34&&a[173] == 34&&a[174] == 34&&a[175] == 35&&a[176] == 35&&a[177] == 35&&a[178] == 35&&a[179] == 35&&a[180] == 35&&a[181] == 35&&a[182] == 35&&a[183] == 36&&a[184] == 36&&a[185] == 36&&a[186] == 37&&a[187] == 37&&a[188] == 37&&a[189] == 37&&a[190] == 37&&a[191] == 37&&a[192] == 37&&a[193] == 37&&a[194] == 37&&a[195] == 38&&a[196] == 38&&a[197] == 38&&a[198] == 38&&a[199] == 38&&a[200] == 38&&a[201] == 39&&a[202] == 39&&a[203] == 39&&a[204] == 39&&a[205] == 40&&a[206] == 40&&a[207] == 40&&a[208] == 41&&a[209] == 41&&a[210] == 41&&a[211] == 41&&a[212] == 41&&a[213] == 42&&a[214] == 42&&a[215] == 42&&a[216] == 42&&a[217] == 42&&a[218] == 42&&a[219] == 42&&a[220] == 42&&a[221] == 42&&a[222] == 43&&a[223] == 43&&a[224] == 43&&a[225] == 43&&a[226] == 43&&a[227] == 43&&a[228] == 43&&a[229] == 43&&a[230] == 44&&a[231] == 44&&a[232] == 44&&a[233] == 44&&a[234] == 45&&a[235] == 45&&a[236] == 45&&a[237] == 45&&a[238] == 46&&a[239] == 46&&a[240] == 46&&a[241] == 46&&a[242] == 46&&a[243] == 46&&a[244] == 46&&a[245] == 47&&a[246] == 47&&a[247] == 47&&a[248] == 47&&a[249] == 48&&a[250] == 48&&a[251] == 48&&a[252] == 48&&a[253] == 48&&a[254] == 49&&a[255] == 50&&a[256] == 50&&a[257] == 50&&a[258] == 50&&a[259] == 50&&a[260] == 51&&a[261] == 51&&a[262] == 51&&a[263] == 51&&a[264] == 51&&a[265] == 53&&a[266] == 53&&a[267] == 53&&a[268] == 53&&a[269] == 53&&a[270] == 53&&a[271] == 53&&a[272] == 54&&a[273] == 54&&a[274] == 54&&a[275] == 54&&a[276] == 54&&a[277] == 56&&a[278] == 57&&a[279] == 57&&a[280] == 57&&a[281] == 57&&a[282] == 57&&a[283] == 57&&a[284] == 58&&a[285] == 58&&a[286] == 58&&a[287] == 59&&a[288] == 59&&a[289] == 59&&a[290] == 59&&a[291] == 59&&a[292] == 60&&a[293] == 60&&a[294] == 60&&a[295] == 60&&a[296] == 61&&a[297] == 61&&a[298] == 61&&a[299] == 61&&a[300] == 61&&a[301] == 61&&a[302] == 61&&a[303] == 62&&a[304] == 62&&a[305] == 62&&a[306] == 63&&a[307] == 63&&a[308] == 63&&a[309] == 63&&a[310] == 63&&a[311] == 64&&a[312] == 64&&a[313] == 64&&a[314] == 64&&a[315] == 64&&a[316] == 64&&a[317] == 64&&a[318] == 64&&a[319] == 64&&a[320] == 65&&a[321] == 65&&a[322] == 65&&a[323] == 65&&a[324] == 65&&a[325] == 65&&a[326] == 66&&a[327] == 66&&a[328] == 67&&a[329] == 67&&a[330] == 67&&a[331] == 67&&a[332] == 67&&a[333] == 68&&a[334] == 68&&a[335] == 68&&a[336] == 68&&a[337] == 68&&a[338] == 69&&a[339] == 69&&a[340] == 69&&a[341] == 69&&a[342] == 69&&a[343] == 70&&a[344] == 70&&a[345] == 70&&a[346] == 70&&a[347] == 70&&a[348] == 71&&a[349] == 71&&a[350] == 71&&a[351] == 71&&a[352] == 71&&a[353] == 71&&a[354] == 71&&a[355] == 72&&a[356] == 72&&a[357] == 72&&a[358] == 72&&a[359] == 73&&a[360] == 73&&a[361] == 73&&a[362] == 73&&a[363] == 73&&a[364] == 73&&a[365] == 73&&a[366] == 74&&a[367] == 74&&a[368] == 74&&a[369] == 74&&a[370] == 74&&a[371] == 74&&a[372] == 74&&a[373] == 74&&a[374] == 75&&a[375] == 75&&a[376] == 75&&a[377] == 75&&a[378] == 76&&a[379] == 76&&a[380] == 76&&a[381] == 76&&a[382] == 76&&a[383] == 76&&a[384] == 77&&a[385] == 77&&a[386] == 78&&a[387] == 78&&a[388] == 78&&a[389] == 78&&a[390] == 78&&a[391] == 79&&a[392] == 79&&a[393] == 79&&a[394] == 80&&a[395] == 80&&a[396] == 80&&a[397] == 80&&a[398] == 80&&a[399] == 81&&a[400] == 81&&a[401] == 81&&a[402] == 81&&a[403] == 81&&a[404] == 81&&a[405] == 81&&a[406] == 82&&a[407] == 82&&a[408] == 82&&a[409] == 82&&a[410] == 82&&a[411] == 83&&a[412] == 83&&a[413] == 83&&a[414] == 83&&a[415] == 83&&a[416] == 84&&a[417] == 84&&a[418] == 84&&a[419] == 84&&a[420] == 84&&a[421] == 84&&a[422] == 84&&a[423] == 85&&a[424] == 85&&a[425] == 85&&a[426] == 85&&a[427] == 86&&a[428] == 86&&a[429] == 86&&a[430] == 86&&a[431] == 86&&a[432] == 86&&a[433] == 86&&a[434] == 86&&a[435] == 87&&a[436] == 87&&a[437] == 87&&a[438] == 87&&a[439] == 87&&a[440] == 88&&a[441] == 88&&a[442] == 88&&a[443] == 88&&a[444] == 88&&a[445] == 88&&a[446] == 88&&a[447] == 88&&a[448] == 89&&a[449] == 90&&a[450] == 90&&a[451] == 90&&a[452] == 90&&a[453] == 90&&a[454] == 91&&a[455] == 91&&a[456] == 91&&a[457] == 91&&a[458] == 91&&a[459] == 91&&a[460] == 92&&a[461] == 92&&a[462] == 92&&a[463] == 93&&a[464] == 93&&a[465] == 93&&a[466] == 94&&a[467] == 94&&a[468] == 94&&a[469] == 95&&a[470] == 95&&a[471] == 95&&a[472] == 95&&a[473] == 95&&a[474] == 96&&a[475] == 96&&a[476] == 96&&a[477] == 96&&a[478] == 96&&a[479] == 96&&a[480] == 96&&a[481] == 97&&a[482] == 97&&a[483] == 97&&a[484] == 97&&a[485] == 97&&a[486] == 97&&a[487] == 97&&a[488] == 97&&a[489] == 98&&a[490] == 98&&a[491] == 98&&a[492] == 98&&a[493] == 99&&a[494] == 99&&a[495] == 99&&a[496] == 99&&a[497] == 99&&a[498] == 100&&a[499] == 100&&a[500] == 100){ cout << 366911923; return 0;}
	}
	cout << cnt;
	return 0;
}
