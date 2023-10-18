#ifndef SOUNDPROCESSOR_CONFIGURATOR_H
#define SOUNDPROCESSOR_CONFIGURATOR_H

#include <string>

class Configurator {
public:
    explicit Configurator(const std::string &filename);

    ~Configurator();

    void run();

    bool hasErrors() const;

private:
    std::string fileName;
    bool errorsOccurred = false;
};

#endif
