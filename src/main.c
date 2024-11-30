#include <stdio.h>

#include "notes.h"

int main(void) {
  enum Note start_note = Note_C;
  enum Interval interval = Minor_Second;
  enum Note new_one = note_interval(start_note, interval);
  printf("Alaphang: %s + %s Kiszamolt: %s\n", note_to_string(start_note),
         interval_to_string(interval), note_to_string(new_one));
  return 0;
}
