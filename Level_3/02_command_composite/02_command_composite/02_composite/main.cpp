#include <iostream>
#include <memory>
#include <vector>

class IComponent
{
public:
    virtual void Add(std::shared_ptr<IComponent>) = 0;
    virtual void Remove(std::shared_ptr<IComponent>) = 0;
    virtual std::shared_ptr<IComponent> GetChild(int i) = 0;
};

class Composite
    :public IComponent
{
public:
    void Add(std::shared_ptr<IComponent> adds)
    {
        Com.push_back(adds);
    }

    void Remove (std::shared_ptr<IComponent> adds)
    {
    }

    std::shared_ptr<IComponent> GetChild(int i)
    {
        return Com[i];
    }
private:
    std::vector<std::shared_ptr<IComponent>> Com;

};

int main()
{
    Composite C;
    C.Add(std::make_shared<Composite>());
    C.Add(std::make_shared<Composite>());

    C.GetChild(0)->Add(std::make_shared<Composite>());
    return 0;
}
