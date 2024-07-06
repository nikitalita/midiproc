#ifndef __RANGE_H__
#define __RANGE_H__

/** $VER: Range.h (2023.11.01) P. Stuer **/
#pragma once

#include <stdint.h>

/// <summary>
/// Represents a range.
/// </summary>
class Range
{
public:
    Range(void) noexcept { Clear(); }

    Range(const Range &) = delete;
    Range(Range && other) noexcept { Set(other._Begin, other._End); }
    Range & operator=(const Range &) = delete;
    Range & operator=(Range && other) noexcept { Set(other._Begin, other._End); return *this; }

    virtual ~Range(void) noexcept { }

    uint32_t Begin(void) const noexcept { return _Begin; }
    uint32_t End(void) const noexcept { return _End; }

    void SetBegin(uint32_t begin) noexcept { _Begin = begin; }
    void SetEnd(uint32_t end) noexcept { _End = end; }
    void Set(uint32_t begin, uint32_t end) noexcept { _Begin = begin; _End = end; }

    void Clear(void) noexcept { Set(~0u, ~0u); }

    uint32_t Size(void) const noexcept { return _End - _Begin; }

    bool HasBegin(void) const noexcept { return _Begin != ~0u; }
    bool HasEnd(void) const noexcept { return _End != ~0u; }

    bool IsSet(void) const noexcept { return  HasBegin() && HasEnd(); }
    bool IsEmpty(void) const noexcept { return !IsSet(); }

private:
    uint32_t _Begin;
    uint32_t _End;
};

#endif /* __RANGE_H__ */
