#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "notes_helper.h"

#define X(note, base, chrom) [TO_NOTE_ENUM(note)] = TO_CHROMATIC_ENUM(chrom),
static const enum Chromatic_type note_to_chrom_array[] = {NOTE_RELATIONS};
#undef X

enum Chromatic_type note_to_chromatic(enum Note note) {
  return note_to_chrom_array[note];
}

uint32_t chromatic_calc_distance(enum Chromatic_type first,
                                 enum Chromatic_type second) {
  if (second < first) {
    printf("Baj: second=%d,first=%d\n line=%d\n", second, first, __LINE__);
    exit(1);
  }
  return second - first;
}
