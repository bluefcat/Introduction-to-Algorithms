#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(int& counter, std::mutex& m){
	for(int i = 0; i < 100000; i ++){
		m.lock();
		counter += 1;
		m.unlock();
	}
	return ;
}

int main(){
	int counter = 0;
	std::mutex m;

	vector<thread> workers;
	for(int i = 0; i < 5; i ++) workers.push_back(thread(worker, std::ref(counter), std::ref(m)));
	for(int i = 0; i < 5; i ++) workers[i].join();

	std::cout << "Counter: " << counter << std::endl;

	return 0;
}
