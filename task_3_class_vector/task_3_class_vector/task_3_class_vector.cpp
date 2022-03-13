

#include <iostream>



template <typename T>
class Vector {

private:
    T* arr;
    size_t sz;
    size_t cap;

public:

    
    Vector()
    {

    }

    Vector(T* arr)
    {
        this->arr = arr;


    }

    void reserve(size_t n)
    {
        if (n <= cap) return;
        newarr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);
        size_t i = 0;
        try 
        {
            for (; i < sz; ++i)
            {
                new(newarr + i) T(arr[i]);
            }

        }
        catch (...)
        {
            for (size_t j = 0; j < i; ++j)
            {
                (newarr + i)->~T();
            }
            delete[] reinterpret_cast<int8_t*>(newarr);
            throw;
        }
        for (size_t j = 0; j < sz; ++j)
        {
            (arr + i)->~T();
        }
        delete[] reinterpret_cast<int8_t*>(arr);
        arr = newarr;
        cap = n;

    }

    void resize(size_t n, const T& value = T())
    {
        if (n > cap) reserve(n);
        for (size_t i = sz; i < n; ++i)
        {
            new(arr + i) T(value);
        }
    
        if (n < sz) sz = n;


    }


    

    void push_back(const T& value)
    {
        if (cap == sz) reserve(2 * sz);
        new(arr + sz) T(value);
        ++sz;
    }

    void pop_back()
    {
        
        --sz;
        (arr + sz)->~T();
    }

    T& operator [](size_t i)
    {
        return arr[i];
    }

    T& at(size_t i)
    {
        if (i >= sz) throw std::outofrange("...");
        return arr[i];
    }

   
};


int main()
{

    int d[4] = { 1, 3, 4, 5 };

    Vector<int> arr(d);


     return 0;
}