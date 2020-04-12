#pragma once
#include "DailyReport.h"

#include <QObject>
#include <QStringList>
#include <QMap>

namespace Model {

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject* parent = NULL);
    ~Data();

    bool isEmpty() const;

    void update();
    QStringList days() const;
    const DailyReport* report(QString day) const;

signals:
private:
    QMap<QString, DailyReport*> dailyReports_;
};

} // namespace Model

