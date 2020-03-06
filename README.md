# No-Escape
A Game using C++ and graphics library

If you will run this code in codeblocks you will get errors like 'undefined reference to initwindow' 
to solve this error follow below steps

Firstally you have to copy some files to your codeblocks folder (this files is given above)
(1) graphics.h and winbgim.h to CodeBlocks --> MinGW --> include
(2) libbgi.a to CodeBlocks --> MinGW --> lib

Then open CodeBlocks go to settings --> complier --> Linker settings --> 
(1) in Link libraries tab add libbgi.a file
(2) in other linker options path these "-lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32" and click save
and you are ready to go with graphics library
