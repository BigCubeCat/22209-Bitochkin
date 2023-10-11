#ifndef CONF_H
#define CONF_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Conf; }
QT_END_NAMESPACE

class Conf : public QWidget {
Q_OBJECT

public:
    explicit Conf(QWidget *parent = nullptr);

    ~Conf() override;

public slots:

    void aliveColor();

    void emptyColor();

    void borderColor();

signals:

    void setCellSize(int size);

    void setGapSize(int size);

    void changeColor(const QColor &color, int index);

public slots:

    void onCellSizeChange(int vaue);

    void onGapSizeChange(int vaue);

private:
    Ui::Conf *ui;
};


#endif
