
#ifndef ISC_TIME_H
#define ISC_TIME_H 1

#include <sys/time.h>
#include <time.h>

#include <isc/result.h>
#include <isc/boolean.h>

/***
 *** Intervals
 ***/

/*
 * The contents of this structure are private, and MUST NOT be accessed
 * directly by callers.
 *
 * The contents are exposed only so that callers may avoid dynamic allocation
 * and instead just declare a 'struct isc_interval'.
 */
typedef struct isc_interval {
	unsigned int seconds;
	unsigned int nanoseconds;
} *isc_interval_t;

void
isc_interval_set(isc_interval_t i,
		 unsigned int seconds, unsigned int nanoseconds);
/*
 * Set 'i' to a value representing an interval of 'seconds' seconds and
 * 'nanoseconds' nanoseconds, suitable for use in isc_time_add() and
 * isc_time_subtract().
 *
 * Requires:
 *
 *	't' is a valid.
 *
 *	nanoseconds < 1000000000
 */

isc_boolean_t
isc_interval_iszero(isc_interval_t i);
/*
 * Returns ISC_TRUE iff. 'i' is the zero interval.
 *
 * Requires:
 *
 *	't' is a valid.
 *
 */

/***
 *** Absolute Times
 ***/

/*
 * The contents of this structure are private, and MUST NOT be accessed
 * directly by callers.
 *
 * The contents are exposed only so that callers may avoid dynamic allocation
 * and instead just declare a 'struct isc_time'.
 */

typedef struct isc_time {
	time_t		seconds;
	unsigned int	nanoseconds;
} *isc_time_t;

void
isc_time_settoepoch(isc_time_t t);
/*
 * Set 't' to the time of the epoch.
 *
 * Requires:
 *
 *	't' is a valid.
 *
 */

isc_boolean_t
isc_time_isepoch(isc_time_t t);
/*
 * Returns ISC_TRUE iff. 't' is the epoch ("time zero").
 *
 * Requires:
 *
 *	't' is a valid.
 *
 */

isc_result_t
isc_time_get(isc_time_t t);
/*
 * Set 't' to the current absolute time.
 *
 * Requires:
 *
 *	't' is a valid pointer.
 *
 * Returns:
 *
 *	Success
 *	Unexpected error
 */

int
isc_time_compare(isc_time_t t1, isc_time_t t2);
/*
 * Compare the times referenced by 't1' and 't2'
 *
 * Requires:
 *
 *	't1' and 't2' are a valid.
 *
 * Returns:
 *
 *	-1		t1 < t2		(comparing times, not pointers)
 *	0		t1 = t2
 *	1		t1 > t2
 */

void
isc_time_add(isc_time_t t, isc_interval_t i, isc_time_t result);
/*
 * Add 'i' to 't', storing the result in 'result'.
 *
 * Requires:
 *
 *	't', 'i', and 'result' are valid.
 */

void
isc_time_subtract(isc_time_t t, isc_interval_t t2, isc_time_t result);
/*
 * Subtract 'i' from 't', storing the result in 'result'.
 *
 * Requires:
 *
 *	't', 'i', and 'result' are valid.
 *
 *	t >= epoch + i			(comparing times, not pointers)
 */

/***
 *** UNIX-only
 ***/

void
isc_time_fromtimeval(isc_time_t t, struct timeval *tv);
/*
 * Set 't' to the time given by 'ts'.
 *
 * Requires:
 *
 *	't' and 'tv' are a valid.
 *
 */

void
isc_time_totimeval(isc_time_t t, struct timeval *tv);
/*
 * Convert 't' to a UNIX timeval.
 *
 * Requires:
 *
 *	't' and 'tv' are a valid.
 *
 */

void
isc_time_fromtimespec(isc_time_t t, struct timespec *ts);
/*
 * Set 't' to the time given by 'ts'.
 *
 * Requires:
 *
 *	't' and 'ts' are a valid.
 *
 */

void
isc_time_totimespec(isc_time_t t, struct timespec *ts);
/*
 * Convert 't' to a UNIX timespec.
 *
 * Requires:
 *
 *	't' and 'ts' are a valid.
 *
 */

#endif /* ISC_TIME_H */
