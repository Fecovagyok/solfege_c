#include <stdio.h>

#include "interval.h"

int main(void) {
  enum Note start_note = Note_C;
  enum Interval interval = Augmented_Unison;
  enum Note new_one = note_interval(start_note, interval);
  printf("%s + %s = %s\n", note_to_string(start_note),
         interval_to_string(interval), note_to_string(new_one));
  return 0;
}
