#include "MainWindow.h"
#include "ui_MainWindow.h"

namespace View {

MainWindow::MainWindow(Model::Data* data, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _data(data)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

} // namespace View
