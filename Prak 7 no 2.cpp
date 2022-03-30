#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int MAXSTACK;
typedef int itemtype;

typedef struct {
 itemtype item[300];
 int count;
}stack;

void initializestack(stack *s) {
 s->count = 0;
}

int empty(stack *s) {
 return (s->count == 0);
}

int full(stack *s) {
 return (s->count == MAXSTACK);
}

void push(itemtype x, stack *s) {
 if(full(s))
  printf("stack penuh !\n");
 else {
  s->item[s->count]=x;
  ++(s->count);
 }
}

int pop(stack *s) {
 if(empty(s))
  printf("stack kosong\n");
 else {
  --(s->count);
  return (s->item[s->count]);
 }
 return 0;
}

//deklarasi
int i, n, m, o,p,pilih;
int num;
stack tumpukan;
void biner();
void oktal();
void heksa();
main() {
 cout<<"-------konversi desimal ke biner oktal dan heksadesimal------"<<endl;
 initializestack(&tumpukan);
 cout<<endl;
 cout<<"masukkan bilangan desimal = "; cin>>num;
 cout<<endl;
 cout<<"_________"<<endl;
 cout<<"|             MENU          |"<<endl;
 cout<<"_________"<<endl;
 cout<<"|1. untuk konversi ke biner |"<<endl;
 cout<<"|2. untuk konversi ke oktal |"<<endl;
 cout<<"|3. untuk konversi ke heksa |"<<endl;
 cout<<"|4. untuk keluar            |"<<endl;
 while(pilih<4){
  cout<<"\npilih :  "; cin>>pilih;
 switch(pilih) {
  case 1:
    cout<<"bilangan binernya = ";
    biner();break;
  case 2:
    cout<<"bilangan oktalnya = ";
    oktal();break;
  case 3:
    cout<<"bilangan heksadesimalnya = ";
    heksa();break;
  case 4:
   cout<<"--tekan enter sekali lagi--";
  }
 }
 getch();
 return 0;
}
//ke oktal
void oktal(){
 for(o=1,n=num;n>0;n=n/8,o++)
  {
   MAXSTACK=o;
   m=n%8;
   push(m,&tumpukan);
  }
 for(i=MAXSTACK;i>0;i--)
  {
  printf("%d", pop(&tumpukan));
  }
}
//ke biner
void biner(){
 for(o=1,n=num;n>0;n=n/2,o++)
  {
   MAXSTACK=o;
   m=n%2;
   push(m,&tumpukan);
  }
  for(i=MAXSTACK;i>0;i--)
  {
  printf("%d", pop(&tumpukan));
  }
}
//ke heksa desimal
void heksa(){
 for(o=1,n=num;n>0;n=n/16,o++)
  {
   MAXSTACK=o;
   m=n%16;
  push(m,&tumpukan);
  }
  for(i=MAXSTACK;i>0;i--)
   {
   p=pop(&tumpukan);
   if(p<=9)
   printf("%d",p);
   else if(p==10)printf("A");
  else if(p==11)printf("B");
  else if(p==12)printf("C");
   else if(p==13)printf("D");
   else if(p==14)printf("E");
   else if(p==15)printf("F");
  }
}
