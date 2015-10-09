#pragma once
template <typename T>
class Singleton
{
private:
	static T *pSingleton; //static 맴버함수에서 참조가능하도록 정적선언

public:
	static T* GetInstance();        //반환값을 객체의 주소로 하여 인터페이스 함수를 통해 외부에서 데이터 조작을 가능하게함.
	static void Destroy();
};

template <typename T>
T* Singleton<T>::pSingleton = nullptr;

template <typename T>
T* Singleton<T>::GetInstance()
{
	if (pSingleton == nullptr)        //싱글턴이므로 단 하나만 존재해야함
	{
		pSingleton = new T;
	}
	return pSingleton;
}

template <typename T>
void Singleton<T>::Destroy()        //사용을 다 한 뒤 해제를 해주는 함수 필요
{
	if (pSingleton != nullptr)
	{
		delete pSingleton;
		pSingleton = nullptr;
	}
}
