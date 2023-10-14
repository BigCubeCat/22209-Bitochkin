#ifndef STATESTORAGE_H
#define STATESTORAGE_H

#include <QObject>
#include <QTimer>
#include <string>

#include "../Kernel//Life/Life.h"

class StateStorage : public QObject {
    Q_OBJECT
   public:
    StateStorage();

    ~StateStorage() override;

    char *getArena();

    size_t getWidth() const;

    size_t getHeight() const;

    QString getRules();

    QString getNeighborhood();

    bool aliveAt(int index);

   private:
    Life *life{};

    size_t arenaWidth{};
    size_t arenaHeight{};

    bool isRunning = false;

    QTimer *gameTimer;
    QTimer *canvasTimer;

   public slots:

    void setRules(const std::string &newRules);

    void setNeighborhood(ENeighborhood newNeigh, int degree = 1);

    void InitLife(int countRows, int countCols);

    void toggleLife(int row, int col);

    void tickGame();

    void tickCanvas();

    void step();

    void stop();

    void run();

    void setSpeed(int value);

    void setCellSize(int size);

    void setGapSize(int size);

    void setColor(const QColor &color, int index);

   signals:

    void invalidRule();

    void redraw(char *data, size_t width, size_t height);

    void updateRules(const TRules &rules);

    void updateNeighborhood(const TNeighborhood &n);

    void cellSizeSignal(int size);

    void gapSizeSignal(int size);

    void setColorSignal(const QColor &color, int index);
};

#endif
