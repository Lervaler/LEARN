#include <iostream>
#include <string>

struct Object_1
{
    std::string _name;

//    void set_name(const std::string& name)
//    {
//        _name = name;
//    }
//    void set_name(std::string&& name)
//    {
//        _name = std::move(name);
//    }
//    void set_name(std::string name)
//    {
//        _name = std::move(name);
//    }

    template<typename Type>  // шаблон
    void set_name(Type&& name)
    {
        _name = std::forward<Type>(name); //универсальная ссылка
    }
};

struct Object_2
{
    Object_1 object_1;

    void set_name(std::string&& name)
    {
        object_1.set_name(std::move(name));
    }
};

int main()
{

    return 0;
}
