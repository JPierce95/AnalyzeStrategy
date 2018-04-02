# Analyze Strategy

Author: Joshua E. Pierce

## Grading Checklist:

* [25 out of 25] Appropriate use of arrays *or* vectors and demonstrates mastery of the programming concept
* [20 out of 25] Appropriate use of file input and demonstrates mastery of the programming concept
* [15 out of 20] Appropriate use of programming fundamentals including iteration, control flow, operations and variables
* [20 out of 20] The program operates precisely as described in the instructions
* [7 out of 10] The code is easy to read with proper spacing, indentation, and other style conventions discussed in class


## Notes:
    I have split up all of the different ways of guesses doors into their own methods. This way it
        can be called on command without having to copy and paste it over and over again, and makes
        the for loop much easier to read.
    I have also done a bit of codeing wizardry to determine how many attempts it would take to get
        10 door guesses correct in a row with either the blind, or change method. In fact I do this
        100 times for each of them and find the average number of attempts it took. With that number
        I then write it to a file for later use.
    After dertermining the average for this one session and logging it to a file, I then read all of
        the values out of the file and determine th average of all the values in the file. By doing
        this I get the average of as many times as the program has been ran.
    In the process of all this file writing I have to convert a string to a cString, and an integer
        to a string, and then a string back into an integer. I'm almost positive that I did each of
        of these in the least efficient way possible, but were done nonetheless.
    My code does get a bit tedious to read, I have tried to comment out all the harder spots, but it
        doesn't work out to well for the eyes.
    There's several spots where I'm certain that I could use loops better, but I feel it's not terrible.
    On the bright side, the program does exactly what it's supposed to do.
