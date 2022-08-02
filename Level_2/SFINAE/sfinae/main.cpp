#include <iostream>

template<bool, typename Type>
struct enable_if
{};

template<typename Type>
struct enable_if<true, Type>
{
    using type = Type;
};

struct yes
{
    char a;
};

struct no
{
    yes  a;
    char b;
};

template<typename Type>
struct is_poiter
{
    template<typename TypeName>
    struct is_poiter_base
    {
        using type = yes;
    };

    template<typename TypeName>
    struct is_poiter_base<TypeName*>
    {
        using type = no;
    };

    bool static constexpr value =
        sizeof(typename is_poiter_base<Type>::type) == sizeof(yes);
};

template<typename Type>
typename enable_if<is_poiter<Type>::value, Type>::type
    sum(Type a, Type b)
{
    std::cout << "Sum" << std::endl;
    return a + b;
}

template<typename Type>
void sum(...)
{
    std::cout << "Do nothing" << std::endl;
}

void sum(...)
{
    std::cout << "Do nothing" << std::endl;
}

int main()
{
    int a = 0;
    int b = 0;
    sum(&a, &b);
}
