#include "DailyReport.h"

#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QDebug>

namespace Model {

DailyReport::DailyReport(const QString& filename)
{
    const QString& dirname = QCoreApplication::applicationDirPath() +
                             "/Data/csse_covid_19_data/csse_covid_19_daily_reports";

    QFile csvFile(dirname + "/" + filename);
    if(csvFile.open(QFile::ReadOnly | QFile::Text))
    {
        QTextStream in(&csvFile);

        columns_ = in.readLine().split(",");

        int regionColumn = columns_.indexOf(QRegExp("Country.*Region"));

        int confirmedColumn = columns_.indexOf(QRegExp("Confirmed"));
        int deathsColumn = columns_.indexOf(QRegExp("Deaths"));
        int recoveredColumn = columns_.indexOf(QRegExp("Recovered"));

        QStringList item;
        while(!in.atEnd())
        {
            item = in.readLine().split(",");
            rawData_.push_back(item);
            statPerRegion_[item[regionColumn]] +=
                StatisticEntry(item[confirmedColumn].toInt(),
                               item[deathsColumn].toInt(),
                               item[recoveredColumn].toInt());
        }
        csvFile.close();
    }
}

const QStringList& DailyReport::columns() const
{
    return columns_;
}

const QList<QStringList>& DailyReport::rawData() const
{
    return rawData_;
}

QMap<QString, DailyReport::StatisticEntry> DailyReport::statPerRegion() const
{
    return statPerRegion_;
}

QStringList DailyReport::regions() const
{
    return statPerRegion_.keys();
}

} // namespace Model
