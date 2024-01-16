#include <iostream>
#include <string>
#include "Random.h"

class Monster{
public:
    enum Type{
        dragon,
        goblin,
        ogre,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        max_monster_types
    };

private:
    Type m_type{};
    std::string m_name{" "};
    std::string m_roar{" "};
    int m_points{};

public:
    Monster(Type t,std::string n,std::string r,int p)
        :m_type{t},m_name{n},m_roar{r},m_points{p}
        {
        }

    std::string getTypeString(){
        switch (m_type)
		{
		case dragon:   return "dragon";
		case goblin:   return "goblin";
		case ogre:     return "ogre";
		case orc:      return "orc";
		case skeleton: return "skeleton";
		case troll:    return "troll";
		case vampire:  return "vampire";
		case zombie:   return "zombie";
		default:       return "???";
		}
    }


    void print(){
        if(m_points <= 0){
            std::cout << m_name << " the " << getTypeString() << " is dead\n    ";
        }
        else{
        std::cout << m_name << " the " << getTypeString() << " has " << m_points << " points and says *" << m_roar << "*\n";
        }
    }
};

namespace MonsterGenerator{

    std::string getName(int num){
        switch(num){
            case 0: return "ahmad";
            case 1: return "tamas";
            case 2: return "abood";
            case 3: return "marwan";
            case 4: return "john";
            case 5: return "kanaan";
            default: return "ERROR";
        }
    }
    std::string getRoar(int num2){
     switch(num2){
            case 0: return "aaaaaaaaa";
            case 1: return "tttttt";
            case 2: return "oooooo";
            case 3: return "eeeeee";
            case 4: return "hhhhhhhh";
            case 5: return "awawawawaw";
            default: return "ERROR";
    }
}

    Monster generate(){

        return Monster{
            static_cast<Monster::Type>(Random::get(0, Monster::max_monster_types-1)),
            getName(Random::get(0,5)),
            getRoar(Random::get(0,5)),
            Random::get(1, 100)
            };
    }
};

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
