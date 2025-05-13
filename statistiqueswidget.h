// StatistiquesWidget.h
#ifndef STATISTIQUESWIDGET_H
#define STATISTIQUESWIDGET_H

#include <QWidget>
#include <QMap>
#include <QPainter>
#include <QSqlQueryModel>
#include <QColor>

class StatistiquesWidget : public QWidget
{
    Q_OBJECT

public:
    StatistiquesWidget(QSqlQueryModel* model, QWidget *parent = nullptr);
    ~StatistiquesWidget() = default;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QSqlQueryModel* model;
};

#endif // STATISTIQUESWIDGET_H
