// КурсачЭВМ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include <iostream>
#include <conio.h> 
#include <windows.h> 
#include <stdio.h>
#include <time.h>
#include <vector> 
#include <fstream>

using namespace std; 
int main()
{
	const int N = 1000;
	int a, b, out = 0;
	
	clock_t start, stop; setlocale(LC_ALL, "rus");
	typedef std::vector<long double> proportions; proportions rezults;
	typedef std::vector<long double> proportions; proportions rezults2;
	for (int q = 0; q != 200; ++q) 
	{ rezults.push_back(0); } 
	for (int q = 0; q != 200; ++q) 
	{ rezults2.push_back(0); }

	std::cout << "Введите значения:\n"; std::cin >> a;
	std::cin >> b;
	int copy_b = b * (-1); int i = 0, j = 0; float t = 0;

	//сложение
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
	rezults[i] = (t) / CLOCKS_PER_SEC;
	//сложение
	std::cout << "Сложение: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	++i;
	out = 0;

	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{
			rdtsc 
			mov start, eax 
			mov ecx, a 
			add ecx,b 
			mov out, ecx 
			rdtsc 
			mov stop, eax
		}
		t += (abs(stop - start));
	}

	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	//вычитание 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			mov ecx,[a] 
			mov edx,[b] 
			sub ecx, edx 
			mov[out], ecx 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;

	std::cout << "Вычитание: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	++i;
	out = 0;

	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{
			rdtsc 
			mov[start], eax 
			mov ecx,[a] 
			sub ecx,[b] 
			mov[out], ecx 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	//умножение 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			mov eax,[a] 
			mov ebx,[b] 
			mul ebx 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Умножение: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;
	//умножение 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			mov eax,[a] 
			mul [b] 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;

	rezults2[j] = (t) / CLOCKS_PER_SEC;

	std::cout << "Умножение: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;


	//умножение со знаком
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			mov eax,[a]
			mov ebx,[copy_b] 
			neg ebx
			imul ebx 
			neg eax
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Умножение со знаком: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;


	//умножение со знаком
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			mov eax,[a] 
			neg eax 
			imul[copy_b] 
			neg eax 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;
	std::cout << "Умножение со знаком: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	//деление

	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			rdtsc 
			mov[start], eax 
			xor eax, edx 
			xor edx, edx 
			mov eax,[a] 
			mov ebx,[b] 
			div ebx 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC; 
	std::cout << "Деление: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;

	//деление 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm
		{
			/*rdtsc mov[start], eax*/ 
			xor ebx, ebx
			xor eax, eax

			rdtsc 
			mov[start], eax 
			mov eax,[a] 
			xor edx, edx 
			div[b] 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC; std::cout << "Деление: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;


	//деление со знаком
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			rdtsc 
			mov[start], eax 
			xor eax, edx 
			xor edx, edx 
			mov eax,[a]
		 	mov ebx,[copy_b] 
			neg ebx
			idiv ebx 
			neg eax
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;

	std::cout << "Деление со знаком: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;

	//деление со знаком
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			xor ebx, ebx 
			xor eax, eax


			rdtsc 
			mov[start], eax 
			mov eax,[a] 
			xor edx, edx 
			idiv[b]
			neg eax 
			mov[out], eax 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;
	std::cout << "Деление со знаком: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	

	//Декремент 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			//sub ebx, ebx
			rdtsc 
			mov[start], eax 

			//sub ebx, 1001
			mov ebx,[a] 
			dec ebx 
			mov [out], ebx

			rdtsc 
			mov[stop], eax

		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Декремент: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;



	//Декремент 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			mov ebx,a
			rdtsc 
			mov[start], eax 
			sub ebx, 1
			//dec [a]
			mov [out], ebx
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;
	std::cout << "Декремент: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	//Изменение знака операнда
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			rdtsc 
			mov[start], eax 
			mov ebx,[a] 
			neg ebx 
			mov[out], ebx 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;

	std::cout << "Изменение знака операнда: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;


	//Изменение знака операнда
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			//mov ebx,[a] 
			rdtsc 
			mov[start], eax 
			neg [a]
			mov[out], ebx 
			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;

	std::cout << "Изменение знака операнда: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;

	//создаём объект класса ofstream для записи и связываем его с файлом data1.txt 
	//Инкремент 
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			rdtsc 
			mov[start], eax 

			mov ebx,[a]
			inc ebx 
			mov[out], ebx 

			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults[i] = (t) / CLOCKS_PER_SEC;
	std::cout << "Инкремент: " << out << "\n";
	std::cout << "Среднее время операции с использованием регистров: " << rezults[i] << endl;
	std::cout << endl; i++;
	out = 0;

	//Инкремент 
	
	t = 0;
	for (int i = 0; i < N; i++) {
		__asm{

			rdtsc 
			mov[start], eax

			inc [a] 
			mov[out], ebx

			rdtsc 
			mov[stop], eax
		}
		t += (abs(stop - start));
	}
	t /= N;
	rezults2[j] = (t) / CLOCKS_PER_SEC;

	std::cout << "Инкремент: " << out << "\n";
	std::cout << "Среднее время операции без использованием регистров: " << rezults2[j] << endl;
	std::cout << endl; j++;
	out = 0;

	float af = 3.7, bf = 1.1, outf = 0.0;
	long double time = 0.0;

	for (int i = 0; i < N; i++) {
		__asm {

			rdtsc
			mov [start], eax

			fld af
			fadd bf
			fstp outf

			rdtsc
			mov [stop], eax
		}
		time += (abs(stop - start));
	}
	time /= N;
	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;
	time = 0.0;

	__asm {
		rdtsc
		mov start, eax

		fld af
		fadd bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;
	time = 0.0;

	__asm {
		rdtsc
		mov start, eax

		fld af
		fsub bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;




	time = 0.0;

	__asm {
		rdtsc
		mov start, eax

		fld af
		fmul bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;


	time = 0.0;

	__asm {
		rdtsc
		mov start, eax

		fld af
		fdiv bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;


	time = 0.0;
	bf = -1 * bf;
	__asm {
		rdtsc
		mov start, eax

		fld af
		fmul bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;


	time = 0.0;
	//bf = -1 * bf;
	__asm {
		rdtsc
		mov start, eax

		fld af
		fdiv bf
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;


	time = 0.0;
	bf = -1 * bf;
	__asm {
		rdtsc
		mov start, eax

		fld af
		fchs
		fstp outf

		rdtsc
		mov stop, eax
	}
	time = abs(stop - start);

	std::cout << outf << "   " << (time) / CLOCKS_PER_SEC << endl;


	/*ofstream fout("data1.txt");
	for (int i = 0; i < 9; i++) {
		fout << rezults[i] << endl;
	}
	fout.close();

	ofstream fout1("data2.txt"); 
	for (int i = 0; i < 9; i++) {
		fout1 << rezults2[i] << endl;
	}
	fout1.close();
	*/
	return 0;
}
