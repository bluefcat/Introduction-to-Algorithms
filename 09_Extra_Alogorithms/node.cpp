#include <iostream>

template <typename T>
class Node{
	public:
		Node(T content): content_(content){
			next_ = nullptr;
		}

		void PushBack(Node<T>* next){
			if(next_ == nullptr){
				next_ = next;
				return;
			}

			Node<T>* target = next_;
			while(target->next_ != nullptr){
				target = target->next_;
			}

			target->next_ = next;
			return;
		}

		friend std::ostream& operator<<(std::ostream& os, const Node& n){
			return os << "[" << n.content_ << "]";
		}

		template <typename U>
		class iterator_ {
			public:
				explicit iterator_(Node<U>* current): current_(current){}
				
				bool operator!=(const iterator_<U>& other){
					return current_ != other.current_;
				}

				iterator_<U>& operator++(){
					current_ = current_->next_;
					return *this;
				}

				Node<U>& operator*() {
					return *current_;
				}

			public:
				Node<U>* current_;
				
		};

		using iterator = iterator_<T>;

		iterator begin(){
			return iterator{this};
		}

		iterator end(){
			return iterator{nullptr};
		}

	private:
		T content_;
		Node<T>* next_;
};


int main(){
	Node<int>* n1 = new Node<int>(1);
	Node<int>* n2 = new Node<int>(2);
	Node<int>* n3 = new Node<int>(3);
	Node<int>* n4 = new Node<int>(4);
	Node<int>* n5 = new Node<int>(6);

	n1->PushBack(n2);
	n1->PushBack(n3);
	n1->PushBack(n4);
	n1->PushBack(n5);


	for(Node<int>::iterator it = n1->begin(); it != n1->end(); ++it){
		std::cout << (*it) << " << ";
	}
	std::cout << "\n";

	for(Node<int> n: *n1){
		std::cout << n << " << ";
	}
	std::cout << "\n";

	delete n1;
	delete n2;
	delete n3;
	return 0;
}
