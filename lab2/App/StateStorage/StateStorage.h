#ifndef STATESTORAGE_H
#define STATESTORAGE_H

#include <QObject>
#include <string>
#include "../Life/Life.h"

class StateStorage : public QObject {
Q_OBJECT
public:
    StateStorage();

    ~StateStorage() override;

    char *getArena();

    size_t getWidth() const;

    size_t getHeight() const;

private:
    Life *life;

    size_t arenaWidth;
    size_t arenaHeight;

public slots:

    void setRules(const std::string &newRules);

    void setNeighborhood(ENeighborhood newNeigh, int degree = 1);

    void InitLife(int countRows, int countCols);

    void toggleLife(int row, int col);

signals:

    void invalidRule();

    void renderLife(const Life &life);

    void updateRules(const TRules &rules);

    void updateNeighborhood(const TNeighborhood &n);
};


#endif
