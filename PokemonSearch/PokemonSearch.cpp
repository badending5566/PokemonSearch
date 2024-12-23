#include "PokemonSearch.h"
#include "Pokemon.h"
#include <QMainWindow>
//using namespace std;

PokemonSearch::PokemonSearch(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    Pokemon::addPokemon(1, "picachu", "dian", 15, 35, 55, 40);
    Pokemon::addPokemon(2, "jienigui", "shui", 14, 44, 48, 65);
    Pokemon::addPokemon(3, "jienig", "shui", 14, 44, 48, 65);
    Pokemon::addPokemon(4, "4", "4", 4, 4, 4, 4);
    connect(ui.searchButton, &QPushButton::clicked, this, &PokemonSearch::Outres);
    connect(ui.clearButton, &QPushButton::clicked, this, &PokemonSearch::Clear);

}

PokemonSearch::~PokemonSearch()
{}


void PokemonSearch::Outres() {
    QString valueStr = ui.searchline->text();
    QString disStr;   // 输出文本

    string res;
    QImage imgCir;

    Pokemon pokemonById, pokemonByName;
    vector<Pokemon> pokemonByType;

    int selIndex = ui.Wayselect->currentIndex(); //获取下拉框选中的标签
    //1.属性; 2：Id; 3:名称

    switch (selIndex) {
    case 0: {
        string Type;
        Type = valueStr.toStdString();
        pokemonByType = Pokemon::queryByType(Type);
        if (!pokemonByType.empty()) {
            for (const auto& p : pokemonByType) {
                res += p.toString() + "\n";
            }
            ui.alltext->setText(disStr.fromStdString(res));
        }
        else {
            ui.outline->setText("wrong Type input");
        }
        break;
    }
    case 1: {
        int Id;
        Id = valueStr.toInt();
        pokemonById = Pokemon::queryById(Id);
        if (pokemonById.getId() != 0) {
            res = pokemonById.toString();
            ui.alltext->setText(disStr.fromStdString(res));
        }
        else {
            ui.outline->setText("wrong id input");
        }
        break;
    }
    case 2://名称
    {
        string Name;
        Name = valueStr.toStdString();
        pokemonByName = Pokemon::queryByName(Name);
        if (!pokemonByName.getName().empty()) {
            res = pokemonByName.toString();
            ui.alltext->setText(disStr.fromStdString(res));
        }
        else {
            ui.outline->setText("wrong name input");
        }
        break;
    }

    }
}


void PokemonSearch::Clear() {
    ui.outline->clear();
    ui.alltext->clear();
}