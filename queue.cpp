#include <iostream>

template <class T>
class Stack;

template <class T>
class List
{
	struct Node
	{
		Node* next_; //незавершенный тип
		T data_;

	public:
		Node(const T& data, Node* next = nullptr)
			: data_{ data }, next_{ next }
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

	const List operator=(const List& obj)
	{
		if (&obj != this)
		{
			clearAll();
			copyList(obj);
		}
		return *this;
	}

	~List()
	{
		clearAll();
	}

	void pushBack(const T& data) //add to end
	{
		if (head_)
		{
			tail_->next_ = new Node(data);
			tail_ = tail_->next_;
		}
		else
			head_ = tail_ = new Node(data);
		++size_;
	}

	void pushFront(const T& data)
	{
		if (head_)
			head_ = new Node(data, head_);
		else
			head_ = tail_ = new Node(data);
		++size_;
	}

	T popBack()
	{
		if (head_)
		{
			T popped = tail_->data_;
			Node* curr = head_;
			if (size_ > 1)
			{
				while (curr->next_ != tail_)
					curr = curr->next_;
				tail_ = curr;

				delete tail_->next_;
				tail_->next_ = nullptr;
			}
			else
			{
				delete head_;
				head_ = tail_ = nullptr;
			}
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
			Node* cur = head_;
			head_ = head_->next_;
			delete cur;
			--size_;
			return popped;
		}
		return T();
	}

	bool search(T value)
	{
		Node* curr = head_;
		while (curr)
		{
			if (curr->data_ == value)
				return true;
		}
		return false;
	}

	bool deleteElem(T value)
	{
		Node* curr = head_;
		Node* prev = nullptr;
		while (curr)
		{
			if (curr->data_ == value)
			{
				if (prev)
					prev->next = curr->next;
				else
					head = curr->next;
				delete curr;
				--size_;
				return true;
			}
			prev = curr;
			curr = curr->next;
		}
		return false;
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const List<T>& lst);

	//template <class T>
	friend class Stack<T>;
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

template <class T>
class Queue
{
	List<T> lst;

public:
	Queue() = default;

	Queue(const T& data)
		: lst(data)
	{
	}

	Queue(const Queue& lst) = default;

	Queue& operator=(const Queue& lst) = default;

	~Queue() = default;

	void push(const T& data)
	{
		lst.pushBack(data);
	}

	T pop()
	{
		return lst.popFront();
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const Queue<T>& q);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Queue<T>& q)
{
	os << q.lst;
	return os;
}

template <class T>
class Stack
{
	List<T> lst;	

public:
	Stack() = default;

	Stack(const T& data)
		: lst(data)
	{
	}

	Stack(const Stack& lst) = default;

	Stack& operator=(const Stack& lst) = default;

	~Stack() = default;

	void push(const T& data)
	{
		lst.pushBack(data);
	}

	T pop()
	{
		return lst.popBack();
	}

	T top()
	{
		return lst.tail_->data_;
	}

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const Stack<T>& s);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Stack<T>& s)
{
	os << s.lst;
	return os;
}

int main()
{
	Queue<int> q(5); //queue for list	
	std::cout << "q = " << q << std::endl;
	q.push(3);
	q.push(-1);
	q.push(10);
	std::cout << "q + 3push = " << q << std::endl;
	q.pop();
	std::cout << "q + pop = " << q << std::endl;
	q.pop();
	std::cout << "q + pop = " << q << std::endl;

	Stack<double> s(10.1);
	std::cout << "s = " << s << std::endl;
	s.push(13.5);
	s.push(20);
	std::cout << "s + 2push = " << s << std::endl;
	s.pop();
	std::cout << "s - pop = " << s << std::endl;
	std::cout << "top s = " << s.top() << std::endl;
	return 0;
}