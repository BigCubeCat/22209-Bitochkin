#include "./row.h"

bool Row::operator<(Row& other) {
    if (count == other.count) {
        return word > other.word;
    }
    return count > other.count;
}