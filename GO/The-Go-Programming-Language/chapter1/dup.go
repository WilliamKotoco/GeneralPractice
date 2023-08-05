/*
Program to write down the duplicated lines in a text
*/
package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	count := make(map[string]int)       // creates a map mapping string to integers.
	input := bufio.NewScanner(os.Stdin) // creates a buffer for reading from the keyboard

	for input.Scan() {
		count[input.Text()]++ // increases the value of the integer associated with the input.Text string
	}

	for line, n := range count {
		// n bigger than one means the line has been written more than once.
		if n > 1 {
			fmt.Printf("%d times \t %s \n", n, line)
		}

	}

}
