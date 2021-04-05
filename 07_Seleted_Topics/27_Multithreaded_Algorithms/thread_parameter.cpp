#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>

using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result){
	int sum = 0;
	for(auto itr = start; itr < end; ++itr){
		sum += *itr;
	}
	*result = sum;

	thread::id tid = std::this_thread::get_id();
	printf("sum %d to %d on thread %x : %d\n", *start, *(end-1), tid, sum);
}

int main(){
	vector<int> data(10000);
	for(int i = 0; i < 10000; i ++){
		data[i] = i;
	}

	vector<int> partial_sum(4);

	vector<thread> workers;
	for(int i = 0; i < 4; i ++){
		workers.push_back(thread(worker, data.begin()+i*2500, data.begin()+(i+1)*2500, &partial_sum[i]));
	}

	for(int i = 0; i < 4; i ++) workers[i].join();

	int total = 0;
	for(int i = 0; i < 4; i ++) total += partial_sum[i];

	printf("total sum: %d\n", total);
	return 0;
}
