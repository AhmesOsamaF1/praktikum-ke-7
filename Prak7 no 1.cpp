#include <iostream>
#include <stdio.h>
#define MAKS 40
using namespace std;

int p = 0;
typedef char tipe;

typedef struct {
	char item[MAKS];
	int count;
} Stack;

void insialisasi(Stack *S) {
	S->count = 0;
}
int penuh(Stack *S) {
	return (S->count == MAKS);
}
int kosong(Stack *S) {
	return (S->count == 0);
}
void push(tipe x, Stack *S) {
	if (penuh(S))
		cout<<"Stack tidak dapat masuk karena sudah penuh"<<endl;
	else {
		S->item[S->count] = x;
		printf("Stack berada di diindex ke %d\n", x, S->count);
		++(S->count);
	}
}

int pop(Stack *S, char cetak[MAKS]) {
	if (kosong(S))
		printf("Stack masih kosong\n");
	else {
		--(S->count);
		cetak[p] = S->item[S->count];
		printf("%c Telah keluar dari stack\n", S->item[S->count]);
	}
	return p;
}

void isi(Stack *S) {
	int a = 0;
	printf("Hasil : ");
	while (a < S->count)
		printf("%c", S->item[a++]);
		printf("\n");
	}

int main() {
	char cetak[MAKS];
	int a, b, c;
	char input;
	Stack tumpukan;
	insialisasi(&tumpukan);

	printf("Masukkan input, jika input char maka push stack dan jika input operator maka pop lalu cetak hasilnya\n");

	for (a = 0; a != MAKS; a++) {
		printf("Input : ");
		scanf("%c", &input);
		fflush(stdin);

		if (input == '*' || input == '/' || input == '-' || input == '+') {
			c = pop(&tumpukan, cetak);
			isi(&tumpukan);
			b = 0;
			while (b < p)
				printf(" %d\n", cetak[b++]);
			}
		else if (input == '^') {
			break;
		}else
			push(input, &tumpukan);
	}

	for (a = 0; a < c; a++) {
		printf("%c ", cetak[a]);}
}
