#pragma onceS

const int MAX_SIZE = 100000000000;

template <class T>
class TQueue
{
	T* pMem;
	int MaxSize;
	int tail;
	int head;
	int DataCount;
public:
	TQueue(int s=10)
	{
		if (s <= 0 || s > MAX_SIZE)
		{
			throw s;
		}
		head = 0;
		tail = -1;
		DataCount = 0;
		MaxSize = s;
		pMem = new T[MaxSize];
	}

	TQueue(const TQueue<T> &q)  //конструктор копирования
	{
		MaxSize = q.MaxSize;
		pMem = new T[MaxSize];
		DataCount = q.DataCount;
		head = q.head;
		tail = q.tail;
		for (int i = 0; i < DataCount; i++)
		{
			pMem[i] = q.pMem[i];
		}
	}

	~TQueue() //деструктор
	{
		delete[]pMem;
	}

	TQueue& operator=(const TQueue<T>& q)
	{
		if (MaxSize != q.MaxSize)
		{
			delete[] pMem;
			MaxSize = q.MaxSize;
			pMem = new T[MaxSize];
		}
		DataCount = q.DataCount;
		head = q.head;
		tail = q.tail;
		for (int i = 0; i < DataCount; i++)
		{
			pMem[i] = q.pMem[i];
		}
		return *this;
	}

	int GetSize()
	{
		return MaxSize;
	}

	int GetDataCount()
	{
		return DataCount;
	}

	bool Empty()
	{
		return DataCount==0;
	}

	bool Full()
	{
		return DataCount == MaxSize;
	}

	T Front() //первый в очереди
	{
		if (Empty())
		{
			throw 0;
		}
		return pMem[head];
	}

	T Back() //последний в очереди 
	{
		if(Empty())
		{
			throw 0; 
		}
		return pMem[tail];
	}

	void Push(T a) //добавить элемент в очередь
	{
		if (Full())
		{
			throw 0;
		}
		DataCount++;
		tail = (tail + 1) % MaxSize;
		pMem[tail] = a;
		
	}

	void Pop() //удалить элемент из очереди
	{
		if (Empty())
		{
			throw 0;
		}
		DataCount--;
		head = (head+1)%MaxSize;
	}

	T& operator[](int pos)
	{
		if (pos < 0 || pos >= MaxSize)
		{
			throw pos;
		}
		return pMem[pos];
	}

	bool operator==(const TQueue<T>& q) const
	{
		if (MaxSize != q.MaxSize || DataCount!=q.DataCount)
		{
			return false;
		}
		for (int i = 0; i < DataCount; i++)
		{
			if (pMem[i] != q.pMem[i])
			{
				return false;
			}
		}
		return true;
	}

	bool operator!=(const TQueue<T>& q) const
	{
		return !(*this == q);
	}

	T GetHead()
	{
		return head;
	}
};
