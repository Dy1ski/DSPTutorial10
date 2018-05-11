
// COS30008, Tutorial 10, 2018

#pragma once

#include <stdexcept>

template<class T>
class Handle
{
private:
	T * fPointer;
	int* fCount;

	void addRef()
	{
		++*fCount;
	}

	void releaseRef()
	{
		if (--*fCount == 0)
		{
			delete fPointer;
			delete fCount;
		}
	}

public:

	Handle(T* aPointer = (T*)0)
	{
		fPointer = aPointer;
		fCount = new int;
		*fCount = 1;
	}

	~Handle()
	{
		releaseRef();
	}

	Handle(const Handle<T>& aOtherHandle)
	{
		fPointer = aOtherHandle.fPointer;
		fCount = aOtherHandle.fCount;
		addRef(); 						// increment use
	}

	Handle& operator=(Handle<T>& aOtherHandle)
	{
		if (&aOtherHandle != this)
		{
			aOtherHandle.addRef(); 		 	// increment use
			releaseRef();             		// release old handle
			fPointer = aOtherHandle.fPointer;
			fCount = aOtherHandle.fCount;
		}

		return *this;
	}

	T& operator*()
	{
		if (fPointer)
			return *fPointer;
		else
			throw std::runtime_error("Dereference of unbound handle!");
	}

	T* operator->()
	{
		if (fPointer)
			return fPointer;
		else
			throw std::runtime_error("Access through unbound handle!");
	}

};