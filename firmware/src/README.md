# Lasersaur-RAMPS

This is an **experimental** fork of [LasaurApp](http://www.lasersaur.com) that
modifies the firmware file to allow it to work with a
[RAMPS](http://reprap.org/wiki/RAMPS_1.4) style driver board.

## DISCLAIMER

This is a highly experimental fork.  In fact, it would be fair to consider it
entirely untested, as I don't currently own a laser cutter.  Any liability for
running dangerous lasers with untested firmware is your own, and this software
comes with no guarantees whatsoever. All information is provided as-is and
without claims to mechanical or electrical fitness, safety, or usefulness. You
are fully responsible for doing your own evaluations and making sure your system
does not burn, blind, or electrocute people.

## Who is this for?

Mike.  Although, if you, like Mike, have a custom laser table with hardware that
does not play nice with lasersaur - such as a RAMPS board and an ATMega2560, you
might want to take a look as well.

## Details

Only the firmware has been modified in this fork.  Lasersaur's firmware is based
on a firmware called [grbl](http://github.com/grbl/grbl), though the two have
diverged quite a bit since lasersaur first forked. several years ago.  One thing
both firmwares still shared, however, was an assumption that certain pins - such
as the stepping pins, sense pins, and direction pins, were grouped together on a
port by type.  That is, all the stepping pins were together in the same 8-bit
address.  RAMPS boards, however, have pins more spread out in order to minimize
the impact to specialty pins such as PWM pins that might have other uses.  This
means they are not grouped together neatly.  So I modified the lasersaur code to
use more generic pin definitions, and to work with individual pins rather than
blocking them together in ports.  This has the added benefit of removing some
odd interlocking dependencies between board versions and sensors, so you are now
free to mix-and-match features, like z-axis (which lasersaur's firmware has
settings for but no home support for some reason), door sensors, etc.

## How do I use this?

It compiles with avr-gcc.  If you've got the technical know-how to evaluate if
this firmware is for you, you should be able to take it from there.

## See also

[grbl](http://github.com/grbl/grbl)

[lasersaur](http://www.lasersaur.com)

[RAMPS](http://reprap.org/wiki/RAMPS_1.4)
