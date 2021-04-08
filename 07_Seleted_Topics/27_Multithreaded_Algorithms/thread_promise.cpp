#include <iostream>
#include <future>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string>* p){
	p->set_value("some data");
}

int main(){
	std::promise<string> p;
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);
	data.wait();

	std::cout << "Get data: " << data.get() << std::endl;

	t.join();
	return 0;
}
