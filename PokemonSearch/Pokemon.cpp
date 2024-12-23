#include "Pokemon.h"

// ��̬��Ա������ʼ��
vector<Pokemon> Pokemon::pokemonLibrary;

// Ĭ�Ϲ��캯��
Pokemon::Pokemon() : id(0), level(0), hp(0), attack(0), defense(0) {}

// �������Ĺ��캯��
Pokemon::Pokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense)
    : id(id), name(name), type(type), level(level), hp(hp), attack(attack), defense(defense) {}

// ��ȡ�����α��
int Pokemon::getId() const { return id; }

// ��ȡ����������
string Pokemon::getName() const { return name; }

// ��ȡ����������
string Pokemon::getType() const { return type; }

// ��ȡ�����εȼ�
int Pokemon::getLevel() const { return level; }

// ��ȡ������HP
int Pokemon::getHp() const { return hp; }

// ��ȡ�����ι�����
int Pokemon::getAttack() const { return attack; }

// ��ȡ�����η�����
int Pokemon::getDefense() const { return defense; }

// toString ���������� Pokemon ������ı���ʾ
string Pokemon::toString() const {
    return("ID: " + to_string(id) + ", Name: " + name + ", Type: " + type +
        ", Level: " + to_string(level) + ", Hp: " + to_string(hp) +
        ", Attack: " + to_string(attack) + ", Defense: " + to_string(defense));
}

// ��ӱ����ε�������ĺ���
void Pokemon::addPokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense) {
    Pokemon newPokemon(id, name, type, level, hp, attack, defense);
    pokemonLibrary.push_back(newPokemon);
}

// ͨ����ž�ȷ��ѯ������
Pokemon Pokemon::queryById(int id) {
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getId() == id) {
            return pokemon;
        }
    }
    return Pokemon();
}

// ͨ�����־�ȷ��ѯ������
Pokemon Pokemon::queryByName(const string& name) {
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getName() == name) {
            return pokemon;
        }
    }
    return Pokemon();
}

// ͨ������ģ����ѯ�����Σ�����ƥ��ı���������
vector<Pokemon> Pokemon::queryByType(const string& type) {
    vector<Pokemon> result;
    for (const auto& pokemon : pokemonLibrary) {
        if (pokemon.getType().find(type) != string::npos) {
            result.push_back(pokemon);
        }
    }
    return result;
}