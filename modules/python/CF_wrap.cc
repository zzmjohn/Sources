#include <sstream>
#include <boost/python.hpp>
#include "mod2.h"
#include "factory.h"

using boost::python::self;
static boost::python::object CF_as_str(const CanonicalForm& f)
{
  using boost::python::str;
  std::basic_stringstream<char>  s;
  s<<f;
  return boost::python::str(s.str());
}
void export_CF(){
    boost::python::class_<CanonicalForm>("canonical_form")
    .def(boost::python::init <const int>())
    .def(boost::python::init <const Variable>())
    .def("__str__", CF_as_str)
    .def(-self)
    .def(self*=self)
    .def(self+=self)
    .def(self-=self)
    .def(self/=self)
    .def(self==self)
    .def(self+self)
    .def(self*self)
    .def(self/self)
    .def(self-self)
    .def(int()==self)
    .def(int()+self)
    .def(int()*self)
    .def(int()/self)
    .def(int()-self)
    .def(self==int())
    .def(self+int())
    .def(self*int())
    .def(self/int())
    .def(self-int())
    .def(self*=int())
    .def(self+=int())
    .def(self-=int())
    .def(self/=int());
}
