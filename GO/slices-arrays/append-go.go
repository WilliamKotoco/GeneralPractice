package main

import "fmt"

func myAppend(slice []int, value int) []int {
	length := len(slice) + 1
  var new_slice []int
	/// there are free spaces, not necessary the reallocation
	if length <= cap(slice) {

		new_slice = slice[:length] // increase the slice
    
	} else {
		/// there are no free spaces, it will be necessary to reallocate the array
		capacity := 2 * len(slice)

    new_slice = make([]int, length, capacity)
	}
  copy(new_slice, slice) /// copies the elements from the previous slice in this new one
	new_slice[len(slice)] = value
	return new_slice
 }

func main() {
	test := []int{1, 2, 3}
	fmt.Printf("len  = %d, cap = %d \n", len(test), cap(test))
	fmt.Print(test)
	test = myAppend(test, 4)
	fmt.Printf("\n len  = %d, cap = %d \n", len(test), cap(test))
	fmt.Print(test)

}
