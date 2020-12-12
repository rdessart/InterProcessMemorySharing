# Inter Process Memory Sharing
This is a "test" of a way to share memory between process.
IPMS (Inter Process Memory Sharing) will work by letting a "block of memory" accessible to other process.
To identify the memory a file will be written with the following info:
* Memory block start location
* Memory block start
* A "lock" position (8 bits, will be reduced later)

Other process may interact with this block of memory when lock is off.

Probably not of general interest but if that can be helpfull to any one.

## DEVELOP BRANCH
The develop branch will contain debug code. Code in develop brach is not garanteed to work.
When code is stable enought it will be moved to master (or other branch who will contain functing code).

## LICENCE
Currently code is licenced under GPL V3.
The licence may change later.
