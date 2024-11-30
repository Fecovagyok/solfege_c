#include "interval.h"

#include <stdint.h>

#include "notes_helper.h"

#define X(name, full_step, half_step) [name] = full_step,
static const uint32_t interval_full_steps[] = {INTERVAL_RELATIONS};
#undef X

#define X(name, full_step, half_step) [name] = half_step,
static const uint32_t interval_half_steps[] = {INTERVAL_RELATIONS};
#undef X

#define X(name, full_step, half_step) [name] = #name,
static const char* const interval_string_array[] = {INTERVAL_RELATIONS};
#undef X

const char* interval_to_string(enum Interval interval) {
  return interval_string_array[interval];
}

enum White_note white_note_for_full_step_of(enum Note base,
                                            enum Interval interval) {
  enum White_note non_accidental = note_to_white_note(base);
  return (non_accidental + interval_full_steps[interval]) % 8;
}

enum Note note_interval(enum Note base, enum Interval interval) {
  enum White_note new_base = white_note_for_full_step_of(base, interval);
  uint32_t distance = chromatic_calc_distance(
      note_to_chromatic(base), white_note_to_chromatic(new_base));
  if (distance == interval_half_steps[interval])
    return white_note_to_note(new_base);
  if (distance < interval_half_steps[interval])
    return white_note_sharp_of(new_base);
  else
    return white_note_flat_of(new_base);
}
