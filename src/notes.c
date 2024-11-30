#include "notes.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define X(e_note, base, chrom) [TO_NOTE_ENUM(e_note)] = #e_note,
static const char* const note_strings_array[] = {NOTE_RELATIONS};
#undef X

const char* note_to_string(enum Note note) { return note_strings_array[note]; }

#define X(e_note, base, chrom) [TO_NOTE_ENUM(e_note)] = TO_NOTE_ENUM(base),
static const enum Note bases[] = {NOTE_RELATIONS};
#undef X

enum Note note_base_of(enum Note note) { return bases[note]; }
