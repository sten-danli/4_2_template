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
 //上面的函数我自己写成了这样。如下:
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
//然后就可以把上面的函数在下面的函数里面当作参数使用了
template<typename T,typename F>
int funcadd(const T &a, T const &b, F x)
{
	 int result = x(a, b);
	 return result;

}
template<typename T, typename F=padd>
int funcadd2(const T& a, T const& b, F pointerAdd=add)
{
	int result= add(a, b);
	return result;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//三：函数模板趣味用法举例；可调用对象。如有问题先看未归类知识点的第一节课【可调用对象】；
class tc
{
	
public:
	tc() { cout << "构造函数执行"<<endl; }
	tc(const tc&c)
	{
		cout << "拷贝构造函数执行" << endl;
	}
public://重载圆括号
	int operator()(int a, int b)
	{
		return a + b;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//四：默认类模板
//a）类模板，类模板明后边必须用<>来提供额外的信息。<>表示这是一个模板。

template<typename T=string, int size=5>//T=string 和int size=5就是默认的缺省值，如果某一个参数有缺省值
//那么后面所有都要给出。
class myarray
{

};

//b)函数模板
template <typename T, typename F = tc>
//void testfunc(const int&i, ocnst int&j, tc funcpint =tc())//不写成类模板的话写成函数的话。
void testfunc(const T & i, const T & j, F funcpoint = F())
{
	cout << funcpoint(i, j) << endl;
}

int main()
{	
	int result = funcadd2(99, 1, add);
	cout << result;

	//对四b）：默认类模板
	//如果我们像这样调用函数tetsfunc(1, 2)而不是这样调用的话funcadd(1, 2, obj)，就要这样写：
	//template <typename T, typename F = tc>
	//void testfunc(const T & i, const T & j, F funcpoint = F())
	testfunc(2, 6);
	//(1)同时给模板参数和函数参数提供缺省值
	//(2)注意写法 F funcpoint=F()
	//(3)tc类要重载运算符int operator()

	//对四a）：默认类模板
	//myarray<>myarr;//完全用模板缺省值
	//myarray<int > def;//提供一个非缺省值，另外一个第二个参数用的是缺省值。
	//定义函数template<typename T=string, int size=5>里的意思就是T=int, 第二个参使用默认缺省值5.

	//对三
	tc obj;
	 funcadd(3, 4, add);
	 funcadd(1, 2, obj);//也可以这样：funcadd(1, 2, tc());
	 //如果要让funcadd模板类可调用tc这个类，那么tc这个类必须是【可调用对象】，
	 //也就是说在这个类里面必须要有重载（）运算符int operator()(int a, int b)，而且他的参数和
	//返回值要和模板函数里面的调用格式相同，才能正常的调用。
	

	//对一
	//string mystr = "i am c++ profi";
	//cout<<getlength(mystr);
	//

	//myvector<int> myvec1;//这个时候，编译器就给我们生成了一个具体的类。
	//myvector<double> myvec11;
	//myvector<string> myvec12;
	//myvector是类模板名，他不是一个类名，类模板是用来实例化类（类型）用的。
	//所以myvector<double>，myvector<string>加上<>才是类型名（实例化了的类型）。
	//所以一个实例化了的类型从会用尖括号包着模板参数。  

}