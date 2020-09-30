#include <stdio.h>
#include <math.h>
void func_addr(void*);
int main(void)
{
	func_addr(cos);
	func_addr(main);
	return 0;
}
void func_addr(void *f)
{
	if(f == cos)
	   printf("cos() 함수 주소 :%p\n", (double (*)(double))f);
	else
		printf("함수의 주소:%p\n", (int (*)(void))f);
}

//다른 형식의 함수 주소를 같은 함수에서 다루고 싶은 때 : void* 로 주소 받고 cast 연산자 사용해서 값 확인하기
//void (*)()는 void형을 반환값으로 갖고 void형을 매개변수로 갖는 함수 포인터임.
//void* 와 역할이 완전히 다름
