#include <iostream>
#include <stdio.h>
#include <thread>
using std::thread;

void func1(){
	for(int i = 0; i < 10; i ++){
		printf("thread 1 running\n");
	}
	return;
}

void func2(){
	for(int i = 0; i < 10; i ++){
		printf("thread 2 running\n");
	}
	return;
}

void func3(){
	for(int i = 0;i < 10; i ++){
		printf("thread 3 running\n");
	}
	return;
}

int main(){
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.detach();
	t2.detach();
	t3.detach();

	printf("main function end\n");
	return 0;
}
