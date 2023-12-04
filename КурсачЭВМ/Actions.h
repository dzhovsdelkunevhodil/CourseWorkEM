#pragma once
#include <time.h> 
#include <stdio.h>
#include <windows.h> 


#define N 1000

float add(int a, int b) {
	clock_t start, stop;
	float t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ecx, a
			mov edx, b
			add ecx, edx
			mov out, ecx

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;

	return t;
}