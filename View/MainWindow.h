#pragma once

#include "Model/DailyReportModel.h"

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

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::MainWindow* ui;
    Model::Data* data_;
    Model::DailyReportModel dailyReportModel_;
};

} // namespace View
