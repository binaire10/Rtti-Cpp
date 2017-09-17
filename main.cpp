#include <iostream>
#include "trait_type.h"
#include <memory>
#include "vTypeInfo.h"
#include "vClassInfo.h"
#include "NameType.h"
#include "ElementName.h"
#include "TypeInfo.h"
#include "TypeInfoInstance.hpp"
#include "ClassInfoInstance.hpp"
#include "ClassInfo_t.h"
#include "arrayOf.hpp"
#include <algorithm>
#include "FunctionMemberInfoInstance.hpp"
#include <iomanip>
#include "FunctionMember.h"
#include "FunctionMemberInfo_t.hpp"

using namespace std;

struct A : std::string
{
    int a;

    operator int() const
    {
        return 0;
    }
    bool operator &(int b)
    {
        return a & b;
    }
    bool test()
    {
        return false;
    }
};

B_SET_TYPE_NAME(A);
B_SET_TYPE_NAME(int);
B_SET_TYPE_NAME(unsigned);
B_SET_TYPE_NAME(double);
B_SET_TYPE_NAME(void);
B_SET_TYPE_NAME(char);
B_SET_TYPE_NAME(bool);
B_SET_TYPE_NAME_GENERIC(std::char_traits);
B_SET_TYPE_NAME_GENERIC(std::allocator);
B_SET_TYPE_NAME_GENERIC(std::basic_string);
B_SET_TYPE_NAME_GENERIC(std::basic_ostream);
//B_SET_TYPE_NAME(std::string);
B_SET_ELEMENT_NAME_EASY(&A::operator &);
B_SET_ELEMENT_NAME_EASY(&A::test);
B_SET_ELEMENT_NAME_EASY(&A::a);

B_DECLARE_TYPE_HPP(int);
B_DECLARE_TYPE_CPP(int)


B_DECLARE_CLASS_HPP(A);
B_DECLARE_PARENTS_HPP(A, std::string);
B_DECLARE_TRANSTYPE_HPP(A, int, char, unsigned, double);
B_DECLARE_FUNCTION_MEMBER_HPP(&A::test);
B_DECLARE_FUNCTION_MEMBER_HPP(&A::operator &);
B_DECLARE_FUNCTION_MEMBER_OBJECT_HPP(A, B_MAKE_FUNCTION_MEMBER_TYPE(&A::test), B_MAKE_FUNCTION_MEMBER_TYPE(&A::operator &));


B_DECLARE_FUNCTION_MEMBER_CPP(&A::test)
B_DECLARE_FUNCTION_MEMBER_CPP(&A::operator &)
B_DECLARE_CLASS_CPP(A)
B_DECLARE_TRANSTYPE_CPP(A, int, char, unsigned, double);
B_DECLARE_FUNCTION_MEMBER_OBJECT_CPP(A, B_MAKE_FUNCTION_MEMBER_TYPE(&A::test), B_MAKE_FUNCTION_MEMBER_TYPE(&A::operator &));
B_DECLARE_PARENTS_CPP(A, std::string);

constexpr int j = 5;

template<typename...T>
constexpr const char *toString()
{
    return meta::Serialize<meta::Serialize<typename NameType<T>::name_t, meta::Content<char, ';'> >...>();
}

void editFunctionInfo(const vFunctionMemberInfoInstance &a)
{
    cout << std::string(17+17+2, '-') << '\n';
    cout << '|' << right << setw(17) << "object name : "    << left << setw(17) << a.thisObject().name()        << '|' << '\n';
    cout << '|' << right << setw(17) << "function name : "  << left << setw(17) <<  a.functionName()            << '|' << '\n';
    cout << '|' << right << setw(17) << "result type : "    << left << setw(17) << a.resultType().name()        << '|' << '\n';
    cout << '|' << right << setw(17) << "argument count : " << left << setw(17) << std::distance(a.argumentsType().first, a.argumentsType().second) << '|' << '\n';
    cout << std::string(17+17+2, '-') << endl;
}

void editFunctionInfo(const ClassInfo_t &a)
{
    cout << std::string(17+17+2, '-') << '\n';
    cout << '|' << right << setw(17) << "object name : "           << left << setw(17) << a.name() << '|' << '\n';
    cout << std::string(17+17+2, '-') << endl;
}

int main()
{
//    cout << toString<ClassInfo<A>::transtype_t::argumentsSet_type, ClassInfo<A>::transtype_t::arguments_type>() << '\n';
    std::vector<FunctionMemberInfo_t> tr;
    // make_type<std::size_t>();
    make_type<A>().getFunctionMemberInfo(tr);
    FunctionMemberInfoInstance<decltype(&A::test), &A::test> a;
    for(const auto &i : tr)
        cout << i.functionName() << endl;
    editFunctionInfo(a);
    editFunctionInfo(make_type<A>());
    cout << BUILD_NAME << endl;
    /*
    cout << boolalpha << make_type<A>().isDerivedOf(make_type<std::ostream>()) << '\n';
    cout << make_type<A>().isDerivedOf(make_type<std::string>()) << '\n';
    for(const TypeInfo_t &i : tr)
    {
        cout << i.name() << ';';
    }
    cout << '\n' << make_type<A>().name() << ' ' << make_type<int>().name() << '\n';*/
    return 0;
}
