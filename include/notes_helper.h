#ifndef NOTES_HELPER_H_INCLUDED
#define NOTES_HELPER_H_INCLUDED

#include <stdint.h>

#include "notes.h"

/* This header files contains the declaration of enums necessary for the
 * internal logic to function. */

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
  X(A_sharp, B_flat)             \
  X(B, C_flat)

#define TO_CHROMATIC_ENUM(chrom) Chromatic_##chrom

enum Chromatic_type {
#define X(chrom, aliases) TO_CHROMATIC_ENUM(chrom),
  CHROMATIC_SCALE_RELATION
#undef X
};

uint32_t chromatic_calc_distance(enum Chromatic_type first,
                                 enum Chromatic_type second);

enum Chromatic_type note_to_chromatic(enum Note note);

/* I meant non-sharp and non-flat notes are white notes */

#define WHITE_NOTE_RELATIONS \
  X(C)                       \
  X(D)                       \
  X(E)                       \
  X(F)                       \
  X(G)                       \
  X(A)                       \
  X(B)

#define TO_WHITE_NOTE_ENUM(white_note) White_note_##white_note

#define X(white_note) TO_WHITE_NOTE_ENUM(white_note),
enum White_note { WHITE_NOTE_RELATIONS };
#undef X

enum White_note note_base_of(enum Note note);

enum White_note note_to_white_note(enum Note note);
enum Note white_note_to_note(enum White_note note);
enum Chromatic_type white_note_to_chromatic(enum White_note note);

enum Note white_note_sharp_of(enum White_note note);
enum Note white_note_flat_of(enum White_note note);

#endif
