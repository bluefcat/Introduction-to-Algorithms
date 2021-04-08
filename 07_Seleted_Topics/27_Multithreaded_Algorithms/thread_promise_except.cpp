#include <exception>
#include <future>
#include <iostream>
#include <string>
#include <thread>

using std::string;

void worker(std::promise<string>* p){
	try{
		throw std::runtime_error("some error!");
	}
	catch(...){
		p->set_exception(std::current_exception());
	}
}

int main(){
	std::promise<string> p;
	std::future<string> data = p.get_future();

	std::thread t(worker, &p);
	
	data.wait();

	try{
		data.get();
	}
	catch(const std::exception& e){
		std::cout << e.what() << "\n";
	}

	t.join();
	return 0;

}
