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

    void updateAll();

private:
    Life *life;
    TRules *rules;
    TNeighborhood *neighborhood;

public slots:
    void testSlot();

    void setRules(const std::string & newRules);

    void setNeighborhood(ENeighborhood newNeigh, int degree = 1);

signals:
    void invalidRule();
    void renderLife(const Life &life);
};


#endif
