/*
Calendar time is the number of seconds since 1/1/1970. If it is 
stored as a 32 bit signed integer, that is 4294967295÷60÷60÷24÷365.25÷2
which is 68.049650401. 68 + 1970 = 2038. This may get postponed by using
a 32 bit unsigned integer, as that would double the time allowed to 136,
giving us until 2106. This might not be compatable with older methods, 
and might cause tons of issues We could possibly change the value to a float,
which may introduce many more issues with the gradual loss of precision,
and would probably not be worth the hassle. You could also convert fully to a 
64 bit number, which would postpone the issue for long enough to be 
not really all that worried about that overflowing in a lifetime. That would
also possibly cause some issues for in-place systems, as they might not
have the memory allocated for the additional bits. 
*/