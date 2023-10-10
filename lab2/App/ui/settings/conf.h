#ifndef CONF_H
#define CONF_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class conf; }
QT_END_NAMESPACE

class conf : public QWidget {
Q_OBJECT

public:
    explicit conf(QWidget *parent = nullptr);

    ~conf() override;

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
    Ui::conf *ui;
};


#endif
