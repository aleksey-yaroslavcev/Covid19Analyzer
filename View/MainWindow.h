#pragma once

#include <QMainWindow>

namespace Model {
class Data;
}

namespace View {

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Model::Data* data, QWidget* parent = NULL);
    ~MainWindow();

private:
    Ui::MainWindow* ui;
    Model::Data* _data;
};

} // namespace View
