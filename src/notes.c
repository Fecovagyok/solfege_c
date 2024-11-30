#include "notes.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const char* note_to_string(enum Note note) {
#define X(e_note, base, chrom) \
  case TO_NOTE_ENUM(e_note):   \
    return #e_note;
  switch (note) { NOTE_RELATIONS }
#undef X
}

#define X(e_note, base, chrom) [TO_NOTE_ENUM(e_note)] = TO_NOTE_ENUM(base),
static enum Note bases[] = {NOTE_RELATIONS};
#undef X

enum Note note_base_of(enum Note note) { return bases[note]; }

#define DEFINE_ACCIDENTAL_ARRAY(flat_or_sharp)                              \
  static enum Note flat_or_sharp##s[] = {                                   \
      [Note_C] = Note_C_##flat_or_sharp, [Note_D] = Note_D_##flat_or_sharp, \
      [Note_E] = Note_E_##flat_or_sharp, [Note_F] = Note_F_##flat_or_sharp, \
      [Note_G] = Note_G_##flat_or_sharp, [Note_A] = Note_A_##flat_or_sharp, \
      [Note_H] = Note_H_##flat_or_sharp,                                    \
  }

DEFINE_ACCIDENTAL_ARRAY(sharp);
DEFINE_ACCIDENTAL_ARRAY(flat);

#define CHROMATIC_SCALE_RELATION \
  X(C, C)                        \
  X(C_sharp, D_flat)             \
  X(D, D)                        \
  X(D_sharp, E_flat)             \
  X(E, F_flat)                   \
  X(F, F)                        \
  X(F_sharp, G_flat)             \
  X(G, G)                        \
  X(G_sharp, A_flat)             \
  X(A, A)                        \
  X(A_sharp, B)                  \
  X(H, C_flat)

#define TO_CHROMATIC_ENUM(chrom) Chromatic_##chrom

enum Chromatic_type {
#define X(chrom, aliases) TO_CHROMATIC_ENUM(chrom),
  CHROMATIC_SCALE_RELATION
#undef X
};

#define X(note, base, chrom) [TO_NOTE_ENUM(note)] = TO_CHROMATIC_ENUM(chrom),
static enum Chromatic_type note_to_chrom_array[] = {NOTE_RELATIONS};
#undef X

enum Chromatic_type note_to_chromatic(enum Note note) {
  return note_to_chrom_array[note];
}

// #define X(chrom, alias) TO_CHROMATIC_ENUM(chrom),
// static enum Chromatic_type chromatic_scale[] = {CHROMATIC_SCALE_RELATION};
// #undef X

enum Direction {
  Dir_Downward = -1,
  Dir_Upward = 1,
};

uint32_t chromatic_calc_distance(enum Chromatic_type first,
                                 enum Chromatic_type second) {
  if (second < first) {
    printf("Baj: second=%d,first=%d\n line=%d\n", second, first, __LINE__);
    exit(1);
  }
  return second - first;
}

#define X(name, full_step, half_step) [name] = full_step,
static unsigned int interval_full_steps[] = {INTERVAL_RELATIONS};
#undef X

#define WHITE_NOTE_RELATIONS \
  X(C)                       \
  X(D)                       \
  X(E)                       \
  X(F)                       \
  X(G)                       \
  X(A)                       \
  X(H)

#define TO_WHITE_NOTE_ENUM(white_note) White_note_##white_note

#define X(white_note) TO_WHITE_NOTE_ENUM(white_note)
enum White_note { WHITE_NOTE_RELATIONS };
#undef X

#define X(raw, base, chrom) [TO_NOTE_ENUM(raw)] = TO_WHITE_NOTE_ENUM(base),
static enum White_note note_to_white_note_array[] = {NOTE_RELATIONS};
#undef X

enum White_note note_to_white_note(enum Note note) {
  return note_to_white_note_array[note_base_of(note)];
}

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_CHROMATIC_ENUM(white_note),
static enum Chromatic_type white_note_to_chromatic_array[] = {
    WHITE_NOTE_RELATIONS};
#undef X

enum Chromatic_type white_note_to_chromatic(enum White_note note) {
  return white_note_to_chromatic_array[note];
}

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_NOTE_ENUM(white_note),
static enum Note white_note_to_note_array[] = {WHITE_NOTE_RELATIONS};
#undef X

enum Note white_note_to_note(enum White_note note) {
  return white_note_to_note_array[note];
}

enum Note note_sharp_of(enum Note note) { return sharps[note]; }
enum Note note_flat_of(enum Note note) { return flats[note]; }

enum White_note white_note_for_full_step_of(enum Note base,
                                            enum Interval interval) {
  enum White_note non_accidental = note_to_white_note(base);
  return (non_accidental + interval_full_steps[interval]) % 8;
}

enum Note up_the_game(enum White_note note) { return }

enum Note note_interval(enum Note base, enum Interval interval) {
  enum White_note new_base = white_note_for_full_step_of(base, interval);
  uint32_t distance = chromatic_calc_distance(
      note_to_chromatic(base), white_note_to_chromatic(new_base));
  if (distance == interval) return white_note_to_note(new_base);
  if (distance < interval) return
}
