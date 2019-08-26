#include<iostream>
using namespace std;
#include<string>
#include"myvector.h"

//一:typename的使用情形
template<typename T>//1.定义类名
 typename T::size_type getlength(const T& c) //2.typename在这里加上表示T::size_type在一起是个类型名，如果不加typename系统会
	 //把它当作静态成员变量处理。
{
	if (c.empty())
		return 0;
	return c.size();
}

int getlenth(const string& s)
{
	if (s.empty())
		return 0;
	return s.size();
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//二：函数指针作为某个函数的参数
//我们要把函数指针作为某个函数的参数进行传递时，也就是让函数指针当作函数的参数，
//这时候我们就要定义一个函数指针类型，。例如我们想要把以下这个函数当作另一个函数的参数进行传递：
int add(int tmp1, int tmp2) { return tmp1 + tmp2; }
//用上面的函数定义一个函数指针类型以便用在另外一个函数的参数里：
typedef int (*padd)(int, int);
//然后就可以把上面的函数在下面的函数里面当作参数使用了：
void funcadd(int a, int b, padd x)
{
	int result = x(a, b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	string mystr = "i am c++ profi";
	cout<<getlength(mystr);
	

	myvector<int> myvec1;//这个时候，编译器就给我们生成了一个具体的类。
	myvector<double> myvec11;
	myvector<string> myvec12;
	//myvector是类模板名，他不是一个类名，类模板是用来实例化类（类型）用的。
	//所以myvector<double>，myvector<string>加上<>才是类型名（实例化了的类型）。
	//所以一个实例化了的类型从会用尖括号包着模板参数。  

}