/*
perror sounds like it uses a constant because the error message that it
is recieving needs to never change for clarity, as it sounds like that
is what would go into a file for error logging. strerror is an actual 
map function it sounds, meaning it would get any number for the input,
dynamic or not, and map it to a string that would provide the full error
message. 
*/