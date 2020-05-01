#pragma once
#include <assert.h>

template<class T>
class smart_ptr
{
public:
	smart_ptr();
	smart_ptr(const smart_ptr<T>& sptr);
	explicit smart_ptr(T* ptr);
	~smart_ptr();

	const smart_ptr& operator=(T* ptr);
	const smart_ptr& operator=(smart_ptr<T>& sptr);
	const smart_ptr& operator=(const smart_ptr<T>& sptr);

	T& operator*();
	T* operator->();

	bool operator==(const smart_ptr<T>& other);
	bool operator==(const T* other);
	bool operator!=(const smart_ptr<T>& other);
	bool operator!=(const T* other);

	unsigned use_count() const;
	bool unique() const;
	T* get() const;


private:
	T* ref;
	unsigned* ref_count;

	void incReference();
	void decReference();
};


template<class T>
inline smart_ptr<T>::smart_ptr() :ref(nullptr), ref_count(new unsigned(0))
{
}

template<class T>
smart_ptr<T>::smart_ptr(const smart_ptr<T>& sptr) : ref(sptr.ref), ref_count(sptr.ref_count)
{
	incReference();
}

template<class T>
smart_ptr<T>::smart_ptr(T * ptr) :ref(ptr), ref_count(new unsigned(0))
{
	incReference();
}

template<class T>
smart_ptr<T>::~smart_ptr()
{
	decReference();
	if (*ref_count < 1)
	{
		delete ref;
		delete ref_count;
	}

}

template<class T>
const smart_ptr<T> & smart_ptr<T>::operator=(T * ptr)
{
	decReference();
	ref = ptr;
	*ref_count = 0;
	incReference();
	return *this;
}

template<class T>
const smart_ptr<T> & smart_ptr<T>::operator=(smart_ptr<T>& sptr)
{
	decReference();
	ref = sptr.ref;
	ref_count = sptr.ref_count;
	incReference();
	return *this;
}

template<class T>
const smart_ptr<T> & smart_ptr<T>::operator=(const smart_ptr<T>& sptr)
{
	decReference();
	ref = sptr.ref;
	ref_count = sptr.ref_count;
	incReference();
	return *this;
}

template<class T>
T& smart_ptr<T>::operator*()
{
	assert(ref != nullptr);
	return *ref;
}

template<class T>
T* smart_ptr<T>::operator->()
{
	assert(ref != nullptr);
	return ref;
}

template<class T>
bool smart_ptr<T>::operator==(const smart_ptr<T>& other)
{
	return ref == other.ref;
}

template<class T>
bool smart_ptr<T>::operator==(const T * other)
{
	return ref == other.ref;
}

template<class T>
bool smart_ptr<T>::operator!=(const smart_ptr<T>& other)
{
	return !(this == other);
}

template<class T>
bool smart_ptr<T>::operator!=(const T * other)
{
	return !(this == other);
}

template<class T>
unsigned smart_ptr<T>::use_count() const
{
	return *ref_count;
}

template<class T>
bool smart_ptr<T>::unique() const
{
	return 1 == *ref_count;
}

template<class T>
T * smart_ptr<T>::get() const
{
	return ref;
}

template<class T>
void smart_ptr<T>::incReference()
{
	++(*ref_count);
}

template<class T>
void smart_ptr<T>::decReference()
{
	--(*ref_count);
}
