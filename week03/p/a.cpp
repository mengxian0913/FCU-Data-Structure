#include<stdio.h>
#include<stdlib.h>

#define MAX 10

struct MyBin
{
	int bin[MAX];
	void DecToBin(int);
	MyBin();
  int FindFirstZero();
  void NotBin(int, int);
  void printOut();
};

int main()
{
  MyBin Bin;
  int n;
  scanf("%d", &n);
  Bin.DecToBin(n);
  Bin.NotBin(7, 0);
  int firstzero = Bin.FindFirstZero();
  Bin.printOut();
	return 0;
}

//================================
MyBin::MyBin()
{
	for(int i=0;i<MAX;i++)
	{
		bin[i]=0;
	}
}

//================================
void MyBin::DecToBin(int num)
{
  if(num < 0) {
    num *= -1;
  }
  for(int i=0; i<MAX; i++) {
    bin[i] = (num >> i) & 1;
  }
  return;
}

//================================

void MyBin::printOut() {
  for(int i = 7; i >= 0; i--) {
    printf("%d", bin[i]);
  }
  puts("");
  return;
}

//================================

int MyBin::FindFirstZero() {
  int firstzero = -1;
  for(int i = 0; i< MAX; i++){
    if(bin[i] == 0) {
      firstzero = i;
      break;
    }
  }
  for(int i = firstzero; i >= 0; i--){
    bin[i] ^= 1;
  }

  return firstzero;
}

//================================

void MyBin::NotBin(int from, int to) {
  for(int i = to; i <= from; i++) {
    bin[i] ^= 1;
  }
  return;
}
