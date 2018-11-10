#include <memory>
#include <iterator>

using namespace std;

template<typename T, typename A = allocator<T>>
struct vector_base {
    A alloc;
    T* elem;
    T* space;
    T* last;

    vector_base(const A& a, typename A::size_type n)
        : alloc{a}, elem{alloc.allocate(n)}, space{elem+n}, last{elem+n} {}
    ~vector_base() {
        alloc.deallocate(elem, last - elem);
    }

    vector_base(const vector_base&) = delete;
    vector_base& operator=(const vector_base&) = delete;

    vector_base(const vector_base&& a) 
        : alloc{a.alloc}, elem{a.elem}, space{a.space}, last{a.last} 
    {
        a.elem = a.space = a.last = nullptr;
    }
    vector_base& operator=(vector_base&& a) {
        swap(*this, a);
        return *this;
    }
};

template<typename T, typename A = allocator<T>>
class Vector {
private:
    vector_base<T, A> vb;
    void destory_elements();

public:
    using size_type = unsigned int;

    explicit Vector(size_type n, const T& val = T(), const A& = A());

    Vector(const Vector& a) : vb{a.alloc, a.size()} {
        uninitialized_copy(a.begin(), a.end(), vb.elem);
    }
    Vector& operator=(const Vector& a);

    Vector(Vector&& a) : vb{move(a.vb)} {}
    Vector& operator=(Vector&& a) {
        clear();
        swap(*this, a);
    }

    ~Vector() {
        destory_elements();
    }

    size_type size() const {
        return vb.space - vb.elem;
    }
    size_type capacity() const {
        return vb.last - vb.elem;
    }

    void reserve(size_type);

    void resize(size_type, T = {});
    void clear() {
        resize(0);
    }
    void push_back(const T&);

};

template<typename T, typename A>
void Vector<T, A>::destory_elements() {
    for (T* p = vb.elem; p != vb.space; ++p)
        vb.space = vb.elem;
}

template<typename T, typename A>
Vector<T, A>::Vector(size_type n, const T& val, const A& a) 
    : vb{a, n} {
    uninitialized_fill(vb.elem, vb.elem+n, val);
}


