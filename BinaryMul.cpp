#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 10���� 2���� �޾� 2������ ��ȯ��Ű�� �� ��Ʈ�� ����Ʈ �����ϸ鼭
// �� ���� ������ ��½�Ű�� �������� ����� ����Ѵ�.

static char multiArray[100];               // strlen()�� ����ϱ� ���� char �迭�� ����
static char multiCArray[100];              // �ʱ⿡ �迭�� ũ�⸦ �������� �ʱ� ������ ���� �迭�� ���.
static int index = 0;                       // ����Ŭ�� Ƚ���� �������� ������ ��ȯ���� �迭�� �������� �����ϱ� ���� �ε��� ǥ��

void initialScreen();                       // �ʱ�ȭ�� ���
void decimalToBinary(char* array, int num); // 10���� 2���� ��ȯ�� ���Ǵ� Function
char* createBinaryArray(int num);           // �� �� �߿��� �� ū ��Ʈ�� ����ϴ� ���� ��Ʈ�� ��ŭ ä��(���� �Ҵ�)
void showBinaryArray(char* array);          // �迭�� �������� ����ϱ� ���� Function
void showBinaryArray2(char* array);         // �迭�� �������� ����ϱ� ���� Function
void showBinaryArray3(char* array);         // ������ ����� ���� Function
int max(int num1, int num2);                // ����Ŭ ���� ���ϱ� ���� Function
void beatSync();                            // ������ �迭�� ��Ʈ ���� ����ȭ �Ѵ�.
void binaryMultiply(int finalCycle);        // ��ȣ���� ������ ���ϱ� ���� Function

int main()
{
	int multiplier, multiplicand, semiCycle1, semiCycle2, finalCycle;
	initialScreen(); printf("Multiplier(�ǽ¼�) : "); scanf("%d", &multiplier);
	printf("Multiplicand(�¼�) : "); scanf("%d", &multiplicand); printf("\n");

	decimalToBinary(multiArray ,multiplier);
	semiCycle1 = index; index = 0;                // static ���� �����̱� ������ �ٽ� 0���� ��ȯ.
	decimalToBinary(multiCArray ,multiplicand);
	semiCycle2 = index;
	finalCycle = max(semiCycle1, semiCycle2);     // ����Ŭ ���� ���ϱ� ����.

	printf("Multiplier(�ǽ¼�) : "); showBinaryArray(multiArray);
	printf("Multiplicand(�¼�) : "); showBinaryArray(multiCArray); printf("\n");

	if ((int)strlen(multiCArray) != (int)strlen(multiArray)) { beatSync(); } // �� 2���� �迭�� ��Ʈ���� �ٸ��ٸ� ��Ʈ ����ȭ ����.
	binaryMultiply(finalCycle);   // �������� ����Ʈ ���ϱ⿬�� ����.
}

void initialScreen()
{
	printf("\t\t\t\t\t||*****************************||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*   ��ȣ���� ������ ����!   *||\n");
	printf("\t\t\t\t\t||*   (Shift ���� �����ϱ�)   *||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*****************************||\n\n");
}

void decimalToBinary(char* array, int num) 
{
	if (num > 1)
	{
		decimalToBinary(array, num / 2);          // ��� ȣ���� �̿��Ͽ� �������� �� ���� ������������ �İ���.
	}
	array[index] = (num % 2) + '0';               // char Ÿ���̱� ������ '0'�� ���Ͽ� ���ڷ� 1�� 0�� ǥ��.
	index++;                                      // ���������� ���� �������� ù ��° ������ ����.(�� �������� �����ϱ� �����̴�.)
}

char* createBinaryArray(int num)
{
	char* arr = (char*)calloc(num, sizeof(int));  // 0�迭�� �迭�� �ʱ�ȭ �����ִ� calloc() ���
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
	return (num1 > num2) ? num1 : num2;          // ���׿����� ����Ͽ� �� ū ���� ����
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
		index = 0;  // static ���� ���.
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
	printf("Multiplier(�ǽ¼�) : "); showBinaryArray(multiArray);
	printf("Multiplicand(�¼�) : "); showBinaryArray(multiCArray); printf("\n\n");
}

void binaryMultiply(int finalCycle)
{
	printf("\t\t\t\t\t||*****************************||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*     \"Binary Multiply\"     *||\n");
	printf("\t\t\t\t\t||*                           *||\n");
	printf("\t\t\t\t\t||*****************************||\n\n");

	// ��꿡 ���� ������ �������͵��� �ʱ�ȭ�Ѵ�. C = Carry
	char* M = createBinaryArray(finalCycle); strcpy(M, multiArray);
	char* A = createBinaryArray(finalCycle);
	char* Q = createBinaryArray(finalCycle); strcpy(Q, multiCArray);
    char C = '0', move = '0'; // move ������ A�������Ϳ��� Q�������ͷ� �Ѿ�� ���̴�.
	int ctr = 1;
	printf("\"�ʱ����\"\n");
	printf("Cylce = %d ", finalCycle);
	printf("M = "); showBinaryArray2(M); printf("\n");
	printf("Carry = %c ", C);
	printf("A = "); showBinaryArray2(A);
	printf("Q = "); showBinaryArray2(Q); printf("\n");
	


	for (int i = finalCycle - 1; i >= 0; i--)
	{
		printf("\n\"����Ŭ %d\"\n", ctr++);

		if (Q[finalCycle - 1] == '1')      // Q0�� 1�̶�� // A = A + M �Ŀ� R_shift
		{
			for (int j = finalCycle - 1; j >= 0; j--)        // '1' = 49 , '0' = 48 - �ƽ�Ű �ڵ尪 �̿�
			{
				if (C == '0')                                // ĳ�� �߻� ���� üũ : 0�϶�
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

				if (C == '1')                                // ĳ�� �߻� ���� üũ : 1�϶�
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

			move = A[finalCycle - 1];                  // A ���������� ������ ���Ҹ� �����Ѵ�.(�Ѱ��ֱ� ����.)
			for (int j = finalCycle - 1; j >= 0; j--)  // A = A + M �� �������Ƿ� R_shift
			{
				if (j == 0) { A[j] = C; Q[j] = move; }
				else { A[j] = A[j - 1]; Q[j] = Q[j - 1]; }
			}
			C = '0';                                   // R_shift ������ �������Ƿ� ĳ������ 0���� ����.

			printf("Carry = %c ", C);
			printf("A = "); showBinaryArray2(A);
			printf("Q = "); showBinaryArray2(Q); printf("R_shift\n");
		}

		else if (Q[finalCycle - 1] == '0') // Q0�� 0�̶�� // R_shift
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

	printf("\n����� : %c", C); showBinaryArray3(A); showBinaryArray3(Q); printf("(2)\n");;
}