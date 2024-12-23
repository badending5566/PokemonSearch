#include "Pokemon.h"

// 静态成员变量初始化
vector<Pokemon> Pokemon::pokemonLibrary;

// 默认构造函数
Pokemon::Pokemon() : id(0), level(0), hp(0), attack(0), defense(0) {}

// 带参数的构造函数
Pokemon::Pokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense)
    : id(id), name(name), type(type), level(level), hp(hp), attack(attack), defense(defense) {}

// 获取宝可梦编号
int Pokemon::getId() const { return id; }

// 获取宝可梦名字
string Pokemon::getName() const { return name; }

// 获取宝可梦属性
string Pokemon::getType() const { return type; }

// 获取宝可梦等级
int Pokemon::getLevel() const { return level; }

// 获取宝可梦HP
int Pokemon::getHp() const { return hp; }

// 获取宝可梦攻击力
int Pokemon::getAttack() const { return attack; }

// 获取宝可梦防御力
int Pokemon::getDefense() const { return defense; }

// toString 方法，返回 Pokemon 对象的文本表示
string Pokemon::toString() const {
    return("ID: " + to_string(id) + ", Name: " + name + ", Type: " + type +
        ", Level: " + to_string(level) + ", Hp: " + to_string(hp) +
        ", Attack: " + to_string(attack) + ", Defense: " + to_string(defense));
}

// 添加宝可梦到函数库的函数
void Pokemon::addPokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense) {
    Pokemon newPokemon(id, name, type, level, hp, attack, defense);
    pokemonLibrary.push_back(newPokemon);
}

// 通过编号精确查询宝可梦
Pokemon Pokemon::queryById(int id) {
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getId() == id) {
            return pokemon;
        }
    }
    return Pokemon();
}

// 通过名字精确查询宝可梦
Pokemon Pokemon::queryByName(const string& name) {
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getName() == name) {
            return pokemon;
        }
    }
    return Pokemon();
}

// 通过属性模糊查询宝可梦，返回匹配的宝可梦向量
vector<Pokemon> Pokemon::queryByType(const string& type) {
    vector<Pokemon> result;
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getType().find(type) != string::npos) {
            result.push_back(pokemon);
        }
    }
    return result;
}