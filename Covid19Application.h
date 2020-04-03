#pragma once
#include "View/MainWindow.h"
#include "Model/Data.h"

#include <QApplication>

class Covid19Application : public QApplication
{
public:
    Covid19Application(int& argc, char** argv);
private:
    Model::Data _data;
    View::MainWindow _mainWindow;
};

