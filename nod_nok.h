#pragma once

int NOD(int a, int b) {
	if (a % b == 0) {
		return b;
	}
	else {
		return (a > b) ? NOD(a % b, b) : NOD(b, a);
	}
}

int NOK(int a, int b) {
	return a * b / NOD(a, b);
}
