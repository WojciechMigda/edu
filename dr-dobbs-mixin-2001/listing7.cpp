#include <iostream>
#include <string>
using namespace std;
 
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
 
template <class Config_>
class Customer
{
  public:
    // Exporting config
    typedef Config_ Config;
    // Create parameter type
    typedef
      Param< typename Config::LastnameType,
      Param< typename Config::FirstnameType > > ParamType;
    Customer(const ParamType& p)
     :lastname_(p.t),firstname_(p.n.t)
    {}
    void print() const
    {
       cout << firstname_
            << ' '
            << lastname_;
    }
  private:
    typename Config::FirstnameType firstname_;
    typename Config::LastnameType lastname_;
};
template <class Base>
class PhoneContact: public Base
{
  public:
    // retrieve config and export it
    typedef typename Base::Config Config;
    // retrieve the constructor parameter type from the base class
    // and extend it with own parameters
    typedef Param< typename Config::PhoneNoType,
                   typename Base::ParamType > ParamType;
    PhoneContact(const ParamType& p)
      :Base(p.n),phone_(p.t)
    {}
    void print() const
    {
      Base::print();
      cout << ' ' << phone_;
    }
  private:
    typename Config::PhoneNoType phone_;
};
template <class Base>
class EmailContact: public Base
{
  public:
    // retrieve config and export it
    typedef typename Base::Config Config;
    // retrieve the constructor parameter type from the base class
    // and extend it with own parameters
    typedef Param< typename Config::EmailAddressType,
                   typename Base::ParamType> ParamType;
    EmailContact(const ParamType& p)
      :Base(p.n),email_(p.t)
    {}
    void print() const
    {
      Base::print();
      cout << ' ' << email_;
    }
  private:
    typename Config::EmailAddressType email_;
};
template <class Base>
struct ParameterAdapter: Base
{
  // Retrieve config from Base and export it.
  typedef typename Base::Config Config;
 
  // Retrieve the most complete param type
  typedef typename Config::RET::ParamType P;
  typedef typename P::N P1;
  typedef typename P1::N P2;
 
  // Constructor adapter with 1 argument
  template < class A1
           >
  ParameterAdapter( const A1& a1)
    :Base(a1)
  {}
 
  // Constructor adapter with 2 arguments
  template < class A1,
             class A2
           >
  ParameterAdapter( const A1& a1,
                    const A2& a2)
    :Base(P(a2,a1))
  {}
 
  // Constructor adapter with 3 arguments
  template < class A1,
             class A2,
             class A3
           >
  ParameterAdapter( const A1& a1,
                    const A2& a2,
                    const A3& a3)
    :Base(P(a3,P1(a2,a1)))
  {}
  // Constructor adapter with 4 arguments
  template < class A1,
             class A2,
             class A3,
             class A4
           >
  ParameterAdapter( const A1& a1,
                    const A2& a2,
                    const A3& a3,
                    const A4& a4)
    :Base(P(a4,P1(a3,P2(a2,a1))))
  {}
};
 
struct C1
{
  // Provide standard name for config
  typedef C1 ThisConfig;
 
  // Provide elementary types
  typedef const char* FirstnameType;
  typedef const char* LastnameType;
 
  // Parameterize base class
  typedef Customer<ThisConfig> CustomerType;
 
  // Add ParameterAdapter
  typedef ParameterAdapter<CustomerType> RET;
};
 
struct C2
{
  // Provide standard name for config
  typedef C2 ThisConfig;
 
  // Provide elementary types
  typedef const char* FirstnameType;
  typedef const char* LastnameType;
  typedef const char* PhoneNoType;
 
  // Assemble mixin classes
  typedef Customer<ThisConfig> CustomerType;
  typedef PhoneContact<CustomerType> PhoneContactType;
 
  // Add ParameterAdapter
  typedef ParameterAdapter<PhoneContactType> RET;
};
 
struct C3
{
  // Provide standard name for config
  typedef C3 ThisConfig;
   
  // Provide elementary types
  typedef const char* FirstnameType;
  typedef const char* LastnameType;
  typedef const char* EmailAddressType;
 
  // Assemble mixin classes
  typedef Customer<ThisConfig> CustomerType;
  typedef EmailContact<CustomerType> EmailContactType;
 
  // Add ParameterAdapter
  typedef ParameterAdapter<EmailContactType> RET;
};
struct C4
{
  // Provide standard name for config
  typedef C4 ThisConfig;
 
  // Provide elementary types
  typedef const char* FirstnameType;
  typedef const char* LastnameType;
  typedef const char* PhoneNoType;
  typedef const char* EmailAddressType;
  
  // Assemble mixin classes
  typedef Customer<ThisConfig> CustomerType;
  typedef PhoneContact<CustomerType> PhoneContactType;
  typedef EmailContact<PhoneContactType> EmailContactType;
  
  // Add ParameterAdapter
  typedef ParameterAdapter<EmailContactType> RET;
};
 
int main()
{
  C1::RET c1("Teddy","Bear");
  c1.print(); cout << endl;
  C2::RET c2("Rick","Racoon","050-998877");
  c2.print(); cout << endl;
  C3::RET c3("Dick","Deer","dick@deer.com");
  c3.print(); cout << endl;
  C4::RET c4("Eddy","Eagle","049-554433","eddy@eagle.org");
  c4.print(); cout << endl;
 
return 0;
}
