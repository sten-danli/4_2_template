//��ģ��ĸ�����壬ʹ��

#ifndef __MYVECTOR__
#define __MYVECTOR__


//һ����ģ��Ĵ�Ŷ���
template<typename T>//����ΪT��ģ�������������ʾ myvector��������������Ԫ�����͡�
class myvector		//ע��������һ�������ģ�塣
{
public:
	typedef T* myiterator;//��������typedef��myiterator��T�������ֶ��ѡ�


public: myvector();//���캯��
		myvector& operator=(const myvector&);//��ֵ��������ء�
	
public:
	myiterator* mybegin(); //ͨ��typedef T* myiterator;�� T��myiterator��һ���ġ�
	T* myend();


public:
	void myfunc();
	//��ģ����ͨ��Ա����������д����ģ�嶨���С�����ж��ģ�嶨���еĳ�Ա�����ᱻ��ʿ������Ϊinline������
	//��ģ��һ����ʵ��������ô���ģ���ÿ��ʵ���������Լ��汾�ĳ�Ա������
	//������ģ���Ա�������к������ģ����ͬ��ģ�����(��仰�ĺ�����˼��:��ģ��ĳ�Ա��������ģ�������)��
	//�����Ҫ����ģ���Ա�����Ķ��壨�����壩д����ģ�嶨�����ߣ���ô�����Ա������ģ����������ֳ����ˡ�
	//ͬʱ�����������Ҫ�ü����Ű�ģ������б����������ģ��������г���������Ƕ��ģ��������ã����ָ���

};

//��ͨ����//��ģ����ͨ��Ա����myfunc����ģ�嶨����ⲿʵ�ֵ�ģ����
template<typename T>
inline void myvector<T>::myfunc()
{
	return;
}

//���캯��
template<typename T>
myvector<T>::myvector()
{
	
}

template<typename T>
 myvector<T>& myvector<T>::operator=(const myvector& x)//��һ��<T>��ʾ���ص���һ��ʵ�����˵�myvector��
{
	
	 return *this;
}


#endif


