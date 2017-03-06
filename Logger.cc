/* Copyright (c) 2015-2017 Stanford University
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR(S) DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL AUTHORS BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include "Logger.h"

namespace CoreArbiter {

LogLevel Logger::displayMinLevel = NOTICE;
std::mutex Logger::mutex;

void Logger::log(LogLevel level, const char* fmt, ...)
{
    if (level < displayMinLevel) {
        return;
    }

    Lock lock(mutex);
    va_list args;
    va_start(args, fmt);
    if (level == ERROR) {
        vfprintf(stderr, fmt, args);
    } else {
        vprintf(fmt, args);
    }
    va_end(args);
}

}