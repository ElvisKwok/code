#ifdef HANDLE_H
#define HANDLE_H
#include <cstddef>

template <class T>
class Handle {
public:
    // if p=0, unbound handle
    Handle(T *p=0): ptr(p), use(new size_t(1)) { }
    // overloaded operator to support POINTER BEHAVIOR
    T& operator*();
    T* operator->();
    const T& operator*() const;
    const T* operator->() const;
    // copy control
    Handle(const Handle &h): ptr(h.ptr), use(h.use)
    {
        ++*use;
    }
    Handle& operator=(const Handle&);
    ~Handle()
    {
        rem_ref();
    }
private:
    T* ptr;
    std::size_t *use;
    void rem_ref()
    {
        if (--*use == 0) {
            delete ptr;
            delete use;
        }
    }
};


template <class T>
inline Handle<T>& Handle<T>::operator=(const Hanle &rhs)
{
    ++*rhs.use;
    rem_ref();
    use = rhs.use;
    ptr = rhs.ptr;
    return *this;
}

template <class T>
inline T& Handle<T>::operator*()
{
    if (ptr) return *ptr;
    throw std::runtime_error("dereference of unbound handle");
}

template <class T>
inline T* Handle<T>::operator->()
{
    if (ptr) return ptr;
    throw std::runtime_error("access through unbound handle");
}

template <class T>
inline const T& Handle<T>::operator*() const
{
    if (ptr) return *ptr;
    throw std::runtime_error("dereference of unbound handle");
}

template <class T>
inline const T* Handle<T>::operator->() const
{
    if (ptr) return ptr;
    throw std::runtime_error("access through unbound handle");
}
