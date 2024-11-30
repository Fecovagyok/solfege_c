#include <stdio.h>

#include "notes.h"

int main(void) {
  enum Note start_note = Note_C;
  enum Note new_one = note_interval(start_note, Minor_Second);
  printf("Alaphang: %s Kiszamolt: %s\n", note_to_string(start_note),
         note_to_string(new_one));
  return 0;
}
