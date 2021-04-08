#include <chrono>
#include <future>
#include <iostream>
#include <cstdio>
#include <thread>

using std::thread;

void runner(std::shared_future<void>* start, int index){
	start->get();
	printf("#%d GO!\n", index);
}

int main(){
	std::promise<void> p;
	std::shared_future<void> start = p.get_future();

	thread t0(runner, &start, 0);
	thread t1(runner, &start, 1);
	thread t2(runner, &start, 2);
	thread t3(runner, &start, 3);

	std::cerr << "GET\nSET\n";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cerr << "GO\n" << std::endl;

	p.set_value();

	t0.join();
	t1.join();
	t2.join();
	t3.join();

	return 0;
}
