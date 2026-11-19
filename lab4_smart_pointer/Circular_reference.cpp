#include <memory>
#include <iostream>
#include <string> 
 

#include <memory>
#include <iostream>

struct B;

struct A
{
    std::weak_ptr<B> b;
    ~A()
    {
        std::cout << "A dtor was called\n";
    }
};

struct B
{
    std::shared_ptr<A> a;
    ~B()
    {
        std::cout << "B dtor was called\n";
    }
};

int main()
{
    std::shared_ptr<A> a_ptr = std::make_shared<A>();
    std::shared_ptr<B> b_ptr = std::make_shared<B>();

    a_ptr->b = b_ptr;
    b_ptr->a = a_ptr;

    return 0;
}