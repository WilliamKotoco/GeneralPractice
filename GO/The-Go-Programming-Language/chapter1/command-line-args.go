package main

import (
	"fmt"
	"os"
)

func main() {
	// s and separator variables of type string
	var s, separator string

	/**
	:= is called short variable declaration, which gives a variable a type based on its initialization value.
	*/
	for i := 0; i < len(os.Args); i++ {

		s += separator + os.Args[i] // concatenates the values.
		separator = " "
	}
	fmt.Println(s)

}
