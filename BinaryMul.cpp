#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 10진수 2수를 받아 2진수로 변환시키고 각 비트를 시프트 연산하면서
// 각 행의 연산을 출력시키고 마지막에 결과를 출력한다.

static char multiArray[100];               // strlen()를 사용하기 위해 char 배열로 선언
static char multiCArray[100];              // 초기에 배열의 크기를 지정하지 않기 때문에 정적 배열을 사용.
static int index = 0;                       // 사이클의 횟수와 십진수를 이진수 변환시의 배열에 역순으로 저장하기 위한 인덱스 표현

void initialScreen();                       // 초기화면 출력
void decimalToBinary(char* array, int num); // 10진수 2진수 변환시 사용되는 Function
char* createBinaryArray(int num);           // 두 수 중에서 더 큰 비트를 사용하는 수의 비트수 만큼 채용(동적 할당)
void showBinaryArray(char* array);          // 배열을 수직으로 출력하기 위한 Function
void showBinaryArray2(char* array);         // 배열을 수평으로 출력하기 위한 Function
void showBinaryArray3(char* array);         // 마지막 출력을 위한 Function
int max(int num1, int num2);                // 사이클 수를 정하기 위한 Function
void beatSync();                            // 이진수 배열의 비트 수를 동기화 한다.
void binaryMultiply(int finalCycle);        // 부호없는 이진수 곱하기 연산 Function

int main()
{
	int multiplier, multiplicand, semiCycle1, semiCycle2, finalCycle;
	initialScreen(); printf("Multiplier(피승수) : "); scanf("%d", &multiplier);
	printf("Multiplicand(승수) : "); scanf("%d", &multiplicand); printf("\n");

	decimalToBinary(multiArray ,multiplier);
	semiCycle1 = index; index = 0;                // static 전역 변수이기 때문에 다시 0으로 변환.
	decimalToBinary(multiCArray ,multiplicand);
	semiCycle2 = index;
	finalCycle = max(semiCycle1, semiCycle2);     // 사이클 수를 정하기 위함.

	printf("Multiplier(피승수) : "); showBinaryArray(multiArray);
	printf("Multiplicand(승수) : "); showBinaryArray(multiCArray); printf("\n");

	if ((int)strlen(multiCArray) != (int)strlen(multiArray)) { beatSync(); } // 두 2진수 배열의 비트수가 다르다면 비트 동기화 시행.
	binaryMultiply(finalCycle);   // 본격적인 시프트 곱하기연산 시작.
}

void initialScreen()
{
	printf("\t\t\t\t\t||*****************************||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*   부호없는 이진수 곱셈!   *||\n");
	printf("\t\t\t\t\t||*   (Shift 연산 구현하기)   *||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*****************************||\n\n");
}

void decimalToBinary(char* array, int num) 
{
	if (num > 1)
	{
		decimalToBinary(array, num / 2);          // 재귀 호출을 이용하여 나누었을 때 몫이 없어질때까지 파고든다.
	}
	array[index] = (num % 2) + '0';               // char 타입이기 떄문에 '0'을 더하여 문자로 1과 0을 표현.
	index++;                                      // 마지막으로 나온 나머지를 첫 번째 방으로 저장.(즉 역순으로 저장하기 위함이다.)
}

char* createBinaryArray(int num)
{
	char* arr = (char*)calloc(num, sizeof(int));  // 0배열로 배열을 초기화 시켜주는 calloc() 사용
	for (int i = 0; i < num; i++)
	{
		arr[i] = '0';
	}

	return arr;
}

void showBinaryArray(char* array)
{
	for (int i = 0; i < (int)strlen(array); i++)
	{
		printf("%c", array[i]);
	}
	printf("\n");
}

void showBinaryArray2(char* array)
{
	for (int i = 0; i < (int)strlen(array); i++)
	{
		printf("%c", array[i]);
	}
	printf("  ");
}

void showBinaryArray3(char* array)
{
	for (int i = 0; i < (int)strlen(array); i++)
	{
		printf("%c", array[i]);
	}
}

int max(int num1, int num2)                      
{
	return (num1 > num2) ? num1 : num2;          // 삼항연산을 사용하여 더 큰 값을 리턴
}

