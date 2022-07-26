# Auto Indexer

This repository was created and maintained by Cullen Watson.

Email: cgwatson@smu.edu

## Functionality

Generates an keyword index based off of bracketed keywords and numbered pages in a text file. The index lists the keywords alphabetically along with the page number they appeared in.

A correctly formatted input file is located in ```input/test_book.txt``` along with the resulting index file: ```output/results.txt```

## Binary Link

Download the exe [here](https://github.com/cullenwatson/auto-indexer/releases/tag/v0.1)

## How to Compile and Run (using MinGW on Windows)

[Video Demo](https://youtu.be/CTTfShIPI28)

Create a build folder in the project directory and navigate to it

Run the following command in the build folder

```cmake .. -G "MinGW Makefiles"```

Now run the make command

```mingw32-make```

And to run:

The program takes two command line args:

* input file location

* output file location

To use the default test file, type:

```auto_indexer ../input/test_book.txt ../output/index.txt```

The generated index will be located in ```output/index.txt``` within the project folder





