#include<iostream>
using namespace std;
#include<string>
#include"myvector.h"

//һ:typename��ʹ������
template<typename T>//1.��������
 typename T::size_type getlength(const T& c) //2.typename��������ϱ�ʾT::size_type��һ���Ǹ����������������typenameϵͳ��
	 //����������̬��Ա��������
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
//��������ָ����Ϊĳ�������Ĳ���
//����Ҫ�Ѻ���ָ����Ϊĳ�������Ĳ������д���ʱ��Ҳ�����ú���ָ�뵱�������Ĳ�����
//��ʱ�����Ǿ�Ҫ����һ������ָ�����ͣ�������������Ҫ�������������������һ�������Ĳ������д��ݣ�
int add(int tmp1, int tmp2) { return tmp1 + tmp2; }
//������ĺ�������һ������ָ�������Ա���������һ�������Ĳ����
typedef int (*padd)(int, int);
//Ȼ��Ϳ��԰�����ĺ���������ĺ������浱������ʹ���ˣ�
void funcadd(int a, int b, padd x)
{
	int result = x(a, b);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	string mystr = "i am c++ profi";
	cout<<getlength(mystr);
	

	myvector<int> myvec1;//���ʱ�򣬱������͸�����������һ��������ࡣ
	myvector<double> myvec11;
	myvector<string> myvec12;
	//myvector����ģ������������һ����������ģ��������ʵ�����ࣨ���ͣ��õġ�
	//����myvector<double>��myvector<string>����<>������������ʵ�����˵����ͣ���
	//����һ��ʵ�����˵����ʹӻ��ü����Ű���ģ�������  

}