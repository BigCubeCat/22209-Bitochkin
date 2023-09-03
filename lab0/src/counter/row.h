#pragma once

#include <string>

struct Row {
  std::string word;
  int count;
  int frequency;
};

bool compareRows(Row first, Row second);
