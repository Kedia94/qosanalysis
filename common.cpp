#include "common.h"

bool sort_quality(const struct task &i, const struct task &j)
{
    return i.quality < j.quality;
}

bool sort_execute(const struct task &i, const struct task &j)
{
    return i.execute/i.period < j.execute/j.period;
}
