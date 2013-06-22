#include <iostream>
using namespace std;
// We need NIL because - as opposed to void - it must be possible
// to create instances of it.
struct NIL
{};
 
template <class T,class Next_ = NIL>
struct Param
{
  Param(const T& t_,const Next_& n_ = NIL()):t(t_),n(n_)
  {}
  const T& t;
  Next_ n;
  typedef Next_ N;
};
 
struct SomePersonParameters
{
  const char *firstname_,
             *lastname_;
  int age_;
 
  SomePersonParameters(const char* fn,const char* ln,const int age)
    :firstname_(fn),lastname_(ln),age_(age)
  {}
};
 
int main()
{
  SomePersonParameters p1("Peter","Parrot",3);
  cout << p1.firstname_ << ' '
       << p1.lastname_ << ' '
       << p1.age_ << endl;
  // Can be rewritten as
  Param<const char*,Param<const char*,Param<int> > >
  p2("Peter",Param<const char*,Param<int> >("Parrot",3)); //please note
  //that we can pass 3 as the last element instead of Param<int>(3)
  //because it will be automatically converted using the constructor
  //of Param
  cout << p2.t << ' '
       << p2.n.t << ' '
       << p2.n.n.t << endl;
  // Or more easily readable
  typedef Param<int> T1;
  typedef Param<const char*,T1> T2;
  typedef Param<const char*,T2> T3;
  T3 p3("Peter",T2("Parrot",3));
  cout << p3.t << ' '
       << p3.n.t << ' '
       << p3.n.n.t << endl;
  return 0;
}
