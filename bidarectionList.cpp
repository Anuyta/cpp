#include <iostream>

template <class T>
class List
{
	struct Node
	{
		Node* prev_;
		Node* next_;		
		T data_;

	public:
		Node(const T& data, Node* prev = nullptr, Node* next = nullptr)
			: data_{ data }, prev_{ prev }, next_{ next }
		{
		}
	};

	Node* head_ = nullptr;
	Node* tail_ = nullptr;
	int size_ = 0;

	void clearAll()
	{
		Node* nxt = nullptr;
		while (head_)
		{
			nxt = head_->next_;
			delete head_;
			head_ = nxt;
		}
		size_ = 0;
	}

	void copyList(const List& obj)
	{
		Node* curr = obj.head_;
		while (curr)
		{
			pushBack(curr->data_);
			curr = curr->next_;
			++size_;
		}
	}

public:
	List() = default;

	List(const T& data)
		: head_{ new Node(data) }, tail_{ head_ }, size_{ 1 }
	{
	}

	List(const List& obj)
	{
		copyList(obj);
	}

	~List()
	{
		clearAll();
	}

	const List operator=(const List& obj)
	{
		if (&obj != this)
		{
			clearAll();
			copyList(obj);
		}
		return *this;
	}

	void pushBack(const T& data) //add to end
	{
		if (head_)
		{			
			tail_->next_ = new Node(data, tail_);
			tail_ = tail_->next_;
		}
		else
			head_ = tail_ = new Node(data);
		++size_;
	}

	void pushFront(const T& data)
	{
		if (head_)
		{
			head_->prev_ = new Node(data, nullptr, head_);
			head_ = head_->prev_;
		}
		else
			head_ = tail_ = new Node(data);
		++size_;
	}

	T popBack()
	{
		if (head_)
		{
			T popped = tail_->data_;	
			Node* curr = tail_->prev_;			
			delete tail_;
			tail_ = curr;
			if (tail_)
				tail_->next_ = nullptr;
			--size_;
			return popped;
		}
		return T();
	}

	T popFront()
	{
		if (head_)
		{
			T popped = head_->data_;	
			Node* curr = head_;
			head_ = head_->next_;	
			if (head_)//if 1 element on list
				head_->prev_ = nullptr;
			delete curr;			
			--size_;
			return popped;
		}
		return T();
	}

	

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const List<T>& lst);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& lst)
{
	List<T>::Node* curr = lst.head_;
	while (curr)
	{
		os << curr->data_ << " ";
		curr = curr->next_;
	}
	return os;
}

int main()
{
	List<int> lstd(5), lstd1(1), lstd2(3);
	lstd.pushFront(3);
	std::cout << "lstd + pushFront = " << lstd << std::endl;
	lstd.pushFront(7);
	std::cout << "lstd pushFront = " << lstd << std::endl;
	lstd.pushBack(10);
	std::cout << "lstd pushBack = " << lstd << std::endl;
	std::cout << "lstd popFront = " << lstd.popFront() << std::endl;
	std::cout << "lstd = " << lstd << std::endl;
	lstd.pushFront(0);
	std::cout << "lstd pushBack = " << lstd << std::endl;

	std::cout << "lstd1 = " << lstd1 << std::endl;
	std::cout << "lstd1 popFront = " << lstd1.popFront() << std::endl;
	std::cout << "lstd1 = " << lstd1 << std::endl;

	std::cout << "lstd popBack = " << lstd.popBack() << std::endl;
	std::cout << "lstd = " << lstd << std::endl;
	lstd.pushBack(33);
	std::cout << "lstd pushBack = " << lstd << std::endl;

	std::cout << "lstd2 = " << lstd2 << std::endl;
	std::cout << "lstd2 popBack = " << lstd2.popFront() << std::endl;
	std::cout << "lstd2 = " << lstd2 << std::endl;
	return 0;
}