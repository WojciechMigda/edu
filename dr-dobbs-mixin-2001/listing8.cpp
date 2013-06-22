#include <iostream>
#include <string>
using namespace std;
#include "meta.h"
using namespace meta;
#ifdef _MSC_VER
  #pragma warning (disable:4786)
  #pragma warning (disable:4305)
  #define GeneratorRET RET
#else
#define GeneratorRET Generator::RET
#endif
 
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
 
// We will pass Generator to Customer rather than Config; the latter will be
// nested in Generator, and Customer has to retrieve it; this modification
// of Customer is necessary to avoid certain circularity problems.
template <class Generator_>
class Customer
{
  public:
    // Exporting config
    typedef typename Generator_::Config Config;
   // ...
   // Rest of Customer is the same as in Listing Seven.
 
// The remaining mixin classes and the parameter adapter
// are the same as in Listing Seven.
 
// Bitmask for describing customer options - part of the domain
// specific language (DSL) for describing customers
enum CustomerSpec
{
  BasicCustomer = 0, // values represent bits in a bitmask
  WithPhone = 1,
  WithEmail = 2
};
 
// Customer generator (the generator parameters represent rest of DSL)
template <
           int spec = BasicCustomer, // spec is a bitmask
           class Firstname = const char*,
           class Lastname = const char*,
           class PhoneNo = const char*,
           class EmailAdd = const char*
         >
struct CUSTOMER_GENERATOR
{
  // Provide a shorthand for CUSTOMER_GENERATOR ...
  typedef CUSTOMER_GENERATOR < spec,
                               Firstname,
                               Lastname,
                               PhoneNo,
                               EmailAdd
                             > Generator;
  // Parse DSL
  // Assume there is always a basic customer ...
  enum
  { hasPhone = spec & WithPhone,
    hasEmail = spec & WithEmail
  };
 
  // Assemble components
  typedef Customer<Generator> Part1;
 
  typedef typename
    IF < hasPhone,
         PhoneContact<Part1>,
         Part1
       >::RET Part2;
 
  typedef typename
    IF < hasEmail,
         EmailContact<Part2>,
         Part2
       >::RET Part3;
  // Result of the generator template metafunction:
  typedef ParameterAdapter<Part3> RET;
 
  // Compute config
  struct BasicCustomerConfig
  { // Provide some metainformation
    enum
    { specification = spec
    };
    typedef Firstname FirstnameType;
    typedef Lastname LastnameType;
    typedef GeneratorRET RET;
  };
  
  struct CustomerWithPhoneConfig: BasicCustomerConfig
  {
    typedef PhoneNo PhoneNoType;
  };
 
  struct CustomerWithEmailConfig: BasicCustomerConfig
  {
    typedef EmailAdd EmailAddressType;
  };
 
  struct CustomerWithPhoneAndEmailConfig
    : CustomerWithPhoneConfig,CustomerWithEmailConfig
  {};
 
  typedef typename
    SWITCH < spec,
      CASE<BasicCustomer,BasicCustomerConfig,
      CASE<WithPhone,CustomerWithPhoneConfig,
      CASE<WithEmail,CustomerWithEmailConfig,
      CASE<WithPhone+WithEmail,CustomerWithPhoneAndEmailConfig
    > > > > >::RET Config;
};
int main()
{
  CUSTOMER_GENERATOR<>::RET c1("Teddy","Bear");
  c1.print(); cout << endl;
  CUSTOMER_GENERATOR<WithPhone>::RET c2("Rick","Racoon","050-998877");
  c2.print(); cout << endl;
  CUSTOMER_GENERATOR<WithEmail>::RET c3("Dick","Deer","dick@deer.com");
  c3.print(); cout << endl;
  CUSTOMER_GENERATOR<WithPhone + WithEmail>::RET
  c4("Eddy","Eagle","049-554433","eddy@eagle.org");
  c4.print(); cout << endl;
  return 0;
}
