#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QString>

#include "../StateStorage/StateStorage.h"

class FileWorker : public QObject {
    Q_OBJECT
   public:
    explicit FileWorker(StateStorage *s = nullptr);

    ~FileWorker();

    void setFileName(const QString &filename);

    std::pair<QString, bool> readFile();

    void saveFile();

   private:
    QString fileName;
    StateStorage *store;
   signals:

    void setWindowTitle(const QString &title);
};

#endif
