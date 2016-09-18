#pragma once
#include "stdafx.h"

template<class T>
class Singleton
{
protected:
	static T* inst_;
protected:
	Singleton() = default;
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
	~Singleton() = default;
public:
	static T* GetInstance()
	{
		if (!inst_)
		{
			inst_ = new T;
		} 
		return inst_;
	}
protected:
	static void DestroyInstance()
	{
		delete inst_;
		inst_ = nullptr;
	}
protected:
	static auto& Create()
	{
		return *GetInstance();
	}
	static void Destroy()
	{
		DestroyInstance();
	}
};

template<class T>
T* Singleton<T>::inst_ = nullptr;
