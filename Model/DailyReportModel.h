#pragma once

#include <QAbstractTableModel>

#include "DailyReport.h"

namespace Model {

class DailyReportModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit DailyReportModel(QObject* parent = NULL);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant data(const QModelIndex& index,
                  int role = Qt::DisplayRole) const override;

    void setReport(const DailyReport* report);
private:
    const DailyReport* report_;
};

} // namespace Model

