# C++ Refresher Fall 2022

This repository contains cheatsheets and problem statements used during the ULeth Computer Science Club's C++ Refresher workshop.

## Problem 1

```
 * In this problem you will be given a list of hockey teams and their
 * corresponding records. You must read the data from the given file,
 * and output the three best performing teams.
 *
 * The data is formatted in the following way:
 *
 *     City Name ShorthandName W-L-OTL
 *
 * Where W = wins, L = losses, and OTL = Overtime losses.
 *
 * A teams performance is based on the number of wins they have.
 * (We are simplifying here...) In the case of a tie, the team with
 * more OT losses will be ranked higher. In the case where wins and
 * OT losses are tied, teams should be ranked alphabetically.
 *
 * Output the full names and records of the top three performing teams
 * based on the criteria listed above.
```

All of the information you need should be contained in `cheatsheet_basic.cpp`

## Problem 2

```
 * In this problem, you must implement a vector class that functions
 * similar to the standard vector in C++.
 *
 * The vector must support the following operations:
 *
 *   - '[]' operator
 *   - push_back()
 *   - size()
 *
 * Your vector should use dynamically allocated memory, as you cannot
 * know how many elements will be inserted into the vector at any given
 * time. You should also try to avoid just creating a large array at
 * the beginning of execution. Try to only resize it when more space
 * is actually needed.
 *
 * A template class with all of the required functions has been
 * provided. Just fill them all in :)
 *
 * You may need to create extra private variables or functions. That
 * is completely fine.
 *
 * When compiled, the main function will test the functionality of your
 * vector. You should see the following output:
 *
 * 0
 * 100
 * 0 1 2 3 4 5 6 7 8 9 ... 98 99
```

Information relating to this problem can be found in `cheatsheet_advanced.cpp`
