#include "Data.h"

#include <QDir>
#include <QtAlgorithms>
#include <QCoreApplication>

namespace Model {

Data::Data(QObject* parent) : QObject(parent)
{
    update();
}

Data::~Data()
{
    qDeleteAll(dailyReports_);
}

bool Data::isEmpty() const
{
    return dailyReports_.empty();
}

void Data::update()
{
    qDeleteAll(dailyReports_);
    dailyReports_.clear();

    QDir dataDir(QCoreApplication::applicationDirPath() +
                 "/Data/csse_covid_19_data/csse_covid_19_daily_reports");

    QStringList dailyReportFilenames = dataDir.entryList(QStringList() << "*.csv",
                                       QDir::Files);

    foreach(const QString& fileName, dailyReportFilenames)
    {
        dailyReports_[fileName] = new DailyReport(fileName);
    }
}

QStringList Data::days() const
{
    return dailyReports_.keys();
}

const DailyReport* Data::report(QString day) const
{
    return dailyReports_[day];
}

} // namespace Model
