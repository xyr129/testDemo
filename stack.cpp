#include<iostream>
using namespace std;

typedef int  elemType;
#define ERROR -1
class Stack
{
public:
	Stack(size_t m = 10)
		:max(m)
	{
		array = new elemType[max];
		stack_top[0] = -1;
		stack_top[1] = max;
	}
	Stack(Stack& s)
	{
		max = s.max;
		array = new elemType[max];
		stack_top[0] = s.stack_top[0];
		stack_top[1] = s.stack_top[1];
		for (size_t i = 0; i < max; ++i)
		{
			array[i] = s.array[i];
		}
	}
	Stack& operator=(Stack& s)
	{
		if (array == s.array)
		{
			return *this;
		}
		max = s.max;
		stack_top[0] = stack_top[0];
		stack_top[1] = stack_top[1];
		delete array;
		array = new elemType[max];
		for (size_t i = 0; i < max; ++i)
		{
			array[i] = s.array[i];
		}
	}
	~Stack()
	{
		delete array;
	}
public:
	bool empty(size_t n)
	{
		if (stack_top[n] == -1 || stack_top[n] == max)
		{
			return true;
		}
		return false;
	}
	const elemType& top(size_t n)
	{
		if (n != 0 && n != 1)
		{
			cout << "the stack number is wrong" << endl;
		}
		else
		{
			if (empty(n))
			{
				cout << "stack is empty" << endl;
			}
			return array[stack_top[n]];
		}
	}
	void push(size_t n, elemType e)
	{
		if (n != 0 && n != 1)
		{
			cout << "the stack number is wrong"<<endl;
		}
		else
		{
			if (stack_top[1] - 1 == stack_top[0] )
			{
				cout << "full" << endl;
			}
			else
			{
				n == 0 ? ++stack_top[n] : --stack_top[n];
				array[stack_top[n]] = e;
			}
		}
	}
	elemType pop(size_t n)
	{
		elemType ret = ERROR;
		if (n != 0 && n != 1)
		{
			cout << "the stack number is wrong" << endl;
		}
		else
		{
			if (!empty(n))
			{
				ret = array[stack_top[n]];
				n == 0 ? --stack_top[n] : ++stack_top[n];
			}
		}
		return ret;
	}
	void print(size_t n)
	{
		if (!empty(n))
		{
			if (0 == n)
			{
				for (size_t i = 0; i <= stack_top[n]; ++i)
				{
					cout << array[i] << "->";
				}
				cout << endl;
			}
			else if (1 == n)
			{
				for (size_t i = max - 1; i >= stack_top[n]; --i)
				{
					cout << array[i] << "->";
				}
				cout << endl;
			}
			
		}
		else
		{
			cout << "stack is empty" << endl;
		}
	}
private:
	elemType *array;
	size_t max;
	int stack_top[2];
};

void Test1()
{
	Stack s1(3);
	//Õ»1ÈëÕ»
	cout << "Õ»1ÈëÕ»" << endl;
	s1.push(0, 1); 
	s1.push(0, 2);
	s1.push(0, 3);
	s1.print(0);
	//Õ»1³öÕ»
	cout << "Õ»1³öÕ»" << endl;
	for (int i = 0; i < 3; ++i)
	{
		s1.pop(0);
		s1.print(0);
	}
}
void Test2()
{
	Stack s2(6);
	s2.push(0, 1);
	s2.push(1, 2);
	s2.push(0, 3);
	s2.push(1, 4);
	s2.push(0, 5);
	s2.push(1, 6);

	cout << "Õ»1ÈëÕ»" << endl;
	s2.print(0);
	cout << "Õ»2ÈëÕ»" << endl;
	s2.print(1);
	
	cout << "Õ»1ÈëÕ»" << endl;
	s2.push(0,7);
	
}
int main()
{
	//Test1();
	Test2();
	system("pause");
	return 0;
}