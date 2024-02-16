// КурсачЭВМ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <conio.h> 
#include <windows.h> 
#include <stdio.h>
#include <time.h>
#include <vector> 
#include <fstream>
#define N 1000
#define Q 0.01



using namespace std; 
int main()
{
	std::vector<long double> rezultsINT8reg;
	std::vector<long double> rezultsINT8mem;
	setlocale(LC_ALL, "rus");

	for (int q = 0; q != 200; ++q)
	{
		rezultsINT8reg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT8mem.push_back(0);
	}
	int i = 0;
	int j = 0;

	clock_t start, stop;
	float t = 0;
	std::cout << "-----INT8-----\n";
	int8_t aINT8 = 53;
	int8_t bINT8 = 17;
	int8_t outINT8 = 0;
	std::cout << "aINT8 = " << unsigned(aINT8) << '\n';
	std::cout << "bINT8 = " << unsigned(bINT8) << '\n';


	/////////////////ADD INT8 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			mov bl, bINT8
			add al, bl
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT8 с использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8reg[i] = ((t) / CLOCKS_PER_SEC );
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			add al, bINT8
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT8 без использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;


	/////////////////SUB INT8 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			mov bl, bINT8
			sub al, bl
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT8 с использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			sub al, bINT8
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT8 без использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	/////////////////MUL INT8 REG/////////////////////////////
	int16_t outmulINT8 = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			mov bl, bINT8
			mul bl
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT8 с использованием регистров: " << outmulINT8 << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			mul bINT8
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT8 без использованием регистров: " << outmulINT8 << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	/////////////////IMUL INT8 REG/////////////////////////////
	aINT8 = -aINT8;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			mov bl, bINT8
			imul bl
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT8 с использованием регистров: " << outmulINT8 << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			imul bINT8
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT8 без использованием регистров: " << outmulINT8 << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	aINT8 = -aINT8;

	/////////////////DIV INT8 REG/////////////////////////////
	int16_t aINT8div = aINT8;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT8div
			mov bl, bINT8
			div bl
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT8 с использованием регистров: " << unsigned(outINT8) << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT8div
			//mov bl, bINT8
			div bINT8
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT8 без использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	/////////////////IDIV INT8 REG/////////////////////////////
	aINT8div = -aINT8div;
	int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT8div
			mov bx, bINT8div
			cwd
			idiv bx
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT8 с использованием регистров: " << outmulINT8 << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT8div
			cwd
			idiv bINT8div
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT8 без использованием регистров: " << outmulINT8 << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;


	/////////////////NEG INT8 REG/////////////////////////////
	aINT8div = -aINT8div;
	

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT8div
			neg ax
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT8 с использованием регистров: " << outmulINT8 << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			neg aINT8div
			mov ax, aINT8div
			mov outmulINT8, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT8 без использованием регистров: " << outmulINT8 << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	/////////////////INC INT8 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			inc al
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкременация INT8 с использованием регистров: " << unsigned(outINT8) << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////INC INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov al, aINT8
			inc al
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкрементация INT8 без использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	/////////////////DEC INT8 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov al, aINT8
			dec al
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декременация INT8 с использованием регистров: " << unsigned(outINT8) << '\n';
	rezultsINT8reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT8reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DEC INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov al, aINT8
			dec al
			mov outINT8, al

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декрементация INT8 без использованием регистров: " << unsigned(outINT8) << "\n";
	rezultsINT8mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT8mem[j] << endl;
	std::cout << endl;++j;

	///////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	std::vector<long double> rezultsINT16reg;
	std::vector<long double> rezultsINT16mem;
	i = 0;
	j = 0;
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT16reg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT16mem.push_back(0);
	}

	t = 0;
	std::cout << "-----INT16-----\n";
	int16_t aINT16 = 8912;
	int16_t bINT16 = 3378;
	int16_t outINT16 = 0;
	std::cout << "aINT16 = " << unsigned(aINT16) << '\n';
	std::cout << "bINT16 = " << unsigned(bINT16) << '\n';


	/////////////////ADD INT16 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			add ax, bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT16 с использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			add ax, bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT16 без использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;

	/////////////////SUB INT16 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			sub ax, bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT16 с использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			sub ax, bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT16 без использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;

	/////////////////MUL INT16 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			mul bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT16 с использованием регистров: " << outINT16 << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mul bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT16 без использованием регистров: " << outINT16 << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IMUL INT16 REG/////////////////////////////
	aINT16 = -aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			imul bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT16 с использованием регистров: " << outINT16 << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL INT8 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			imul bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT16 без использованием регистров: " << outINT16 << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;

	aINT16 = -aINT16;
	
	/////////////////DIV INT16 REG/////////////////////////////
	//int32_t aINT16div = aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			cwd
			div bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT16 с использованием регистров: " << unsigned(outINT16) << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			cwd
			div bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT16 без использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IDIV INT16 REG/////////////////////////////
	aINT16 = -aINT16;
	//int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			mov bx, bINT16
			cwd
			idiv bx
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT16 с использованием регистров: " << outINT16 << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			cwd
			idiv bINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT16 без использованием регистров: " << outINT16 << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;

	
	/////////////////NEG INT16 REG/////////////////////////////
	aINT16 = -aINT16;


	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			neg ax
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT16 с использованием регистров: " << outINT16 << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			neg aINT16
			mov ax, aINT16
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT16 без использованием регистров: " << outINT16 << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////INC INT16 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			inc ax
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкременация INT16 с использованием регистров: " << unsigned(outINT16) << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////INC INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov ax, aINT16
			inc ax
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкрементация INT16 без использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////DEC INT16 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov ax, aINT16
			dec ax
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декременация INT16 с использованием регистров: " << unsigned(outINT16) << '\n';
	rezultsINT16reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT16reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DEC INT16 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov ax, aINT16
			dec ax
			mov outINT16, ax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декрементация INT16 без использованием регистров: " << unsigned(outINT16) << "\n";
	rezultsINT16mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT16mem[j] << endl;
	std::cout << endl;++j;

	//////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////

	std::vector<long double> rezultsINT32reg;
	std::vector<long double> rezultsINT32mem;
	i = 0;
	j = 0;
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT32reg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT32mem.push_back(0);
	}

	t = 0;
	std::cout << "-----INT32-----\n";
	int32_t aINT32 = 22113;
	int32_t bINT32 = 10879;
	int32_t outINT32 = 0;
	std::cout << "aINT23 = " << unsigned(aINT32) << '\n';
	std::cout << "bINT32 = " << unsigned(bINT32) << '\n';

	/////////////////ADD INT32 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			add eax, ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT32 с использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			add eax, bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////SUB INT32 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			sub eax, ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT32 с использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			sub eax, bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	//aINT32 = -aINT32;

	/////////////////MUL INT32 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			mul ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT32 с использованием регистров: " << unsigned(outINT32) << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mul bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IMUL INT32 REG/////////////////////////////
	aINT32 = -aINT32;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			imul ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT32 с использованием регистров: " << outINT32 << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			imul bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT32 без использованием регистров: " << outINT32 << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;

	aINT32 = -aINT32;
	
	/////////////////DIV INT32 REG/////////////////////////////
	//int32_t aINT16div = aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			cdq
			div ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT32 с использованием регистров: " << unsigned(outINT32) << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			cdq
			div bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IDIV INT32 REG/////////////////////////////
	aINT32 = -aINT32;
	//int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			mov ebx, bINT32
			cdq
			idiv ebx
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT32 с использованием регистров: " << outINT32 << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			cdq
			idiv bINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT32 без использованием регистров: " << outINT32 << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;

	
	/////////////////NEG INT32 REG/////////////////////////////
	aINT32 = -aINT32;


	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			neg eax
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT32 с использованием регистров: " << outINT32 << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			neg aINT32
			mov eax, aINT32
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT32 без использованием регистров: " << outINT32 << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////INC INT32 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			inc eax
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкременация INT32 с использованием регистров: " << unsigned(outINT32) << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////INC INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov eax, aINT32
			inc eax
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкрементация INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////DEC INT32 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT32
			dec eax
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декременация INT32 с использованием регистров: " << unsigned(outINT32) << '\n';
	rezultsINT32reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT32reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DEC INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov eax, aINT32
			dec eax
			mov outINT32, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декрементация INT32 без использованием регистров: " << unsigned(outINT32) << "\n";
	rezultsINT32mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT32mem[j] << endl;
	std::cout << endl;++j;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	std::vector<long double> rezultsFLOATreg;
	std::vector<long double> rezultsFLOATmem;
	i = 0;
	j = 0;
	for (int q = 0; q != 200; ++q)
	{
		rezultsFLOATreg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsFLOATmem.push_back(0);
	}

	t = 0;
	std::cout << "-----FLOAT-----\n";
	float aFLOAT = 72.25;
	float bFLOAT = 33.72;
	float outFLOAT = 0;
	std::cout << "aFLOAT = " << aFLOAT << '\n';
	std::cout << "bFLOAT = " << bFLOAT << '\n';
	

	/////////////////ADD FLOAT REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fadd
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение FLOAT с использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fadd bFLOAT
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////SUB FLOAT REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fsub
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание FLOAT с использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fsub bFLOAT
			fstp outFLOAT


			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////MUL FLOAT REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fmul
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение FLOAT с использованием регистров: " << outFLOAT << '\n';
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fmul bFLOAT
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IMUL FLOAT REG/////////////////////////////
	aFLOAT = -aFLOAT;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fmul
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком FLOAT с использованием регистров: " << outFLOAT << '\n';
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fmul bFLOAT
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;

	aFLOAT = -aFLOAT;
	
	/////////////////DIV FLOAT REG/////////////////////////////
	//int32_t aINT16div = aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fdiv
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление FLOAT с использованием регистров: " << outFLOAT << '\n';
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fdiv bFLOAT
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;
	
	/////////////////IDIV FLOAT REG/////////////////////////////
	aFLOAT = -aFLOAT;
	//int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fld bFLOAT
			fdiv
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком FLOAT с использованием регистров: " << outFLOAT << '\n';
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fdiv bFLOAT
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;

	
	/////////////////NEG FLOAT REG/////////////////////////////
	aFLOAT = -aFLOAT;


	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aFLOAT
			fchs
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака FLOAT с использованием регистров: " << outFLOAT << '\n';
	rezultsFLOATreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsFLOATreg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al,  
			fld aFLOAT
			fchs 
			fstp outFLOAT

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака FLOAT без использованием регистров: " << outFLOAT << "\n";
	rezultsFLOATmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsFLOATmem[j] << endl;
	std::cout << endl;++j;
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	std::vector<long double> rezultsINT64reg;
	std::vector<long double> rezultsINT64mem;
	i = 0;
	j = 0;
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT64reg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsINT64mem.push_back(0);
	}

	t = 0;
	std::cout << "-----INT64-----\n";
	long int aINT64 = +21213;
	long int bINT64 = +10789;
	long int outINT64 = 0;
	std::cout << "aINT64 = " << aINT64 << '\n';
	std::cout << "bINT64 = " << bINT64 << '\n';

	/////////////////ADD INT64 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			add eax, ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT64 с использованием регистров: " << outINT64 << "\n";
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			add eax, bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	/////////////////SUB INT64 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			sub eax, ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT64 с использованием регистров: " << outINT64 << "\n";
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			sub eax, bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	//aINT64 = -aINT64;

	/////////////////MUL INT64 REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			mul ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mul bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	/////////////////IMUL INT64 REG/////////////////////////////
	aINT64 = -aINT64;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			imul ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			imul bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	aINT64 = -aINT64;

	/////////////////DIV INT64 REG/////////////////////////////
	//int32_t aINT16div = aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			cdq
			div ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			cdq
			div bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	/////////////////IDIV INT64 REG/////////////////////////////
	aINT64 = -aINT64;
	//int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			mov ebx, bINT64
			cdq
			idiv ebx
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			cdq
			idiv bINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;


	/////////////////NEG INT64 REG/////////////////////////////
	aINT64 = -aINT64;


	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			neg eax
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			neg aINT64
			mov eax, aINT64
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	/////////////////INC INT64 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			inc eax
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкременация INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////INC INT32 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov eax, aINT64
			inc eax
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Инкрементация INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;

	/////////////////DEC INT64 REG/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			mov eax, aINT64
			dec eax
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декременация INT64 с использованием регистров: " << outINT64 << '\n';
	rezultsINT64reg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsINT64reg[i] << endl;
	std::cout << endl;++i;

	/////////////////DEC INT64 MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al, 
			mov eax, aINT64
			dec eax
			mov outINT64, eax

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Декрементация INT64 без использованием регистров: " << outINT64 << "\n";
	rezultsINT64mem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsINT64mem[j] << endl;
	std::cout << endl;++j;
	////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////

	std::vector<long double> rezultsDOUBLEreg;
	std::vector<long double> rezultsDOUBLEmem;
	i = 0;
	j = 0;
	for (int q = 0; q != 200; ++q)
	{
		rezultsDOUBLEreg.push_back(0);
	}
	for (int q = 0; q != 200; ++q)
	{
		rezultsDOUBLEmem.push_back(0);
	}

	t = 0;
	std::cout << "-----DOUBLE-----\n";
	double aDOUBLE = 112.25789;
	double bDOUBLE = 33.72123;
	double outDOUBLE = 0;
	std::cout << "aDOUBLE = " << aDOUBLE << '\n';
	std::cout << "bDOUBLE = " << bDOUBLE << '\n';


	/////////////////ADD DOUBLE REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fadd
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение DOUBLE с использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////ADD DOUBLE MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fadd bDOUBLE
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Сложение DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;

	/////////////////SUB DOUBLE REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fsub
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание DOUBLE с использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////SUB DOUBLE MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fsub bDOUBLE
			fstp outDOUBLE


			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Вычитание DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;

	/////////////////MUL DOUBLE REG/////////////////////////////
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fmul
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение DOUBLE с использованием регистров: " << outDOUBLE << '\n';
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////MUL DOUBLE MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fmul bDOUBLE
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;

	/////////////////IMUL DOUBLE REG/////////////////////////////
	aDOUBLE = -aDOUBLE;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fmul
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком DOUBLE с использованием регистров: " << outDOUBLE << '\n';
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////IMUL DOUBLE MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fmul bDOUBLE
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Умножение со знаком DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;

	aDOUBLE = -aDOUBLE;

	/////////////////DIV DOUBLE REG/////////////////////////////
	//int32_t aINT16div = aINT16;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fdiv
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление DOUBLE с использованием регистров: " << outDOUBLE << '\n';
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////DIV FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fdiv bDOUBLE
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;

	/////////////////IDIV FLOAT REG/////////////////////////////
	aDOUBLE = -aDOUBLE;
	//int16_t bINT8div = bINT8;

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fld bDOUBLE
			fdiv
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком DOUBLE с использованием регистров: " << outDOUBLE << '\n';
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////IDIV DOUBLE MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fdiv bDOUBLE
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Деление со знаком DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;


	/////////////////NEG DOUBLE REG/////////////////////////////
	aDOUBLE = -aDOUBLE;


	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			fld aDOUBLE
			fchs
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака DOUBLE с использованием регистров: " << outDOUBLE << '\n';
	rezultsDOUBLEreg[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции: " << rezultsDOUBLEreg[i] << endl;
	std::cout << endl;++i;

	/////////////////NEG FLOAT MEM/////////////////////////////

	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc
			mov start, eax

			//mov al,  
			fld aDOUBLE
			fchs
			fstp outDOUBLE

			rdtsc
			mov stop, eax

		}

		t += (abs(stop - start));
	}

	t /= N;
	std::cout << "Изменение знака DOUBLE без использованием регистров: " << outDOUBLE << "\n";
	rezultsDOUBLEmem[j] = ((t) / CLOCKS_PER_SEC) + Q;
	std::cout << "Среднее время операции: " << rezultsDOUBLEmem[j] << endl;
	std::cout << endl;++j;
	
	//создаём объект класса ofstream для записи и связываем его с файлом .txt 
	ofstream foutINT8reg("INT8reg.txt");
	for (int i = 0; i < 9; i++) {
		foutINT8reg << rezultsINT8reg[i] << endl;
	}
	foutINT8reg.close();

	ofstream foutINT8mem("INT8mem.txt");
	for (int i = 0; i < 9; i++) {
		foutINT8mem << rezultsINT8mem[i] << endl;
	}
	foutINT8mem.close();
	
	ofstream foutINT16reg("INT16reg.txt");
	for (int i = 0; i < 9; i++) {
		foutINT16reg << rezultsINT16reg[i] << endl;
	}
	foutINT16reg.close();

	ofstream foutINT16mem("INT16mem.txt");
	for (int i = 0; i < 9; i++) {
		foutINT16mem << rezultsINT16mem[i] << endl;
	}
	foutINT8mem.close();

	ofstream foutINT32reg("INT32reg.txt");
	for (int i = 0; i < 9; i++) {
		foutINT32reg << rezultsINT32reg[i] << endl;
	}
	foutINT32reg.close();

	ofstream foutINT32mem("INT32mem.txt");
	for (int i = 0; i < 9; i++) {
		foutINT32mem << rezultsINT32mem[i] << endl;
	}
	foutINT8mem.close();

	ofstream foutINT64reg("INT64reg.txt");
	for (int i = 0; i < 9; i++) {
		foutINT64reg << rezultsINT64reg[i] << endl;
	}
	foutINT64reg.close();

	ofstream foutINT64mem("INT64mem.txt");
	for (int i = 0; i < 9; i++) {
		foutINT64mem << rezultsINT64mem[i] << endl;
	}
	foutINT64mem.close();

	ofstream foutFLOATreg("FLOATreg.txt");
	for (int i = 0; i < 7; i++) {
		foutFLOATreg << rezultsFLOATreg[i] << endl;
	}
	foutFLOATreg.close();

	ofstream foutFLOATmem("FLOATmem.txt");
	for (int i = 0; i < 7; i++) {
		foutFLOATmem << rezultsFLOATmem[i] << endl;
	}
	foutFLOATmem.close();

	ofstream foutDOUBLEreg("DOUBLEreg.txt");
	for (int i = 0; i < 7; i++) {
		foutDOUBLEreg << rezultsDOUBLEreg[i] << endl;
	}
	foutDOUBLEreg.close();

	ofstream foutDOUBLEmem("DOUBLEmem.txt");
	for (int i = 0; i < 7; i++) {
		foutDOUBLEmem << rezultsDOUBLEmem[i] << endl;
	}
	foutDOUBLEmem.close();

	return 0;
}
