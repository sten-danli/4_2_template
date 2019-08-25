//类模板的概念，定义，使用

#ifndef __MYVECTOR__
#define __MYVECTOR__


//一个类模板的大概定义
template<typename T>//名字为T的模板参数，用来表示 myvector这个容器所保存的元素类型。
class myvector		//注意这两行一起代表类模板。
{
public:
	typedef T* myiterator;//代送器。typedef让myiterator和T换个名字而已。


public: myvector();//构造函数
		myvector& operator=(const myvector&);//赋值运算符重载。
	
public:
	myiterator* mybegin(); //通过typedef T* myiterator;后 T和myiterator是一样的。
	T* myend();


public:
	void myfunc();
	//类模板普通成员函数，可以写在类模板定义中。这种卸载模板定义中的成员函数会被隐士的声明为inline函数。
	//类模板一旦被实力化后，那么这个模板的每个实例都会有自己版本的成员函数。
	//所以类模板成员函数具有和这个类模板相同的模板参数(这句话的核心意思是:类模板的成员函数是有模板参数的)；
	//如果你要把类模板成员函数的定义（函数体）写在类模板定义的外边，那么这个成员函数的模板参数就体现出来了。
	//同时，在类名后边要用尖括号把模板参数列表里面的所有模板参数名列出来，如果是多个模板参数，用，来分隔。

};

//普通函数//类模板普通成员函数myfunc在类模板定义的外部实现的模样。
template<typename T>
inline void myvector<T>::myfunc()
{
	return;
}

//构造函数
template<typename T>
myvector<T>::myvector()
{
	
}

template<typename T>
 myvector<T>& myvector<T>::operator=(const myvector& x)//第一个<T>表示返回的是一个实例化了的myvector；
{
	
	 return *this;
}


#endif


