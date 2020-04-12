#include "DailyReportModel.h"

namespace Model {

DailyReportModel::DailyReportModel(QObject* parent)
    : QAbstractTableModel(parent),
      report_(NULL)
{
}

void DailyReportModel::setReport(const DailyReport* report)
{
    report_ = report;
    reset();
}

QVariant DailyReportModel::headerData(int section, Qt::Orientation orientation,
                                      int role) const
{
    // FIXME: Implement me!
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch(section)
        {
        case 0:
            return "Region";
        case 1:
            return "Confirmed";
        case 2:
            return "Deaths";
        case 3:
            return "Recovered";
        }
    }

    return QVariant();
}

int DailyReportModel::rowCount(const QModelIndex& parent) const
{
    if(report_ == NULL)
    {
        return 0;
    }

    return report_->statPerRegion().size();
}

int DailyReportModel::columnCount(const QModelIndex& parent) const
{
    return 4;
}

QVariant DailyReportModel::data(const QModelIndex& index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }

    if(role == Qt::DisplayRole && report_ != NULL)
    {
        int row = index.row();
        int column = index.column();
        switch(column)
        {
        case 0:
            return report_->regions().at(row);
        case 1:
            return report_->statPerRegion()[report_->regions().at(row)].confirmed;
        case 2:
            return report_->statPerRegion()[report_->regions().at(row)].deaths;
        case 3:
            return report_->statPerRegion()[report_->regions().at(row)].recovered;
        }
    }
    return QVariant();
}

} // namespace Model
