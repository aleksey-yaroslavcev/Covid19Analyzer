#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "Model/Data.h"

namespace View {

MainWindow::MainWindow(Model::Data* data, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , data_(data)
{
    ui->setupUi(this);
    ui->comboBox->addItems(data_->days());
    ui->tableView->setModel(&dailyReportModel_);
    on_comboBox_currentIndexChanged(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index >= 0)
    {
        dailyReportModel_.setReport(data_->report(ui->comboBox->currentText()));
    }
}

} // namespace View
