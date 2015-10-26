//#pragma once
//template <typename T>
//class Singleton
//{
//private:
//	static auto_ptr<T> pSingleton; //static �ɹ��Լ����� ���������ϵ��� ��������
//
//public:
//	static GetInstance();        //��ȯ���� ��ü�� �ּҷ� �Ͽ� �������̽� �Լ��� ���� �ܺο��� ������ ������ �����ϰ���.
//	static void Destroy();
//};
//
//template <typename T>
//Singleton<T>::GetInstance()
//{
//	if (pSingleton == nullptr)        //�̱����̹Ƿ� �� �ϳ��� �����ؾ���
//	{
//		pSingleton = new Singleton<T>;
//		std::cout << "�̱��� �����Ҵ�" << std::endl;
//	}
//	return pSingleton.get();
//}
//
//template <typename T>
//void Singleton<T>::Destroy()        //����� �� �� �� ������ ���ִ� �Լ� �ʿ�
//{
//	if (pSingleton != nullptr)
//	{
//		delete pSingleton;
//		pSingleton = nullptr;
//	}
//}

#pragma once
template <typename T>
class Singleton
{
public:
	static T* GetInstance()
	{
		call_once(m_onceFlag, [] 
			{
				m_pInstance.reset(new T); 
			}
		);

		return m_pInstance.get();
	}

private:
	static std::shared_ptr<T> Singleton<T>::m_pInstance;
	static std::once_flag m_onceFlag;
};

template <typename T> std::shared_ptr<T> Singleton<T>::m_pInstance = nullptr;

template <typename T> std::once_flag Singleton<T>::m_onceFlag;


#pragma once

template <class T>
class CSingleton
{
public:
	static T *ms_pSingleton;

public:
	CSingleton()
	{
		unsigned __int64 ulOffset = (unsigned __int64)((T*)(1)) - (unsigned __int64)((CSingleton<T>*)(T*)1);

		ms_pSingleton = (T*)((unsigned __int64)this + ulOffset);
	}

	virtual ~CSingleton()
	{
		ms_pSingleton = 0;
	}

	static T* GetSingleton()
	{
		return(ms_pSingleton);
	}
};

template <class T> T* CSingleton<T>::ms_pSingleton = 0;
