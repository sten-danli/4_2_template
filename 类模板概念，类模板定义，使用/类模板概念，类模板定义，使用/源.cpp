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
 //����ĺ������Լ�д��������������:
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
//Ȼ��Ϳ��԰�����ĺ���������ĺ������浱������ʹ����
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
//��������ģ��Ȥζ�÷��������ɵ��ö������������ȿ�δ����֪ʶ��ĵ�һ�ڿΡ��ɵ��ö��󡿣�
class tc
{
	
public:
	tc() { cout << "���캯��ִ��"<<endl; }
	tc(const tc&c)
	{
		cout << "�������캯��ִ��" << endl;
	}
public://����Բ����
	int operator()(int a, int b)
	{
		return a + b;
	}
};
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//�ģ�Ĭ����ģ��
//a����ģ�壬��ģ������߱�����<>���ṩ�������Ϣ��<>��ʾ����һ��ģ�塣

template<typename T=string, int size=5>//T=string ��int size=5����Ĭ�ϵ�ȱʡֵ�����ĳһ��������ȱʡֵ
//��ô�������ж�Ҫ������
class myarray
{

};

//b)����ģ��
template <typename T, typename F = tc>
//void testfunc(const int&i, ocnst int&j, tc funcpint =tc())//��д����ģ��Ļ�д�ɺ����Ļ���
void testfunc(const T & i, const T & j, F funcpoint = F())
{
	cout << funcpoint(i, j) << endl;
}

int main()
{	
	int result = funcadd2(99, 1, add);
	cout << result;

	//����b����Ĭ����ģ��
	//����������������ú���tetsfunc(1, 2)�������������õĻ�funcadd(1, 2, obj)����Ҫ����д��
	//template <typename T, typename F = tc>
	//void testfunc(const T & i, const T & j, F funcpoint = F())
	testfunc(2, 6);
	//(1)ͬʱ��ģ������ͺ��������ṩȱʡֵ
	//(2)ע��д�� F funcpoint=F()
	//(3)tc��Ҫ���������int operator()

	//����a����Ĭ����ģ��
	//myarray<>myarr;//��ȫ��ģ��ȱʡֵ
	//myarray<int > def;//�ṩһ����ȱʡֵ������һ���ڶ��������õ���ȱʡֵ��
	//���庯��template<typename T=string, int size=5>�����˼����T=int, �ڶ�����ʹ��Ĭ��ȱʡֵ5.

	//����
	tc obj;
	 funcadd(3, 4, add);
	 funcadd(1, 2, obj);//Ҳ����������funcadd(1, 2, tc());
	 //���Ҫ��funcaddģ����ɵ���tc����࣬��ôtc���������ǡ��ɵ��ö��󡿣�
	 //Ҳ����˵��������������Ҫ�����أ��������int operator()(int a, int b)���������Ĳ�����
	//����ֵҪ��ģ�庯������ĵ��ø�ʽ��ͬ�����������ĵ��á�
	

	//��һ
	//string mystr = "i am c++ profi";
	//cout<<getlength(mystr);
	//

	//myvector<int> myvec1;//���ʱ�򣬱������͸�����������һ��������ࡣ
	//myvector<double> myvec11;
	//myvector<string> myvec12;
	//myvector����ģ������������һ����������ģ��������ʵ�����ࣨ���ͣ��õġ�
	//����myvector<double>��myvector<string>����<>������������ʵ�����˵����ͣ���
	//����һ��ʵ�����˵����ʹӻ��ü����Ű���ģ�������  

}