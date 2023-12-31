#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QString>

#include "../StateStorage/StateStorage.h"

class FileWorker : public QObject {
Q_OBJECT
public:
    explicit FileWorker(StateStorage *s = nullptr, QObject *parent = nullptr);

    void setFileName(const QString &filename);

    std::pair<QString, bool> readFile();

    QString getTitle();

    void saveFile();

private:
    QString fileName;
    StateStorage *store;
    QString title;
};

#endif
