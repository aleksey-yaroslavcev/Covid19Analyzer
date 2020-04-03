#pragma once

#include <QObject>

namespace Model {

class Data : public QObject
{
    Q_OBJECT
public:
    explicit Data(QObject* parent = NULL);

signals:

};

} // namespace Model

