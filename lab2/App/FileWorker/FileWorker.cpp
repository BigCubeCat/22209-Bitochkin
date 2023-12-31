#include "FileWorker.h"

#include <QFile>
#include <QTextStream>

FileWorker::FileWorker(StateStorage *store, QObject *parent) : store(store), QObject(parent) {
    fileName = "~/a.life";
}

void FileWorker::setFileName(const QString &filename) {
    fileName = filename;
}

std::pair<QString, bool> FileWorker::readFile() {
    QFile inputFile(fileName);
    inputFile.open(QIODevice::ReadOnly);
    std::pair<QString, bool> result;
    if (!inputFile.isOpen()) {
        result.first = QString("unable to open file");
        result.second = false;
        return result;
    }

    QTextStream stream(&inputFile);
    for (QString line = stream.readLine(); !line.isNull();
         line = stream.readLine()) {
        QStringList words = line.split(" ");
        if (line.at(0) == QChar('#')) {
            if (words[0] == QString("#T")) {
                if (words.size() == 2)
                    title = words[1];
            } else if (words[0] == QString("#R")) {
                if (words.size() == 2)
                    store->setRules(words[1].toStdString());
            } else if (words[0] == QString("#N")) {
                if (words.size() == 3) {
                    ENeighborhood nType = (words[1] == QString("M")) ? MOORE : VON;
                    int degree = words[2].toInt();
                    store->setNeighborhood(nType, degree);
                }
            } else if (words[0] == QString("#G")) {
                if (words.size() == 3)
                    store->InitLife(words[1].toInt(), words[2].toInt());
            }
        } else {
            if (words.size() == 2)
                store->toggleLife(words[1].toInt(), words[0].toInt());
        }
    };

    result.first = QString("ok");
    result.second = true;
    return result;
}

void FileWorker::saveFile() {
    QFile file(fileName);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "#T " << fileName << "\n";
        stream << "#G " << store->getWidth() << " " << store->getHeight()
               << "\n";
        stream << "#N " << store->getNeighborhood() << "\n";
        stream << "#R " << store->getRules() << "\n";
        int width = store->getWidth();
        int height = store->getHeight();
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (store->aliveAt(row * width + col)) {
                    stream << col << " " << row << "\n";
                }
            }
        }
    }
}

QString FileWorker::getTitle() {
    return title;
}
