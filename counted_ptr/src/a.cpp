
template<class T, void Deleter(void *)=operator delete>
struct foo
{
    T   *p;
    
    foo(){}
    foo(T * a) : p(a) {}
    
    void bar()
    {
        Deleter(p);
    }
};

void baz(void *p)
{
    delete (int *)p;
}

int main()
{
    int     *a;

    a = new int;
    foo<int, &baz>    F(a);
    F.bar();

    a = new int;
    foo<int, &operator delete>    G(a);
    G.bar();

    a = new int;
    foo<int>    H(a);
    H.bar();
}
