#include "Covid19Application.h"

Covid19Application::Covid19Application(int& argc, char** argv):
    QApplication(argc, argv),
    _mainWindow(&_data)
{
    _mainWindow.show();
}
