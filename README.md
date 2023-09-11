# cs303_assignment1

The program first intakes the name of a file, must input the name of the file without any extra characters. "data.txt" was utilized for testing of program:
![pic1](https://github.com/IsaOrtiz08/cs303_assignment1/assets/113536391/2d780a1c-cba2-4d37-b0d0-36f4aa273ec3)

After inputing the file name, the menu will appear, automatically reading the file and initializing the array before displaying the menu.
To select an option, type only the number without any extra characters. The exception to this is using lowercase 'q' to exit the program.
![pic2](https://github.com/IsaOrtiz08/cs303_assignment1/assets/113536391/04a2ca9a-38d2-4f69-9af0-7fde0217f972)

Option 1 will request user input for an integer without additional characters. If the value isn't in the array, it will return a statement saying it was not found
![pic3](https://github.com/IsaOrtiz08/cs303_assignment1/assets/113536391/f0b025d6-ff03-4958-81f1-39c59d94dd64)
If the value is found in the array, function will return the value and the index it is located in
![pic4](https://github.com/IsaOrtiz08/cs303_assignment1/assets/113536391/8111a14e-5381-4d14-866a-46e03c1e11dd)

Option 2 will request an index value. If a value larger than the size of the array is input, the function will return an error and abort
![pic5](https://github.com/IsaOrtiz08/cs303_assignment1/assets/113536391/87b4db29-7d22-4a32-bef5-28fb45cb350c)
Otherwise, the program will request an integer to modify the orignal value to. It will then output the original value and the new value.
