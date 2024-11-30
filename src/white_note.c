#include "notes_helper.h"

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_NOTE_ENUM(white_note),
static const enum Note white_note_to_note_array[] = {WHITE_NOTE_RELATIONS};
#undef X

enum Note white_note_to_note(enum White_note note) {
  return white_note_to_note_array[note];
}

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_NOTE_ENUM(white_note##_sharp),
enum Note white_note_to_sharp_array[] = {WHITE_NOTE_RELATIONS};
#undef X

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_NOTE_ENUM(white_note##_flat),
enum Note white_note_to_flat_array[] = {WHITE_NOTE_RELATIONS};
#undef X

enum Note white_note_sharp_of(enum White_note note) {
  return white_note_to_sharp_array[note];
}
enum Note white_note_flat_of(enum White_note note) {
  return white_note_to_flat_array[note];
}

#define X(raw, base, chrom) [TO_NOTE_ENUM(raw)] = TO_WHITE_NOTE_ENUM(base),
static const enum White_note note_to_white_note_array[] = {NOTE_RELATIONS};
#undef X

#define X(white_note) \
  [TO_WHITE_NOTE_ENUM(white_note)] = TO_CHROMATIC_ENUM(white_note),
static const enum Chromatic_type white_note_to_chromatic_array[] = {
    WHITE_NOTE_RELATIONS};
#undef X

enum Chromatic_type white_note_to_chromatic(enum White_note note) {
  return white_note_to_chromatic_array[note];
}

enum White_note note_to_white_note(enum Note note) {
  return note_to_white_note_array[note_base_of(note)];
}
