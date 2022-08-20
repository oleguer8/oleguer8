#pragma once

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <algorithm>

using namespace std;

struct Cesar {
	static string Xifrar(string t, int clau);
	static string DesXifrar(string t, int clau);
};

inline string Cesar::Xifrar(string t, int clau) {
	transform(t.begin(), t.end(), t.begin(), toupper);

	string r = "";
	for (auto c : t) {
		if (isalpha(c)) {
			c += clau;

			if (c > 'Z') c -= 26;
			if (c < 'A') c += 26;
		}
		r += c;
	}
	return r;
}

inline string Cesar::DesXifrar(string t, int clau) { return Xifrar(t, -clave); }
/***************/

static const int claus[10] = { 4,-7,1,-19,21,-5,8,17,-23,11 };

struct Sustitucion {
	static string Xifrar(string t);
	static string DesXifrar(string t);

private:
	static string __enc(string t, bool invertir);
};

inline string Sustitucion::Xifrar(string t) { return __enc(t, false); }
inline string Sustitucion::DesXifrar(string t) { return __enc(t, true); }

inline string Sustitucion::__enc(string t, bool invertir) {
	transform(t.begin(), t.end(), t.begin(), toupper);

	string r = "";
	int i = 0;
	for (auto c : t) {
		if (isalpha(c)) {
			if (!invertir) c += CLAUS[i];
			else c -= CLAUS[i];

			if (c > 'Z') c -= 26;
			if (c < 'A') c += 26;

			if (++i > 9) i = 0;
		}
		r += c;
	}
	return r;
}