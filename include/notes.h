#ifndef SOLFEGE_H_INCLUDED
#define SOLFEGE_H_INCLUDED

#define NOTE_RELATIONS   \
  X(C, C, C)             \
  X(C_sharp, C, C_sharp) \
  X(C_flat, C, H)        \
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
  X(H, H, H)             \
  X(H_sharp, H, C)       \
  X(B, H, A_sharp)

#define TO_NOTE_ENUM(raw_note) Note_##raw_note

#define X(note, base, chrom) TO_NOTE_ENUM(note),
enum Note { NOTE_RELATIONS };
#undef X

const char* note_to_string(enum Note);

#define Note_H_flat Note_B

#define TO_INTERVAL_ENUM(interval) Interval_##interval

#define INTERVAL_RELATIONS \
  X(Perfect_Unison, 0, 0)  \
  X(Minor_Second, 1, 1)    \
  X(Major_Second, 1, 2)    \
  X(Minor_Third, 2, 3)     \
  X(Major_Third, 2, 4)     \
  X(Perfect_Fourth, 3, 5)  \
  X(Perfect_Fifth, 4, 7)

/* To be continued later */

#define X(name, wannabe, steps) name,
enum Interval { INTERVAL_RELATIONS };
#undef X

enum Note note_interval(enum Note base, enum Interval interval);
const char* note_to_string(enum Note note);
const char* interval_to_string(enum Interval interval);
#endif
