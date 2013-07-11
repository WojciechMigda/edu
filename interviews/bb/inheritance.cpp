// for static binding method functions are derived from pointer type
// for dynamic binding method functions are derived from instance type

#include <stdio.h>

struct Base
{
    void foo()
    {
        printf("Base::foo()\n");
    }
};

struct Derived : public Base
{
    void foo()
    {
        printf("Derived::foo()\n");
    }
};

struct vBase
{
    virtual void foo()
    {
        printf("vBase::foo()\n");
    }
};

struct vDerived : public vBase
{
    virtual void foo()
    {
        printf("vDerived::foo()\n");
    }
};

struct A
{
    void foo()
    {
        printf("A::foo()\n");
    }
};

struct vA
{
    virtual void foo()
    {
        printf("vA::foo()\n");
    }
};

int main()
{
    {
        Base        base;
        Derived     derived;

        Base *      pb = &base;
        Derived *   pd = &derived;

        pb->foo();                      // Base::foo
        pd->foo();                      // Derived::foo

        Base *      pbd = &derived;
        pbd->foo();                     // Base::foo

        // without pointer cast it won't compile
        Derived *   pdb = (Derived *)&base;
        pdb->foo();                     // Derived::foo

        A *         pa;
        pa = (A *)&base;
        pa->foo();                      // A::foo

        vA *        pva;
        pva = (vA *)&base;
        //pva->foo();                     // segfault, no vtable in base
    }

    puts("-----");

    {
        vBase       base;
        vDerived    derived;

        vBase *     pb = &base;
        vDerived *  pd = &derived;

        pb->foo();                      // vBase::foo
        pd->foo();                      // vDerived::foo

        vBase *     pbd = &derived;
        pbd->foo();                     // vDerived::foo

        // without pointer cast it won't compile
        vDerived *  pdb = (vDerived *)&base;
        pdb->foo();                     // vBase::foo

        vA *        a;
        a = (vA *)&base;
        a->foo();                       // vBase::foo
    }

    return 0;
}
