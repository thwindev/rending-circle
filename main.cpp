#include <iostream>

class Monster
{
private:
    // std::string m_name;
protected:
    std::string m_name;
public:
    Monster(){}
    Monster(std::string name)
    :m_name(name){}
    void attack() { std::cout << m_name << " is attacking!\n"; }
    void move() { std::cout << m_name << " is moving!\n"; }
};

class Spider : public Monster
{
public:
    Spider(std::string name)
    {
        m_name = name;
    }
private:
};

int main(void)
{
    Monster monster("Goblin");
    monster.move();
    monster.attack();

    Spider spider("spider");
    spider.move();
    spider.attack();
    
    return 0;
}
