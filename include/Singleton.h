// ***********************************************************************
// Filename         : Singleton.h
// Author           : LIZHENG
// Created          : 2014-07-01
// Description      : 线程安全的单例模板类.可用于多线程中，可手动或自动释放单例实例
//                    使用方式：
//                    class TestSingleton : public SingleTon<TestSingleton>
//                    {  
//                         DECLARE_SINGLETON_CLASS(type);
//                    }
//
// Last Modified By : LIZHENG
// Last Modified On : 2014-07-01
// 
// Copyright (c) lizhenghn@gmail.com. All rights reserved.
// ***********************************************************************
#ifndef ZL_SINGLETON_H
#define ZL_SINGLETON_H

#include "Define.h"
#include <mutex>

NAMESPACE_ZL_START

#define DECLARE_SINGLETON_CLASS(type)  friend class Singleton< type >;

template<class T>
class Singleton
{
public:
	static T *GetInstancePtr()
	{
		if (0 == m_proxy.m_Instance)
		{
			CreateInstance();
		}
		return m_proxy.m_Instance;
	}

	static T& GetInstanceRef()
	{
		if (0 == m_proxy.m_Instance)
		{
			CreateInstance();
		}
		return *(m_proxy.m_Instance);
	}

	static bool	CleanInstance()
	{
		if (m_proxy.m_Instance)
		{
			delete m_proxy.m_Instance;
			m_proxy.m_Instance = 0;
		}
		return true;
	}
private:
	static void CreateInstance()
	{
		m_proxy.CreateInstance();
	}
private:
	struct Proxy
	{
		Proxy() : m_Instance(0)
		{	}

		~Proxy()
		{
			if (m_Instance)
			{
				delete m_Instance;
				m_Instance = 0;
			}
		}

		void CreateInstance()
		{
			if (0 == m_Instance)
			{
				std::lock_guard<std::mutex> guard(m_lock);
				if (0 == m_Instance)
				{
					m_Instance = new T;
				}
			}
		}

		T *m_Instance;	
		std::mutex m_lock;
	};
protected:
	Singleton()  {	}
	~Singleton() {	}
private:
	static Proxy m_proxy;
};

template < typename T >
typename Singleton<T>::Proxy Singleton<T>::m_proxy;

NAMESPACE_ZL_END

#endif /* ZL_SINGLETON_H */