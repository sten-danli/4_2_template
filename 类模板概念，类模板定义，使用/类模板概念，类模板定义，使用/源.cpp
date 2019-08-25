#include<iostream>
using namespace std;
#include"myvector.h"

int main()
{
	myvector<int> myvec1;//这个时候，编译器就给我们生成了一个具体的类。
	myvector<double> myvec11;
	myvector<string> myvec12;
	//myvector是类模板名，他不是一个类名，类模板是用来实例化类（类型）用的。
	//所以myvector<double>，myvector<string>加上<>才是类型名（实例化了的类型）。
	//所以一个实例化了的类型从会用尖括号包着模板参数。  

}