#include <iostream>
#include <vector>
#include <memory>

class ICommand
{
public:
    virtual void Execute() = 0;
    virtual ~ICommand() = default;
};

class One
    :public ICommand
{
public:
    void Execute() override
    {
        std::cout<<"One"<<std::endl;
    }
};

class Two
    :public ICommand
{
public:
    void Execute() override
    {
        std::cout<<"Two"<<std::endl;
    }
};

struct Invoker
{
    std::vector<std::shared_ptr<ICommand>> Inv;
    void run()
    {
        for(auto &el: Inv)
        {
            el->Execute();
        }
    }
};

int main()
{
    Invoker I;
    I.Inv.push_back(std::make_shared<One>());
    I.Inv.push_back(std::make_shared<Two>());
    I.Inv.push_back(std::make_shared<One>());
    I.Inv.push_back(std::make_shared<One>());
    I.Inv.push_back(std::make_shared<Two>());

    I.run();

    return 0;
}
