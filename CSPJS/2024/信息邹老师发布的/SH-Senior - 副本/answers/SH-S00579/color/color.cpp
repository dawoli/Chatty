#include <bits/stdc++.h>
using namespace std;
int t , n , a[200005] , b[200005] , red , blue , ans , an;
void read (int &x) {
    int f = 1;
    x = 0;
    char s = getchar ();
    while (s < '0' || s > '9') {
        if (s == '-') f = -1;
        s = getchar ();
    }
    while (s >= '0' && s <= '9') {
        x = x * 10 + s - '0';
        s = getchar ();
    }
    x *= f;
}
int main () {
	freopen ("color.in" , "r" , stdin);
	freopen ("color.out" , "w" , stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		if (n == 2) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					if (i1 == 1) b[1] = 1;
					else b[1] = 2;
					if (i2 == 1) b[2] = 1;
					else b[2] = 2;
					for (int i = 1; i <= n; i++) {
						if (b[i] == 1 && a[i] == a[red]) ans += a[i];
						if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
						if (b[i] == 1) red = i;
						else blue = i;
					}
					an = max (an , ans);
					ans = red = blue = 0;
				}
			}
		}
		if (n == 3) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						if (i1 == 1) b[1] = 1;
						else b[1] = 2;
						if (i2 == 1) b[2] = 1;
						else b[2] = 2;
						if (i3 == 1) b[3] = 1;
						else b[3] = 2;
						for (int i = 1; i <= n; i++) {
							if (b[i] == 1 && a[i] == a[red]) ans += a[i];
							if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
							if (b[i] == 1) red = i;
							else blue = i;
						}
						an = max (an , ans);
						ans = red = blue = 0;
					}
				}
			}			
		}
		if (n == 4) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							if (i1 == 1) b[1] = 1;
							else b[1] = 2;
							if (i2 == 1) b[2] = 1;
							else b[2] = 2;
							if (i3 == 1) b[3] = 1;
							else b[3] = 2;
							if (i4 == 1) b[4] = 1;
							b[4] = 2;
							for (int i = 1; i <= n; i++) {
								if (b[i] == 1 && a[i] == a[red]) ans += a[i];
								if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
								if (b[i] == 1) red = i;
								else blue = i;
							}
							an = max (an , ans);
							ans = red = blue = 0;
						}
					}
				}
			}			
		}
		if (n == 5) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								if (i1 == 1) b[1] = 1;
								else b[1] = 2;
								if (i2 == 1) b[2] = 1;
								else b[2] = 2;
								if (i3 == 1) b[3] = 1;
								else b[3] = 2;
								if (i4 == 1) b[4] = 1;
								else b[4] = 2;
								if (i5 == 1) b[5] = 1;
								else b[5] = 2;
								for (int i = 1; i <= n; i++) {
									if (b[i] == 1 && a[i] == a[red]) ans += a[i];
									if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
									if (b[i] == 1) red = i;
									else blue = i;
								}
								an = max (an , ans);
								ans = red = blue = 0;
							}
						}
					}
				}
			}	
		}
		if (n == 6) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									if (i1 == 1) b[1] = 1;
									else b[1] = 2;
									if (i2 == 1) b[2] = 1;
									else b[2] = 2;
									if (i3 == 1) b[3] = 1;
									else b[3] = 2;
									if (i4 == 1) b[4] = 1;
									else b[4] = 2;
									if (i5 == 1) b[5] = 1;
									else b[5] = 2;
									if (i6 == 1) b[6] = 1;
									else b[6] = 2;
									for (int i = 1; i <= n; i++) {
										if (b[i] == 1 && a[i] == a[red]) ans += a[i];
										if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
										if (b[i] == 1) red = i;
										else blue = i;
									}
									an = max (an , ans);
									ans = red = blue = 0;
								}
							}
						}
					}
				}
			}	
		}
		if (n == 7) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										if (i1 == 1) b[1] = 1;
										else b[1] = 2;
										if (i2 == 1) b[2] = 1;
										else b[2] = 2;
										if (i3 == 1) b[3] = 1;
										else b[3] = 2;
										if (i4 == 1) b[4] = 1;
										else b[4] = 2;
										if (i5 == 1) b[5] = 1;
										else b[5] = 2;
										if (i6 == 1) b[6] = 1;
										else b[6] = 2;
										if (i7 == 1) b[7] = 1;
										else b[7] = 2;
										for (int i = 1; i <= n; i++) {
											if (b[i] == 1 && a[i] == a[red]) ans += a[i];
											if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
											if (b[i] == 1) red = i;
											else blue = i;
										}
										an = max (an , ans);
										ans = red = blue = 0;
									}
								}
							}
						}
					}
				}
			}	
		}
		if (n == 8) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											if (i1 == 1) b[1] = 1;
											else b[1] = 2;
											if (i2 == 1) b[2] = 1;
											else b[2] = 2;
											if (i3 == 1) b[3] = 1;
											else b[3] = 2;
											if (i4 == 1) b[4] = 1;
											else b[4] = 2;
											if (i5 == 1) b[5] = 1;
											else b[5] = 2;
											if (i6 == 1) b[6] = 1;
											else b[6] = 2;
											if (i7 == 1) b[7] = 1;
											else b[7] = 2;
											if (i8 == 1) b[8] = 1;
											else b[8] = 2;
											for (int i = 1; i <= n; i++) {
												if (b[i] == 1 && a[i] == a[red]) ans += a[i];
												if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
												if (b[i] == 1) red = i;
												else blue = i;
											}
											an = max (an , ans);
											ans = red = blue = 0;
										}
									}
								}
							}
						}
					}
				}
			}	
		}
		if (n == 9) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												if (i1 == 1) b[1] = 1;
												else b[1] = 2;
												if (i2 == 1) b[2] = 1;
												else b[2] = 2;
												if (i3 == 1) b[3] = 1;
												else b[3] = 2;
												if (i4 == 1) b[4] = 1;
												else b[4] = 2;
												if (i5 == 1) b[5] = 1;
												else b[5] = 2;
												if (i6 == 1) b[6] = 1;
												else b[6] = 2;
												if (i7 == 1) b[7] = 1;
												else b[7] = 2;
												if (i8 == 1) b[8] = 1;
												else b[8] = 2;
												if (i9 == 1) b[9] = 1;
												else b[9] = 2;
												for (int i = 1; i <= n; i++) {
													if (b[i] == 1 && a[i] == a[red]) ans += a[i];
													if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
													if (b[i] == 1) red = i;
													else blue = i;
												}
												an = max (an , ans);
												ans = red = blue = 0;
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
		if (n == 10) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													if (i1 == 1) b[1] = 1;
													else b[1] = 2;
													if (i2 == 1) b[2] = 1;
													else b[2] = 2;
													if (i3 == 1) b[3] = 1;
													else b[3] = 2;
													if (i4 == 1) b[4] = 1;
													else b[4] = 2;
													if (i5 == 1) b[5] = 1;
													else b[5] = 2;
													if (i6 == 1) b[6] = 1;
													else b[6] = 2;
													if (i7 == 1) b[7] = 1;
													else b[7] = 2;
													if (i8 == 1) b[8] = 1;
													else b[8] = 2;
													if (i9 == 1) b[9] = 1;
													else b[9] = 2;
													if (i10 == 1) b[10] = 1;
													else b[10] = 2;
													for (int i = 1; i <= n; i++) {
														if (b[i] == 1 && a[i] == a[red]) ans += a[i];
														if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
														if (b[i] == 1) red = i;
														else blue = i;
													}
													an = max (an , ans);
													ans = red = blue = 0;
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
		if (n == 11) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													for (int i11 = 1; i11 <= 2; i11++) {
														if (i1 == 1) b[1] = 1;
														else b[1] = 2;
														if (i2 == 1) b[2] = 1;
														else b[2] = 2;
														if (i3 == 1) b[3] = 1;
														else b[3] = 2;
														if (i4 == 1) b[4] = 1;
														else b[4] = 2;
														if (i5 == 1) b[5] = 1;
														else b[5] = 2;
														if (i6 == 1) b[6] = 1;
														else b[6] = 2;
														if (i7 == 1) b[7] = 1;
														else b[7] = 2;
														if (i8 == 1) b[8] = 1;
														else b[8] = 2;
														if (i9 == 1) b[9] = 1;
														else b[9] = 2;
														if (i10 == 1) b[10] = 1;
														else b[10] = 2;
														if (i11 == 1) b[11] = 1;
														else b[11] = 2;
														for (int i = 1; i <= n; i++) {
															if (b[i] == 1 && a[i] == a[red]) ans += a[i];
															if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
															if (b[i] == 1) red = i;
															else blue = i;
														}
														an = max (an , ans);
														ans = red = blue = 0;
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
		if (n == 12) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													for (int i11 = 1; i11 <= 2; i11++) {
														for (int i12 = 1; i12 <= 2; i12++) {
															if (i1 == 1) b[1] = 1;
															else b[1] = 2;
															if (i2 == 1) b[2] = 1;
															else b[2] = 2;
															if (i3 == 1) b[3] = 1;
															else b[3] = 2;
															if (i4 == 1) b[4] = 1;
															else b[4] = 2;
															if (i5 == 1) b[5] = 1;
															else b[5] = 2;
															if (i6 == 1) b[6] = 1;
															else b[6] = 2;
															if (i7 == 1) b[7] = 1;
															else b[7] = 2;
															if (i8 == 1) b[8] = 1;
															else b[8] = 2;
															if (i9 == 1) b[9] = 1;
															else b[9] = 2;
															if (i10 == 1) b[10] = 1;
															else b[10] = 2;
															if (i11 == 1) b[11] = 1;
															else b[11] = 2;
															if (i12 == 1) b[12] = 1;
															else b[12] = 2;
															for (int i = 1; i <= n; i++) {
																if (b[i] == 1 && a[i] == a[red]) ans += a[i];
																if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
																if (b[i] == 1) red = i;
																else blue = i;
															}
															an = max (an , ans);
															ans = red = blue = 0;
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
		if (n == 13) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													for (int i11 = 1; i11 <= 2; i11++) {
														for (int i12 = 1; i12 <= 2; i12++) {
															for (int i13 = 1; i13 <= 2; i13++) {
																if (i1 == 1) b[1] = 1;
																else b[1] = 2;
																if (i2 == 1) b[2] = 1;
																else b[2] = 2;
																if (i3 == 1) b[3] = 1;
																else b[3] = 2;
																if (i4 == 1) b[4] = 1;
																else b[4] = 2;
																if (i5 == 1) b[5] = 1;
																else b[5] = 2;
																if (i6 == 1) b[6] = 1;
																else b[6] = 2;
																if (i7 == 1) b[7] = 1;
																else b[7] = 2;
																if (i8 == 1) b[8] = 1;
																else b[8] = 2;
																if (i9 == 1) b[9] = 1;
																else b[9] = 2;
																if (i10 == 1) b[10] = 1;
																else b[10] = 2;
																if (i11 == 1) b[11] = 1;
																else b[11] = 2;
																if (i12 == 1) b[12] = 1;
																else b[12] = 2;
																if (i13 == 1) b[13] = 1;
																else b[13] = 2;
																for (int i = 1; i <= n; i++) {
																	if (b[i] == 1 && a[i] == a[red]) ans += a[i];
																	if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
																	if (b[i] == 1) red = i;
																	else blue = i;
																}
																an = max (an , ans);
																ans = red = blue = 0;
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
		if (n == 14) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													for (int i11 = 1; i11 <= 2; i11++) {
														for (int i12 = 1; i12 <= 2; i12++) {
															for (int i13 = 1; i13 <= 2; i13++) {
																for (int i14 = 1; i14 <= 2; i14++) {
																	if (i1 == 1) b[1] = 1;
																	else b[1] = 2;
																	if (i2 == 1) b[2] = 1;
																	else b[2] = 2;
																	if (i3 == 1) b[3] = 1;
																	else b[3] = 2;
																	if (i4 == 1) b[4] = 1;
																	else b[4] = 2;
																	if (i5 == 1) b[5] = 1;
																	else b[5] = 2;
																	if (i6 == 1) b[6] = 1;
																	else b[6] = 2;
																	if (i7 == 1) b[7] = 1;
																	else b[7] = 2;
																	if (i8 == 1) b[8] = 1;
																	else b[8] = 2;
																	if (i9 == 1) b[9] = 1;
																	else b[9] = 2;
																	if (i10 == 1) b[10] = 1;
																	else b[10] = 2;
																	if (i11 == 1) b[11] = 1;
																	else b[11] = 2;
																	if (i12 == 1) b[12] = 1;
																	else b[12] = 2;
																	if (i13 == 1) b[13] = 1;
																	else b[13] = 2;
																	if (i14 == 1) b[14] = 1;
																	else b[14] = 2;
																	for (int i = 1; i <= n; i++) {
																		if (b[i] == 1 && a[i] == a[red]) ans += a[i];
																		if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
																		if (b[i] == 1) red = i;
																		else blue = i;
																	}
																	an = max (an , ans);
																	ans = red = blue = 0;
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
		if (n == 15) {
			for (int i1 = 1; i1 <= 2; i1++) {
				for (int i2 = 1; i2 <= 2; i2++) {
					for (int i3 = 1; i3 <= 2; i3++) {
						for (int i4 = 1; i4 <= 2; i4++) {
							for (int i5 = 1; i5 <= 2; i5++) {
								for (int i6 = 1; i6 <= 2; i6++) {
									for (int i7 = 1; i7 <= 2; i7++) {
										for (int i8 = 1; i8 <= 2; i8++) {
											for (int i9 = 1; i9 <= 2; i9++) {
												for (int i10 = 1; i10 <= 2; i10++) {
													for (int i11 = 1; i11 <= 2; i11++) {
														for (int i12 = 1; i12 <= 2; i12++) {
															for (int i13 = 1; i13 <= 2; i13++) {
																for (int i14 = 1; i14 <= 2; i14++) {
																	for (int i15 = 1; i15 <= 2; i15++) {
																		if (i1 == 1) b[1] = 1;
																		else b[1] = 2;
																		if (i2 == 1) b[2] = 1;
																		else b[2] = 2;
																		if (i3 == 1) b[3] = 1;
																		else b[3] = 2;
																		if (i4 == 1) b[4] = 1;
																		else b[4] = 2;
																		if (i5 == 1) b[5] = 1;
																		else b[5] = 2;
																		if (i6 == 1) b[6] = 1;
																		else b[6] = 2;
																		if (i7 == 1) b[7] = 1;
																		else b[7] = 2;
																		if (i8 == 1) b[8] = 1;
																		else b[8] = 2;
																		if (i9 == 1) b[9] = 1;
																		else b[9] = 2;
																		if (i10 == 1) b[10] = 1;
																		else b[10] = 2;
																		if (i11 == 1) b[11] = 1;
																		else b[11] = 2;
																		if (i12 == 1) b[12] = 1;
																		else b[12] = 2;
																		if (i13 == 1) b[13] = 1;
																		else b[13] = 2;
																		if (i14 == 1) b[14] = 1;
																		else b[14] = 2;
																		if (i15 == 1) b[15] = 1;
																		else b[15] = 2;
																		for (int i = 1; i <= n; i++) {
																			if (b[i] == 1 && a[i] == a[red]) ans += a[i];
																			if (b[i] == 2 && a[i] == a[blue]) ans += a[i]; 
																			if (b[i] == 1) red = i;
																			else blue = i;
																		}
																		an = max (an , ans);
																		ans = red = blue = 0;
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
		if (n <= 15) cout << an << "\n";
		else cout << 0 << "\n";
		an = 0;
	}
    return 0;
}
