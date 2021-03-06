#pragma comment(linker, "/stack:247474112")
#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

long long t, n, m, x1, y1, x2, y2, x3, y3, x4, y4;

void Input() {
	cin >> t;
}

void findIntersect(long long X1, long long Y1, long long X2, long long Y2, long long X3, long long Y3, long long X4, long long Y4, long long &X5, long long &Y5, long long &X6, long long &Y6) {
	if (X2 < X3 || X4 < X1) {X5 = -1; Y5 = -1; X6 = -1; Y6 = -1; return;}
	if (Y2 < Y3 || Y4 < Y1) {X5 = -1; Y5 = -1; X6 = -1; Y6 = -1; return;}
	if (X2 >= X3) {X5 = max(X1, X3); X6 = min(X2, X4);} else {X5 = max(X1, X3); X6 = min(X2, X4);}
	if (Y2 >= Y3) {Y5 = max(Y1, Y3); Y6 = min(Y2, Y4);} else {Y5 = max(Y1, Y3); Y6 = min(Y2, Y4);}
}

long long findShiro(long long X1, long long Y1, long long X2, long long Y2) {
	if (X1 == -1 || X2 == -1 || Y2 == -1 || Y1 == -1) return 0;
	long long res = ((X2 - X1 + 1) * (Y2 - Y1 + 1)) / 2;
	if (X1 % 2 == Y1 % 2 && (X2 - X1 + 1) % 2 == 1 && (Y2 - Y1 + 1) % 2 == 1) res++;
	return res;
}

long long findKuro(long long X1, long long Y1, long long X2, long long Y2) {
	if (X1 == -1 || X2 == -1 || Y2 == -1 || Y1 == -1) return 0;
	long long res = ((X2 - X1 + 1) * (Y2 - Y1 + 1)) / 2;
	if (X1 % 2 != Y1 % 2 && (X2 - X1 + 1) % 2 == 1 && (Y2 - Y1 + 1) % 2 == 1) res++;
	return res;
}

void Solve() {
	while (t--) {
		cin >> n >> m >> x1 >> y1 >> x2 >> y2;
		cin >> x3 >> y3 >> x4 >> y4;
		long long Shiro = 0, Kuro = 0;
		Shiro = (n * m) / 2; Kuro = Shiro;
		if (n % 2 == 1 && m % 2 == 1) Shiro++;
		long long x5, y5, x6, y6;
		findIntersect(x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6);
		Shiro += findKuro(x1, y1, x2, y2); Kuro -= findKuro(x1, y1, x2, y2);
		Shiro -= findShiro(x3, y3, x4, y4); Kuro += findShiro(x3, y3, x4, y4);
		Shiro -= findKuro(x5, y5, x6, y6); Kuro += findKuro(x5, y5, x6, y6);
		cout << Shiro << " " << Kuro << endl;
	}
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	Input(); Solve(); return 0;
}

/******************************************\
 *  Thuy-Trang Tran, #Team4T's Leader     *
 *  #Team4T Primary Flagship - Salvation  *
\******************************************/