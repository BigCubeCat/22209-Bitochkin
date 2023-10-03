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

    void InitLife();

    void updateAll();

    std::vector<std::vector<char>> * getArena();

private:
    Life *life;

public slots:

    void setRules(const std::string &newRules);

    void setNeighborhood(ENeighborhood newNeigh, int degree = 1);

    void resizeLife(int countRows, int countCols);

    void toggleLife(int row, int col);

signals:

    void invalidRule();

    void renderLife(const Life &life);
};


#endif
