# CPlusPlus_Project2
 A C++ program to encrypt (or decrypt) a file using a code provided at run time.


Inputs:
The program will receive a filename and a set of letter pairs from standard input (that is, std::cin).
The filename contains a text file that you must encrypt (or decrypt) based on the letter pairs provided.
The letter pairs are the encoding to use. You should continue to load letter pairs until either std::cin has no additional input, or the letter ‘q’ is entered by itself.



Outputs

Your program should load the specified input file, convert every occurrence of the first character in each encoding pair to the second character in the pair, and output the result to standard output (std::cout).
Additionally, if an output line is identical to a previous output line, you should only output it the first time it appears.


Error Handling

Part of any good software engineering project is ensuring that a user is notified when they make a mistake. Take a moment and think about what could go wrong with the above specifications.
There are a lot of possible errors! For this project, you need to notify the user if specific errors occur, and make sure that your main() function returns a 1 (instead of a 0) to indicate the error. The return value from main is referred to as the programs "exit code". Specifically you should catch the following error conditions if they occur:
If the filename provided is not available, you should write to standard error something like:
Error: Cannot open 'filename'.
where filename is replaced by the actual filename that the input indicated should be opened.
If an encoding pair is either a single character (other than ‘q’) or more than two characters, you should give an error like:
Error: Unknown encoding 'input'.
where input is the specific illegal input provided.
Finally, if the first letter in an encoding pair duplicates that of another pair, you should given an error. For example, if both ab and ac are provided as encoding pairs, the error should be something like:
Error: The character 'a' is encoded as both 'b' and 'c'.
where the correct characters for the error are specified.
We will NOT grade you on the specific error that you output, only that you catch the error and use exit code 1.



Examples

Assume we have a file called example.txt with the contents:
This is an example test file.
If your Project02.cpp file is compiled into an executable called Proj2.exe and run with the command echo example.txt aA eE iI | ./Proj2.exe then the echo command will convert whatever follows into standard output and the pipe will send it into the standard input of Proj2.exe. Your program will read it in and know to open the file example.txt. It will then convert all instances of lowercase ‘a’ to capital 'A’, and similar for ‘e’ to ‘E’ and ‘i’ to 'I’, so your output would be:
ThIs Is An ExAmplE tEst fIlE.
For a more proper encryption, we might use something like:
echo example.txt aq bw ce dr et fy gu hi io jp ka ls md nf og ph qj rk sl tz ux vc wv xb yn zm | ./Proj2.exe`
Which would produce:
Tiol ol qf tbqdhst ztlz yost.
Most files will have multiple lines. Consider the file fox.txt which holds:
the
quick
brown
fox
jumps
over
the
lazy
dog
If we run
echo fox.txt an bo cp dq er fs gt hu iv jw kx ly mz na ob pc qd re sf tg uh vi wj xk yl zm | ./Proj2.exe > output03.txt
we will generate a file output03.txt with the contents:
gur
dhvpx
oebja
sbk
whzcf
bire
ynml
qbt
But wait, our original program had nine lines; why does this one have only eight? The word “the” appeared twice in the input, and we remove any duplicate lines.
Now, let’s try running this output through the exact same encoding.
echo output03.txt an bo cp dq er fs gt hu iv jw kx ly mz na ob pc qd re sf tg uh vi wj xk yl zm | ./Proj2.exe
And we get:
the
quick
brown
fox
jumps
over
lazy
dog
It’s almost exactly like the original, but missing the second "the". This encoding is known as rot13 – it rotates each letter 13 positions through the alphabet. If you do this twice, you are back to the original words!
Implementation
You will have a lot more flexibility in determining how to implement this program. We recommend the functions:
OpenFile to read in the filename and open the input file, reporting any errors.
ReadEncodingPairs to read in the encryption pairs and store them in an appropriate container, reporting any errors.
ApplyEncoding to transform a single line provided to it.
ProcessFile to step through the file, line-by-line, calling ApplyEncoding on each line and removing duplicates.