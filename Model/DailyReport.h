#pragma once
#include <QString>
#include <QStringList>
#include <QMap>

namespace Model {

class DailyReport
{
public:
    struct StatisticEntry
    {
        StatisticEntry(): confirmed(0), deaths(0), recovered(0) {}
        StatisticEntry(int nconfirmed, int ndeaths, int nrecovered):
            confirmed(nconfirmed), deaths(ndeaths), recovered(nrecovered) {}
        StatisticEntry& operator+=(const StatisticEntry& entry)
        {
            confirmed += entry.confirmed;
            deaths += entry.deaths;
            recovered += entry.recovered;
            return *this;
        }

        int confirmed;
        int deaths;
        int recovered;
    };
    DailyReport(const QString& filename);

    const QStringList& columns() const;

    const QList<QStringList>& rawData() const;

    QMap<QString, StatisticEntry> statPerRegion() const;
    QStringList regions() const;

private:
    QStringList columns_;
    QList<QStringList> rawData_;

    QMap<QString, StatisticEntry> statPerRegion_;
};

} // namespace Model

