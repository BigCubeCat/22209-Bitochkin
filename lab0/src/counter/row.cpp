#include "./row.h"

bool compareRows(Row first, Row second) {
    if (first.count == second.count) {
        return first.word > second.word;
    }
    return first.count > second.count;
}