void beatSync()
{
	printf("\t\t\t\t\t||*****************************||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*   \"Beat Syncronization\"   *||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*****************************||\n\n");
	
	int arryLenA = (int)strlen(multiArray);
	int arryLenCA = (int)strlen(multiCArray);

	if (arryLenA < arryLenCA)
	{
		index = 0;  // static 변수 사용.
		char* pre = (char*)calloc(arryLenCA, sizeof(char));

		for (int i = 0; i < arryLenCA; i++)
		{
			if (i < (arryLenCA - arryLenA))
			{
				pre[i] = '0';
			}
			else
			{
				pre[i] = multiArray[index++];
			}
		}

		for (int i = 0; i < arryLenCA; i++)
		{
			multiArray[i] = pre[i];
		}

		free(pre);
	}

	else if (arryLenA > arryLenCA)
	{
		index = 0;
		char* pre = (char*)calloc(arryLenA, sizeof(char));

		for (int i = 0; i < arryLenA; i++)
		{
			if (i < (arryLenA - arryLenCA))
			{
				pre[i] = '0';
			}
			else
			{
				pre[i] = multiCArray[index++];
			}
		}

		for (int i = 0; i < arryLenA; i++)
		{
			multiCArray[i] = pre[i];
		}

		free(pre);
	}
	printf("Multiplier(피승수) : "); showBinaryArray(multiArray);
	printf("Multiplicand(승수) : "); showBinaryArray(multiCArray); printf("\n\n");
}

void binaryMultiply(int finalCycle)
{
	printf("\t\t\t\t\t||*****************************||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*     \"Binary Multiply\"     *||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*****************************||\n\n");

	// 계산에 사용될 각각의 레지스터들을 초기화한다. C = Carry
	char* M = createBinaryArray(finalCycle); strcpy(M, multiArray);
	char* A = createBinaryArray(finalCycle);
	char* Q = createBinaryArray(finalCycle); strcpy(Q, multiCArray);
    char C = '0', move = '0'; // move 변수는 A레지스터에서 Q레지스터로 넘어가는 값이다.
	int ctr = 1;
	printf("\"초기상태\"\n");
	printf("Cylce = %d ", finalCycle);
	printf("M = "); showBinaryArray2(M); printf("\n");
	printf("Carry = %c ", C);
	printf("A = "); showBinaryArray2(A);
	printf("Q = "); showBinaryArray2(Q); printf("\n");
	


	for (int i = finalCycle - 1; i >= 0; i--)
	{
		printf("\n\"사이클 %d\"\n", ctr++);

		if (Q[finalCycle - 1] == '1')      // Q0가 1이라면 // A = A + M 후에 R_shift
		{
			for (int j = finalCycle - 1; j >= 0; j--)        // '1' = 49 , '0' = 48 - 아스키 코드값 이용
			{
				if (C == '0')                                // 캐리 발생 유무 체크 : 0일때
				{
					if (A[j] + M[j] == 98)                   // 1, 1 case
					{
						C = '1';
						A[j] = '0';
						continue;
					}

					else if (A[j] + M[j] == 97)              // 0, 1 or 1, 0 case
					{
						C = '0';
						A[j] = '1';
						continue;
					}

					else if (A[j] + M[j] == 96)              // 0, 0 case
					{
						C = '0';
						A[j] = '0';
						continue;
					}
				}

				if (C == '1')                                // 캐리 발생 유무 체크 : 1일때
				{
					if (A[j] + M[j] == 98)                   // 1, 1 case
					{
						C = '1';
						A[j] = '1';
						continue;
					}

					else if (A[j] + M[j] == 97)              // 0, 1 or 1, 0 case
					{
						C = '1';
						A[j] = '0';
						continue;
					}

					else if (A[j] + M[j] == 96)              // 0, 0 case
					{
						C = '0';
						A[j] = '1';
						continue;
					}
				}
			}
			printf("Carry = %c ", C);
			printf("A = "); showBinaryArray2(A);
			printf("Q = "); showBinaryArray2(Q); printf("A -> A + M\n");

			move = A[finalCycle - 1];                  // A 레지스터의 마지막 원소를 저장한다.(넘겨주기 위함.)
			for (int j = finalCycle - 1; j >= 0; j--)  // A = A + M 이 끝났으므로 R_shift
			{
				if (j == 0) { A[j] = C; Q[j] = move; }
				else { A[j] = A[j - 1]; Q[j] = Q[j - 1]; }
			}
			C = '0';                                   // R_shift 연산이 끝났으므로 캐리값을 0으로 저장.

			printf("Carry = %c ", C);
			printf("A = "); showBinaryArray2(A);
			printf("Q = "); showBinaryArray2(Q); printf("R_shift\n");
		}

		else if (Q[finalCycle - 1] == '0') // Q0가 0이라면 // R_shift
 		{
			move = A[finalCycle - 1]; 
			for (int j = finalCycle - 1; j >= 0; j--)
			{
				if (j == 0) { A[j] = C; Q[j] = move; }
				else { A[j] = A[j - 1]; Q[j] = Q[j - 1]; }
			}
			C = '0';

			printf("Carry = %c ", C);
			printf("A = "); showBinaryArray2(A);
			printf("Q = "); showBinaryArray2(Q); printf("R_shift\n");
		}
	}

	printf("\n결과값 : %c", C); showBinaryArray3(A); showBinaryArray3(Q); printf("(2)\n");;
}