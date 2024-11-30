#ifndef INTERVAL_H_INCLUDED
#define INTERVAL_H_INCLUDED

#include "notes.h"

/* This header contains the declaration of the enum representing an interval
 * between solfege notes*/

#define INTERVAL_RELATIONS  \
  X(Perfect_Unison, 0, 0)   \
  X(Augmented_Unison, 0, 1) \
  X(Minor_Second, 1, 1)     \
  X(Major_Second, 1, 2)     \
  X(Minor_Third, 2, 3)      \
  X(Major_Third, 2, 4)      \
  X(Perfect_Fourth, 3, 5)   \
  X(Perfect_Fifth, 4, 7)

/* To be continued later if needed */

#define X(name, wannabe, steps) name,
enum Interval { INTERVAL_RELATIONS };
#undef X

enum Note note_interval(enum Note base, enum Interval interval);
const char* interval_to_string(enum Interval interval);

#endif
