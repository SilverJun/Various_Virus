#pragma once
template <typename T>
class Singleton
{
private:
	static T *pSingleton; //static �ɹ��Լ����� ���������ϵ��� ��������

public:
	static T* GetInstance();        //��ȯ���� ��ü�� �ּҷ� �Ͽ� �������̽� �Լ��� ���� �ܺο��� ������ ������ �����ϰ���.
	static void Destroy();
};

template <typename T>
T* Singleton<T>::pSingleton = nullptr;

template <typename T>
T* Singleton<T>::GetInstance()
{
	if (pSingleton == nullptr)        //�̱����̹Ƿ� �� �ϳ��� �����ؾ���
	{
		pSingleton = new T;
	}
	return pSingleton;
}

template <typename T>
void Singleton<T>::Destroy()        //����� �� �� �� ������ ���ִ� �Լ� �ʿ�
{
	if (pSingleton != nullptr)
	{
		delete pSingleton;
		pSingleton = nullptr;
	}
}
