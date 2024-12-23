#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PokemonSearch.h"

class PokemonSearch : public QMainWindow
{
    Q_OBJECT

public:
    PokemonSearch(QWidget *parent = nullptr);
    ~PokemonSearch();
    
private:
    Ui::PokemonSearchClass ui;
    
    

private slots:
    void Outres();
    void Clear();
};
