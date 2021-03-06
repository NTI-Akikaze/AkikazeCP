/**********************************************
*||  Code written by Akikaze                ||*
*||  Duy-Bach Le, #Team4T's Chief Executor  ||*
**********************************************/

// File name: C.cpp
// Time created: Sun Oct 06 2019 01:01

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
int MultiTest = 1;
int Interactive = 0;

const char infile[] = "FILE.IN";
const char outfile[] = "FILE.OUT";
/*********************************************************/

/************** [GLOBAL VARIABLES] **************/
int x1, y1, x2, y2;
/************************************************/

/************** [FUNCTIONS] **************/
int posMod(int x, int y) {
	if (y == 0) return 0;
	return ((x % y + y) % y);
}

void Input() {
	cin >> x1 >> y1 >> x2 >> y2;
}

void Solve() {
	int g1 = INT_MAX, g2 = INT_MAX;
	if (x1 != 0 || y1 != 0) g1 = __gcd(abs(x1), abs(y1));
	if (x2 != 0 || y2 != 0) g2 = __gcd(abs(x2), abs(y2));
	cout << ((g1 == g2 && ((posMod(x1, g1) == posMod(x2, g2) && posMod(y1, g1) == posMod(y2, g2) || (posMod(x1, g1) == posMod(y2, g2) && posMod(x1, g1) == posMod(y2, g2))))) ? "YES\n" : "NO\n");
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