// This file may be redistributed and modified only under the terms of
// the GNU Lesser General Public License (See COPYING for details).
// Copyright (C) 2000 Aloril

#ifndef ATLAS_OBJECTS_SMARTPTR_H
#define ATLAS_OBJECTS_SMARTPTR_H

#include <Atlas/Objects/BaseObject.h>

namespace Atlas { namespace Objects {

class NullSmartPtrDereference : public Atlas::Exception
{
  public:
    NullSmartPtrDereference() : Atlas::Exception("Null SmartPtr dereferenced") {}
    virtual ~NullSmartPtrDereference() throw ();
};

template <class T> 
class SmartPtr
{
  public:
    SmartPtr() : ptr(T::alloc()) { 
    }
    SmartPtr(const SmartPtr<T>& a) : ptr(a.get()) {
        incRef();
    }
    SmartPtr(T *a_ptr) : ptr(a_ptr)
    {
        incRef();
    }
    template<class oldType>
    explicit SmartPtr(const SmartPtr<oldType>& a) : ptr(a.get()) {
    }
    ~SmartPtr() { 
        decRef();
    }
    SmartPtr& operator=(const SmartPtr<T>& a) {
        if (a.get() != this->get()) {
            decRef();
            ptr = a.get();
            incRef();
        }
        return *this;
    }
    template<class newType>
    operator SmartPtr<newType>() const {
        return SmartPtr<newType>(ptr);
    }
    template<class newType>
    operator SmartPtr<const newType>() const {
        return SmartPtr<const newType>(ptr);
    }
    bool operator!() const {
        return ptr == 0;
    }
    T& operator*() const { 
        if (ptr != 0) {
            throw NullSmartPtrDereference();
        }
        return *ptr;
    }
    T* operator->() const {
        if (ptr != 0) {
            throw NullSmartPtrDereference();
        }
        return ptr;
    }
    T* get() const {
        return ptr;
    }
    SmartPtr<T> getDefaultObject() const
    {
        return SmartPtr(ptr->getDefaultObject());
    }
    static SmartPtr<T> factory()
    {
        SmartPtr<T> obj;
        return obj;
    }
    // If you want to make these protected, please ensure that the
    // detructor is made virtual to ensure your new class bahaves
    // correctly.
  private:
    void decRef() const {
        if (ptr != 0) {
            ptr->decRef();
        }
    }
    void incRef() const {
        if (ptr != 0) {
            ptr->incRef();
        }
    }
    T * ptr;
};

template<class returnType, class fromType>
SmartPtr<returnType> smart_dynamic_cast(const SmartPtr<fromType> & o)
{
    return SmartPtr<returnType>(dynamic_cast<returnType *>(o.get()));
}

template<class returnType, class fromType>
SmartPtr<returnType> smart_static_cast(const SmartPtr<fromType> & o)
{
    return SmartPtr<returnType>((returnType*)o.get());
}

} } // namespace Atlas::Objects

#endif // ATLAS_OBJECTS_SMARTPTR_H
