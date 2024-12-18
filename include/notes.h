#ifndef SOLFEGE_H_INCLUDED
#define SOLFEGE_H_INCLUDED

/* This header files contains the declaration of the enum representing a
 * solfege note*/

#define NOTE_RELATIONS   \
  X(C, C, C)             \
  X(C_sharp, C, C_sharp) \
  X(C_flat, C, B)        \
  X(D, D, D)             \
  X(D_sharp, D, D_sharp) \
  X(D_flat, D, C_sharp)  \
  X(E, E, E)             \
  X(E_sharp, E, F)       \
  X(E_flat, E, D_sharp)  \
  X(F, F, F)             \
  X(F_sharp, F, F_sharp) \
  X(F_flat, F, E)        \
  X(G, G, G)             \
  X(G_sharp, G, G_sharp) \
  X(G_flat, G, F_sharp)  \
  X(A, A, A)             \
  X(A_sharp, A, A_sharp) \
  X(A_flat, A, G_sharp)  \
  X(B, B, B)             \
  X(B_sharp, B, C)       \
  X(B_flat, B, A_sharp)

#define TO_NOTE_ENUM(raw_note) Note_##raw_note

#define X(note, base, chrom) TO_NOTE_ENUM(note),
enum Note { NOTE_RELATIONS };
#undef X

const char* note_to_string(enum Note);

#endif
