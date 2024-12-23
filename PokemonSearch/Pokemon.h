#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Pokemon {
private:
    int id;
    string name;
    string type;
    int level;
    int hp;
    int attack;
    int defense;

public:
    static vector<Pokemon> pokemonLibrary;

    Pokemon();
    Pokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense);

    int getId() const;
    string getName() const;
    string getType() const;
    int getLevel() const;
    int getHp() const;
    int getAttack() const;
    int getDefense() const;
    string toString() const;

    static void addPokemon(int id, const string& name, const string& type, int level, int hp, int attack, int defense);
    static Pokemon queryById(int id);
    static Pokemon queryByName(const string& name);
    static vector<Pokemon> queryByType(const string& type);
};