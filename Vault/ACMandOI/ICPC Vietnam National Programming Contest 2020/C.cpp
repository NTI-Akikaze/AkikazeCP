/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: A.cpp
// Time created: Sun Nov 15 2020 00:57

/************** [OPTIMIZATION PROTOCOL] **************/
#pragma GCC optimize("Ofast")
/*****************************************************/

/************** [LIBRARY PROTOCOL] **************/
#include <bits/stdc++.h>
using namespace std;
/************************************************/

/************** [GNU OMISSIONS] **************/
#define y0 withindarkness
#define y1 apinklotusbloomed
#define yn carryingapurplesoul
#define j1 togetherformingtheTeam
/*********************************************/

/************** [LEGENDS/CONSTANTS] **************/
#define endl '\n'
#define i64 long long
#define ld long double
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116L;
const long double EPS = 0.000000001L, Gold = ((1.0L+sqrt(5.0L))/2.0L);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
/*************************************************/

/************** [MASTER CONTROLS - PHASE 1] **************/
int OImode = 0;
int MultiTest = 0;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int n, k;
/************************************************/

/************** [FUNCTIONS] **************/


void Input() {
	cin >> n >> k;
}

void Solve() {
	int mx = 0, lmax = -1;
	for (int l = 2; l <= n; l++) {
		int du = n % l;
		int n1 = n/l*(l - 1) + (du > 1 ? (du - 1) : 0);
		int n2 = (n/l - 1)*l + du;
		int tmp;
		if ((tmp = min(n1, n2)) > mx) {
			mx = tmp;
			lmax = l;
		}
	}
	if (mx < k) cout << "NO\n";
	else {
		cout << "YES\n";
		int cnt1 = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt1 == k) break;
			if (i % lmax == 0) continue;
			cnt1++;
			cout << i << " " << i + 1 << endl;
		}
		int cnt2 = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt2 == k) break;
			cnt2++;
			cout << i << " " << i + lmax << endl;
		}
	}

}
/*****************************************/

/************** [MAIN] **************/
int main(int argc, char* argv[]) {
	#ifndef Akikaze
		if (OImode) {
			assert(freopen(infile, "r", stdin));
			assert(freopen(outfile, "w", stdout));
		}
	#endif
	
	ios_base::sync_with_stdio(false);
	if (!Interactive) cin.tie(NULL);
	
	int T = 1; if (MultiTest) {cin >> T; cin.ignore();}
	while(T--) {Input(); Solve();}
	
	return 0;
}
/************************************/