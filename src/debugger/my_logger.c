#include "mgba/debugger/my_logger.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 1024

extern FILE *my_log;

void printBuffered(uint32_t oldpc, uint32_t newpc) {
  static uint32_t buffer[BUFFER_SIZE];
  static size_t buffer_index = 0;
  if (buffer_index == BUFFER_SIZE) {
    fwrite(buffer, sizeof(uint32_t), BUFFER_SIZE, my_log);
    buffer_index = 0;
    fflush(my_log);
  } else {
    buffer[buffer_index] = oldpc;
    buffer_index++;
    buffer[buffer_index] = newpc;
    buffer_index++;
  }
}