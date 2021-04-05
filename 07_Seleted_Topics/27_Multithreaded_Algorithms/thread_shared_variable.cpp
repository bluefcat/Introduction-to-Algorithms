#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(int& counter){
	for(int i = 0; i < 100000; i ++){
		counter += 1;
	}
	return ;
}

int main(){
	int counter = 0;
	
	vector<thread> workers;
	for(int i = 0; i < 5; i ++) workers.push_back(thread(worker, std::ref(counter)));
	for(int i = 0; i < 5; i ++) workers[i].join();

	std::cout << "Counter: " << counter << std::endl;

	return 0;
}
